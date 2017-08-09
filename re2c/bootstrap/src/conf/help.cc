extern const char *help;
const char *help =
"\n"
"       -? -h --help\n"
"              Show a short help screen:\n"
"\n"
"       -b --bit-vectors\n"
"              Implies  -s.  Use bit vectors as well to try to coax better code\n"
"              out of the compiler. Most useful for  specifications  with  more\n"
"              than a few keywords (e.g., for most programming languages).\n"
"\n"
"       -c --conditions\n"
"              Used for (f)lex-like condition support.\n"
"\n"
"       -d --debug-output\n"
"              Creates  a parser that dumps information about the current posi‐\n"
"              tion and the state the parser is in.  This is useful for  debug‐\n"
"              ging  parser issues and states. If you use this switch, you need\n"
"              to define a YYDEBUG macro, which will be called like a  function\n"
"              with  two  parameters:  void  YYDEBUG (int state, char current).\n"
"              The first parameter receives the state  or  -1  and  the  second\n"
"              parameter receives the input at the current cursor.\n"
"\n"
"       -D --emit-dot\n"
"              Emit  Graphviz  dot data, which can then be processed with e.g.,\n"
"              dot -Tpng input.dot > output.png. Please note that scanners with\n"
"              many states may crash dot.\n"
"\n"
"       -e --ecb\n"
"              Generate  a  parser that supports EBCDIC. The generated code can\n"
"              deal with any character up to 0xFF. In this mode,  re2c  assumes\n"
"              an  input  character size of 1 byte. This switch is incompatible\n"
"              with -w, -x, -u, and -8.\n"
"\n"
"       -f --storable-state\n"
"              Generate a scanner with support for storable state.\n"
"\n"
"       -F --flex-syntax\n"
"              Partial support for flex syntax. When this flag is active, named\n"
"              definitions  must  be  surrounded  by  curly  braces  and can be\n"
"              defined without an equal sign  and  the  terminating  semicolon.\n"
"              Instead, names are treated as direct double quoted strings.\n"
"\n"
"       -g --computed-gotos\n"
"              Generate  a  scanner  that utilizes GCC's computed-goto feature.\n"
"              That is, re2c generates jump tables whenever a  decision  is  of\n"
"              certain complexity (e.g., a lot of if conditions would be other‐\n"
"              wise necessary). This is only usable with compilers that support\n"
"              this feature.  Note that this implies -b and that the complexity\n"
"              threshold can be configured using  the  cgoto:threshold  inplace\n"
"              configuration.\n"
"\n"
"       -i --no-debug-info\n"
"              Do  not  output  #line information. This is useful when you want\n"
"              use a CMS tool with re2c's output. You might want to do this  if\n"
"              you  do  not want to impose re2c as a build requirement for your\n"
"              source.\n"
"\n"
"       -o OUTPUT --output=OUTPUT\n"
"              Specify the OUTPUT file.\n"
"\n"
"       -r --reusable\n"
"              Allows reuse of scanner definitions with  /*!use:re2c  */  after\n"
"              /*!rules:re2c */.  In this mode, no /*!re2c */ block and exactly\n"
"              one /*!rules:re2c */ must be present.  The rules are  saved  and\n"
"              used  by  every /*!use:re2c */ block that follows.  These blocks\n"
"              can contain  inplace  configurations,  especially  re2c:flags:e,\n"
"              re2c:flags:w,   re2c:flags:x,  re2c:flags:u,  and  re2c:flags:8.\n"
"              That way it is possible to  create  the  same  scanner  multiple\n"
"              times for different character types, different input mechanisms,\n"
"              or different output mechanisms.  The /*!use:re2c */  blocks  can\n"
"              also  contain  additional rules that will be appended to the set\n"
"              of rules in /*!rules:re2c */.\n"
"\n"
"       -s --nested-ifs\n"
"              Generate nested ifs for some switches. Many compilers need  this\n"
"              assist to generate better code.\n"
"\n"
"       -t HEADER --type-header=HEADER\n"
"              Create  a  HEADER  file  that contains types for the (f)lex-like\n"
"              condition support. This can only be activated when -c is in use.\n"
"\n"
"       -T --tags\n"
"              Enable submatch extraction with tags.  This option is implied by\n"
"              --posix-captures.\n"
"\n"
"       -P --posix-captures\n"
"              Enable  submatch  extraction  with POSIX-style capturing groups.\n"
"              This option implies -T --tags.\n"
"\n"
"       -u --unicode\n"
"              Generate a parser that supports UTF-32. The generated  code  can\n"
"              deal  with  any  valid Unicode character up to 0x10FFFF. In this\n"
"              mode, re2c assumes an input character  size  of  4  bytes.  This\n"
"              switch is incompatible with -e, -w, -x, and -8. This implies -s.\n"
"\n"
"       -v --version\n"
"              Show version information.\n"
"\n"
"       -V --vernum\n"
"              Show  the  version  as  a  number  in the MMmmpp (Majorm, minor,\n"
"              patch) format.\n"
"\n"
"       -w --wide-chars\n"
"              Generate a parser that supports UCS-2. The  generated  code  can\n"
"              deal  with  any  valid  Unicode character up to 0xFFFF.  In this\n"
"              mode, re2c assumes an input character  size  of  2  bytes.  This\n"
"              switch is incompatible with -e, -x, -u, and -8. This implies -s.\n"
"\n"
"       -x --utf-16\n"
"              Generate  a  parser that supports UTF-16. The generated code can\n"
"              deal with any valid Unicode character up to  0x10FFFF.  In  this\n"
"              mode,  re2c  assumes  an  input  character size of 2 bytes. This\n"
"              switch is incompatible with -e, -w, -u, and -8. This implies -s.\n"
"\n"
"       -8 --utf-8\n"
"              Generate a parser that supports UTF-8. The  generated  code  can\n"
"              deal  with  any  valid Unicode character up to 0x10FFFF. In this\n"
"              mode, re2c assumes an input  character  size  of  1  byte.  This\n"
"              switch is incompatible with -e, -w, -x, and -u.\n"
"\n"
"       --case-insensitive\n"
"              Makes  all strings case insensitive. This makes \"-quoted expres‐\n"
"              sions behave as '-quoted expressions.\n"
"\n"
"       --case-inverted\n"
"              Invert the meaning of single and  double  quoted  strings.  With\n"
"              this  switch, single quotes are case sensitive and double quotes\n"
"              are case insensitive.\n"
"\n"
"       --no-generation-date\n"
"              Suppress date output in the generated file.\n"
"\n"
"       --no-optimize-tags\n"
"              Suppress tag optimization (mostly used for debugging).\n"
"\n"
"       --no-version\n"
"              Suppress version output in the generated file.\n"
"\n"
"       --no-generation-date\n"
"              Suppress version output in the generated file.\n"
"\n"
"       --encoding-policy POLICY\n"
"              Specify how re2c must treat Unicode surrogates.  POLICY  can  be\n"
"              one of the following: fail (abort with an error when a surrogate\n"
"              is encountered), substitute (silently  replace  surrogates  with\n"
"              the error code point 0xFFFD), ignore (treat surrogates as normal\n"
"              code points). By default, re2c ignores surrogates (for  backward\n"
"              compatibility). The Unicode standard says that standalone surro‐\n"
"              gates are invalid code points, but different libraries and  pro‐\n"
"              grams treat them differently.\n"
"\n"
"       --input INPUT\n"
"              Specify re2c's input API. INPUT can be either default or custom.\n"
"\n"
"       -S --skeleton\n"
"              Instead of embedding re2c-generated code into C/C++ source, gen‐\n"
"              erate a self-contained program for the same DFA. Most useful for\n"
"              correctness and performance testing.\n"
"\n"
"       --empty-class POLICY\n"
"              What to do if the user uses an empty character class. POLICY can\n"
"              be one of the following: match-empty (match empty input:  pretty\n"
"              illogical,  but  this is the default for backwards compatibility\n"
"              reasons), match-none (fail to match on any input), error (compi‐\n"
"              lation  error). Note that there are various ways to construct an\n"
"              empty class, e.g., [], [^\\x00-\\xFF], [\\x00-\\xFF][\\x00-\\xFF].\n"
"\n"
"       --dfa-minimization <table | moore>\n"
"              The  internal  algorithm  used  by  re2c  to  minimize  the  DFA\n"
"              (defaults  to  moore).  Both the table filling algorithm and the\n"
"              Moore algorithm should produce the same DFA (up to states  rela‐\n"
"              beling).   The  table  filling  algorithm  is  much  simpler and\n"
"              slower; it serves as a reference implementation.\n"
"\n"
"       --eager-skip\n"
"              This option controls when the generated lexer  advances  to  the\n"
"              next  input  symbol  (that  is,  increments  YYCURSOR or invokes\n"
"              YYSKIP).  By default this happens after transition to  the  next\n"
"              state, but --eager-skip option allows to override default behav‐\n"
"              ior and advance input position immediately after  reading  input\n"
"              symbol.  This option is implied by --no-lookahead.\n"
"\n"
"       --dump-nfa\n"
"              Generate .dot representation of NFA and dump it on stderr.\n"
"\n"
"       --dump-dfa-raw\n"
"              Generate  .dot representation of DFA under construction and dump\n"
"              it on stderr.\n"
"\n"
"       --dump-dfa-det\n"
"              Generate .dot representation of  DFA  immediately  after  deter‐\n"
"              minization and dump it on stderr.\n"
"\n"
"       --dump-dfa-tagopt\n"
"              Generate  .dot representation of DFA after tag optimizations and\n"
"              dump it on stderr.\n"
"\n"
"       --dump-dfa-min\n"
"              Generate .dot representation of DFA after minimization and  dump\n"
"              it on stderr.\n"
"\n"
"       --dump-adfa\n"
"              Generate  .dot representation of DFA after tunneling and dump it\n"
"              on stderr.\n"
"\n"
"       -1 --single-pass\n"
"              Deprecated. Does nothing (single pass is the default now).\n"
"\n"
"       -W     Turn on all warnings.\n"
"\n"
"       -Werror\n"
"              Turn warnings into errors. Note that this option  alone  doesn't\n"
"              turn  on  any warnings; it only affects those warnings that have\n"
"              been turned on so far or will be turned on later.\n"
"\n"
"       -W<warning>\n"
"              Turn on a warning.\n"
"\n"
"       -Wno-<warning>\n"
"              Turn off a warning.\n"
"\n"
"       -Werror-<warning>\n"
"              Turn on a warning  and  treat  it  as  an  error  (this  implies\n"
"              -W<warning>).\n"
"\n"
"       -Wno-error-<warning>\n"
"              Don't  treat  this  particular warning as an error. This doesn't\n"
"              turn off the warning itself.\n"
"\n"
"       -Wcondition-order\n"
"              Warn if the generated program makes implicit  assumptions  about\n"
"              condition numbering. You should use either the -t, --type-header\n"
"              option or the /*!types:re2c*/ directive to generate a mapping of\n"
"              condition names to numbers and then use the autogenerated condi‐\n"
"              tion names.\n"
"\n"
"       -Wempty-character-class\n"
"              Warn if a regular expression contains an empty character  class.\n"
"              Rationally,  trying  to  match an empty character class makes no\n"
"              sense: it should always fail. However, for backwards compatibil‐\n"
"              ity reasons, re2c allows empty character classes and treats them\n"
"              as empty strings. Use the --empty-class  option  to  change  the\n"
"              default behavior.\n"
"\n"
"       -Wmatch-empty-string\n"
"              Warn  if  a regular expression in a rule is nullable (matches an\n"
"              empty string). If the DFA runs in a loop and an empty  match  is\n"
"              unintentional (the input position in not advanced manually), the\n"
"              lexer may get stuck in an infinite loop.\n"
"\n"
"       -Wswapped-range\n"
"              Warn if the lower bound of a range is  greater  than  its  upper\n"
"              bound.  The  default  behavior  is  to  silently  swap the range\n"
"              bounds.\n"
"\n"
"       -Wundefined-control-flow\n"
"              Warn if some input strings cause undefined control flow  in  the\n"
"              lexer  (the faulty patterns are reported). This is the most dan‐\n"
"              gerous and most common mistake. It can be easily fixed by adding\n"
"              the default rule (*) (this rule has the lowest priority, matches\n"
"              any code unit, and consumes exactly one code unit).\n"
"\n"
"       -Wunreachable-rules\n"
"              Warn about rules that are shadowed by other rules and will never\n"
"              match.\n"
"\n"
"       -Wuseless-escape\n"
"              Warn  if  a symbol is escaped when it shouldn't be.  By default,\n"
"              re2c silently ignores such escapes, but this may as  well  indi‐\n"
"              cate a typo or error in the escape sequence.\n"
"\n"
;
