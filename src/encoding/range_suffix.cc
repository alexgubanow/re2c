#include "src/encoding/range_suffix.h"
#include "src/regexp/re.h"
#include "src/util/range.h"


namespace re2c {

static RE *emit(RESpec &spec, RangeSuffix *p, RE *re);

free_list<RangeSuffix *> RangeSuffix::freeList;

RE *to_regexp(RESpec &spec, RangeSuffix *p)
{
    return p ? emit(spec, p, nullptr) : re_sym(spec, nullptr);
}

/*
 * Build regexp from suffix tree.
 */
RE *emit(RESpec &spec, RangeSuffix *p, RE *re)
{
    if (p == nullptr) return re;

    RangeMgr &rm = spec.rangemgr;
    RE *regexp = nullptr;
    for (; p != nullptr; p = p->next) {
        RE *re1 = re_cat(spec, re_sym(spec, rm.ran(p->l, p->h + 1)), re);
        regexp = re_alt(spec, regexp, emit(spec, p->child, re1));
    }
    return regexp;
}

} // namespace re2c
