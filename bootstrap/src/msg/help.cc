extern const char *help;
const char *help =
"USAGE\n"
"       re2c  [OPTION...] INPUT [-o OUTPUT]\n"
"\n"
"       re2go [OPTION...] INPUT [-o OUTPUT]\n"
"\n"
"OPTIONS\n"
"       -? -h --help\n"
"              Show help message.\n"
"\n"
"       -1 --single-pass\n"
"              Deprecated. Does nothing (single pass is the default now).\n"
"\n"
"       -8 --utf-8\n"
"              Generate  a  lexer that reads input in UTF-8 encoding.  re2c as‐\n"
"              sumes that character range is 0 -- 0x10FFFF and  character  size\n"
"              is 1 byte.\n"
"\n"
"       -b --bit-vectors\n"
"              Optimize conditional jumps using bit masks. Implies -s.\n"
"\n"
"       -c --conditions --start-conditions\n"
"              Enable  support of Flex-like \"conditions\": multiple interrelated\n"
"              lexers within one block. Option --start-conditions is  a  legacy\n"
"              alias; use --conditions instead.\n"
"\n"
"       --case-insensitive\n"
"              Treat  single-quoted  and double-quoted strings as case-insensi‐\n"
"              tive.\n"
"\n"
"       --case-inverted\n"
"              Invert the meaning of single-quoted and  double-quoted  strings:\n"
"              treat  single-quoted strings as case-sensitive and double-quoted\n"
"              strings as case-insensitive.\n"
"\n"
"       --case-ranges\n"
"              Collapse consecutive cases in a switch statements into  a  range\n"
"              of  the  form case low ... high:. This syntax is an extension of\n"
"              the C/C++ language, supported by compilers like GCC,  Clang  and\n"
"              Tcc.  The main advantage over using single cases is smaller gen‐\n"
"              erated C code and faster generation time, although for some com‐\n"
"              pilers  like  Tcc  it also results in smaller binary size.  This\n"
"              option doesn't work for the Go backend.\n"
"\n"
"       --depfile FILE\n"
"              Write dependency information to FILE in the form of  a  Makefile\n"
"              rule  <output-file>  : <input-file> [include-file ...]. This al‐\n"
"              lows to track build  dependencies  in  the  presence  of  /*!in‐\n"
"              clude:re2c*/ directives, so that updating include files triggers\n"
"              regeneration of the output file.  This option requires  that  -o\n"
"              --output option is specified.\n"
"\n"
"       -e --ecb\n"
"              Generate a lexer that reads input in EBCDIC encoding.  re2c  as‐\n"
"              sumes  that  character range is 0 -- 0xFF an character size is 1\n"
"              byte.\n"
"\n"
"       --empty-class <match-empty | match-none | error>\n"
"              Define  the  way  re2c  treats  empty  character  classes.  With\n"
"              match-empty (the default) empty class matches empty input (which\n"
"              is  illogical,  but  backwards-compatible).   With``match-none``\n"
"              empty  class  always  fails  to  match.   With error empty class\n"
"              raises a compilation error.\n"
"\n"
"       --encoding-policy <fail | substitute | ignore>\n"
"              Define the way re2c treats Unicode surrogates.  With  fail  re2c\n"
"              aborts with an error when a surrogate is encountered.  With sub‐\n"
"              stitute re2c silently replaces surrogates with  the  error  code\n"
"              point  0xFFFD.  With ignore (the default) re2c treats surrogates\n"
"              as normal code points. The Unicode standard says that standalone\n"
"              surrogates  are  invalid,  but real-world libraries and programs\n"
"              behave in different ways.\n"
"\n"
"       -f --storable-state\n"
"              Generate a lexer which can store its inner state.  This is  use‐\n"
"              ful  in  push-model lexers which are stopped by an outer program\n"
"              when there is not enough input, and then resumed when more input\n"
"              becomes available. In this mode users should additionally define\n"
"              YYGETSTATE() and YYSETSTATE(state) macros  and  variables  yych,\n"
"              yyaccept and state as part of the lexer state.\n"
"\n"
"       -F --flex-syntax\n"
"              Partial  support for Flex syntax: in this mode named definitions\n"
"              don't need the equal sign and  the  terminating  semicolon,  and\n"
"              when used they must be surrounded by curly braces. Names without\n"
"              curly braces are treated as double-quoted strings.\n"
"\n"
"       -g --computed-gotos\n"
"              Optimize conditional jumps using  non-standard  \"computed  goto\"\n"
"              extension (which must be supported by the compiler). re2c gener‐\n"
"              ates jump tables only in complex cases with a lot of conditional\n"
"              branches.   Complexity   threshold   can   be   configured  with\n"
"              cgoto:threshold configuration. This option implies -b. This  op‐\n"
"              tion doesn't work for the Go backend.\n"
"\n"
"       -I PATH\n"
"              Add  PATH to the list of locations which are used when searching\n"
"              for include files. This option is  useful  in  combination  with\n"
"              /*!include:re2c ... */ directive. Re2c looks for FILE in the di‐\n"
"              rectory of including file and in the list of include paths spec‐\n"
"              ified by -I option.\n"
"\n"
"       -i --no-debug-info\n"
"              Do  not output #line information. This is useful when the gener‐\n"
"              ated code is tracked by some version control system or IDE.\n"
"\n"
"       --input <default | custom>\n"
"              Specify the API used by the generated  code  to  interface  with\n"
"              used-defined  code. Option default is the C API based on pointer\n"
"              arithmetic (it is the default for the C backend). Option  custom\n"
"              is the generic API (it is the default for the Go backend).\n"
"\n"
"       --input-encoding <ascii | utf8>\n"
"              Specify  the  way  re2c  parses regular expressions.  With ascii\n"
"              (the default) re2c handles input as ASCII-encoded: any  sequence\n"
"              of  code  units  is  a sequence of standalone 1-byte characters.\n"
"              With utf8 re2c handles  input  as  UTF8-encoded  and  recognizes\n"
"              multibyte characters.\n"
"\n"
"       --lang <c | go>\n"
"              Specify  the  output  language. Supported languages are C and Go\n"
"              (the default is C).\n"
"\n"
"       --location-format <gnu | msvc>\n"
"              Specify location format in messages.   With  gnu  locations  are\n"
"              printed as 'filename:line:column: ...'.  With msvc locations are\n"
"              printed as 'filename(line,column) ...'.  Default is gnu.\n"
"\n"
"       --no-generation-date\n"
"              Suppress date output in the generated file.\n"
"\n"
"       --no-version\n"
"              Suppress version output in the generated file.\n"
"\n"
"       -o OUTPUT --output=OUTPUT\n"
"              Specify the OUTPUT file.\n"
"\n"
"       -P --posix-captures\n"
"              Enable submatch extraction with POSIX-style capturing groups.\n"
"\n"
"       -r --reusable\n"
"              Allows reuse of re2c rules with /*!rules:re2c */ and /*!use:re2c\n"
"              */  blocks.  Exactly  one rules-block must be present. The rules\n"
"              are saved and used by every use-block that  follows,  which  may\n"
"              add its own rules and configurations.\n"
"\n"
"       -S --skeleton\n"
"              Ignore user-defined interface code and generate a self-contained\n"
"              \"skeleton\" program.  Additionally,  generate  input  files  with\n"
"              strings  derived  from  the regular grammar and compressed match\n"
"              results that are used to verify \"skeleton\" behavior on  all  in‐\n"
"              puts.  This  option  is useful for finding bugs in optimizations\n"
"              and code generation. This option doesn't work for the  Go  back‐\n"
"              end.\n"
"\n"
"       -s --nested-ifs\n"
"              Use  nested if statements instead of switch statements in condi‐\n"
"              tional jumps. This usually results in more efficient  code  with\n"
"              non-optimizing compilers.\n"
"\n"
"       -T --tags\n"
"              Enable submatch extraction with tags.\n"
"\n"
"       -t HEADER --type-header=HEADER\n"
"              Generate  a HEADER file that contains enum with condition names.\n"
"              Requires -c option.\n"
"\n"
"       -u --unicode\n"
"              Generate a lexer that reads UTF32-encoded  input.  Re2c  assumes\n"
"              that  character  range  is 0 -- 0x10FFFF and character size is 4\n"
"              bytes. This option implies -s.\n"
"\n"
"       -V --vernum\n"
"              Show version information in MMmmpp format (major, minor, patch).\n"
"\n"
"       --verbose\n"
"              Output a short message in case of success.\n"
"\n"
"       -v --version\n"
"              Show version information.\n"
"\n"
"       -w --wide-chars\n"
"              Generate a lexer that reads  UCS2-encoded  input.  Re2c  assumes\n"
"              that  character  range  is  0  -- 0xFFFF and character size is 2\n"
"              bytes. This option implies -s.\n"
"\n"
"       -x --utf-16\n"
"              Generate a lexer that reads UTF16-encoded  input.  Re2c  assumes\n"
"              that  character  range  is 0 -- 0x10FFFF and character size is 2\n"
"              bytes. This option implies -s.\n"
"\n"
"       -D --emit-dot\n"
"              Instead of normal output generate lexer graph  in  .dot  format.\n"
"              The  output  can  be  converted  to  an  image  with the help of\n"
"              Graphviz (e.g. something like dot -Tpng -odfa.png dfa.dot).\n"
"\n"
"       -d --debug-output\n"
"              Emit YYDEBUG in the generated code.  YYDEBUG should  be  defined\n"
"              by  the user in the form of a void function with two parameters:\n"
"              state (lexer state or -1) and symbol (current  input  symbol  of\n"
"              type YYCTYPE).\n"
"\n"
"       --dump-adfa\n"
"              Debug option: output DFA after tunneling (in .dot format).\n"
"\n"
"       --dump-cfg\n"
"              Debug  option:  output  control  flow graph of tag variables (in\n"
"              .dot format).\n"
"\n"
"       --dump-closure-stats\n"
"              Debug option: output statistics on the number of states in  clo‐\n"
"              sure.\n"
"\n"
"       --dump-dfa-det\n"
"              Debug  option:  output DFA immediately after determinization (in\n"
"              .dot format).\n"
"\n"
"       --dump-dfa-min\n"
"              Debug option: output DFA after minimization (in .dot format).\n"
"\n"
"       --dump-dfa-tagopt\n"
"              Debug option: output DFA after tag optimizations (in  .dot  for‐\n"
"              mat).\n"
"\n"
"       --dump-dfa-tree\n"
"              Debug  option:  output DFA under construction with states repre‐\n"
"              sented as tag history trees (in .dot format).\n"
"\n"
"       --dump-dfa-raw\n"
"              Debug  option:  output  DFA  under  construction  with  expanded\n"
"              state-sets (in .dot format).\n"
"\n"
"       --dump-interf\n"
"              Debug  option:  output  interference  table produced by liveness\n"
"              analysis of tag variables.\n"
"\n"
"       --dump-nfa\n"
"              Debug option: output NFA (in .dot format).\n"
"\n"
"       --dfa-minimization <moore | table>\n"
"              Internal option: DFA minimization algorithm used  by  re2c.  The\n"
"              moore option is the Moore algorithm (it is the default). The ta‐\n"
"              ble option is the \"table  filling\"  algorithm.  Both  algorithms\n"
"              should produce the same DFA up to states relabeling; table fill‐\n"
"              ing is simpler and much slower and serves as a reference  imple‐\n"
"              mentation.\n"
"\n"
"       --eager-skip\n"
"              Internal  option: make the generated lexer advance the input po‐\n"
"              sition eagerly -- immediately after reading  the  input  symbol.\n"
"              This changes the default behavior when the input position is ad‐\n"
"              vanced lazily -- after transition to the next state. This option\n"
"              is implied by --no-lookahead.\n"
"\n"
"       --no-lookahead\n"
"              Internal  option:  use  TDFA(0) instead of TDFA(1).  This option\n"
"              has effect only with --tags or --posix-captures options.\n"
"\n"
"       --no-optimize-tags\n"
"              Internal optionL: suppress optimization of tag variables (useful\n"
"              for debugging).\n"
"\n"
"       --posix-closure <gor1 | gtop>\n"
"              Internal  option:  specify  shortest-path algorithm used for the\n"
"              construction of epsilon-closure with POSIX disambiguation seman‐\n"
"              tics:  gor1  (the default) stands for Goldberg-Radzik algorithm,\n"
"              and gtop stands for \"global topological order\" algorithm.\n"
"\n"
"       --posix-prectable <complex | naive>\n"
"              Internal option: specify the algorithm  used  to  compute  POSIX\n"
"              precedence  table. The complex algorithm computes precedence ta‐\n"
"              ble in one traversal of tag history tree and has quadratic  com‐\n"
"              plexity  in  the  number  of TNFA states; it is the default. The\n"
"              naive algorithm has worst-case cubic complexity in the number of\n"
"              TNFA  states,  but  it  is  much simpler than complex and may be\n"
"              slightly faster in non-pathological cases.\n"
"\n"
"       --stadfa\n"
"              Internal option: use staDFA algorithm for  submatch  extraction.\n"
"              The  main  difference with TDFA is that tag operations in staDFA\n"
"              are placed in states, not on transitions.\n"
"\n"
"       --fixed-tags <none | toplevel | all>\n"
"              Internal option:  specify  whether  the  fixed-tag  optimization\n"
"              should  be  applied  to  all tags (all), none of them (none), or\n"
"              only those in toplevel concatenation (toplevel). The default  is\n"
"              all.   \"Fixed\"  tags  are  those that are located within a fixed\n"
"              distance to some other tag (called \"base\"). In such  cases  only\n"
"              tha base tag needs to be tracked, and the value of the fixed tag\n"
"              can be computed as the value of the base tag plus a static  off‐\n"
"              set.  For  tags  that  are under alternative or repetition it is\n"
"              also necessary to check if the base tag has a no-match value (in\n"
"              that case fixed tag should also be set to no-match, disregarding\n"
"              the offset). For tags in top-level concatenation  the  check  is\n"
"              not needed, because they always match.\n"
"\n"
"WARNINGS\n"
"       -W     Turn on all warnings.\n"
"\n"
"       -Werror\n"
"              Turn  warnings  into errors. Note that this option alone doesn't\n"
"              turn on any warnings; it only affects those warnings  that  have\n"
"              been turned on so far or will be turned on later.\n"
"\n"
"       -W<warning>\n"
"              Turn on warning.\n"
"\n"
"       -Wno-<warning>\n"
"              Turn off warning.\n"
"\n"
"       -Werror-<warning>\n"
"              Turn  on warning and treat it as an error (this implies -W<warn‐\n"
"              ing>).\n"
"\n"
"       -Wno-error-<warning>\n"
"              Don't treat this particular warning as an  error.  This  doesn't\n"
"              turn off the warning itself.\n"
"\n"
"       -Wcondition-order\n"
"              Warn  if  the generated program makes implicit assumptions about\n"
"              condition numbering. One should use either the -t, --type-header\n"
"              option or the /*!types:re2c*/ directive to generate a mapping of\n"
"              condition names to numbers and then use the autogenerated condi‐\n"
"              tion names.\n"
"\n"
"       -Wempty-character-class\n"
"              Warn  if a regular expression contains an empty character class.\n"
"              Trying to match an empty character  class  makes  no  sense:  it\n"
"              should  always  fail.  However, for backwards compatibility rea‐\n"
"              sons re2c allows empty character  classes  and  treats  them  as\n"
"              empty  strings.  Use  the --empty-class option to change the de‐\n"
"              fault behavior.\n"
"\n"
"       -Wmatch-empty-string\n"
"              Warn if a rule is nullable (matches an empty  string).   If  the\n"
"              lexer  runs  in a loop and the empty match is unintentional, the\n"
"              lexer may unexpectedly hang in an infinite loop.\n"
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
"              the  default  rule  * which has the lowest priority, matches any\n"
"              code unit, and consumes exactly one code unit.\n"
"\n"
"       -Wunreachable-rules\n"
"              Warn about rules that are shadowed by other rules and will never\n"
"              match.\n"
"\n"
"       -Wuseless-escape\n"
"              Warn  if  a symbol is escaped when it shouldn't be.  By default,\n"
"              re2c silently ignores such escapes, but this may as  well  indi‐\n"
"              cate a typo or an error in the escape sequence.\n"
"\n"
"       -Wnondeterministic-tags\n"
"              Warn  if  a  tag  has  n-th degree of nondeterminism, where n is\n"
"              greater than 1.\n"
"\n"
"       -Wsentinel-in-midrule\n"
"              Warn if the sentinel symbol occurs in the middle of a  rule  ---\n"
"              this  may  cause reads past the end of buffer, crashes or memory\n"
"              corruption in the generated lexer. This warning is only applica‐\n"
"              ble  if  the sentinel method of checking for the end of input is\n"
"              used.  It is set to an error if re2c:sentinel  configuration  is\n"
"              used.\n"
;
