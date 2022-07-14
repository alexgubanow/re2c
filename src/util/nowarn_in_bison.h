#ifndef _RE2C_UTIL_NOWARN_IN_BISON_
#define _RE2C_UTIL_NOWARN_IN_BISON_

// disable certain GCC and/or Clang warnings, as we have no control over
// autogenerated code (Clang also understands '#pragma GCC')
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic ignored "-Wconversion"
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wmissing-variable-declarations"
#pragma GCC diagnostic ignored "-Wunreachable-code"
#pragma GCC diagnostic ignored "-Wunreachable-code-break"

// Silence -Wunused-macro warnings on bison-generated macros.
// `#pragma GCC diagnostic ignored` doesn't help for macros that are emitted too early.

#ifdef YYPULL
#endif

#ifdef YYSKELETON_NAME
#endif

#ifdef YYBISON
#endif

#ifdef YYBISON_VERSION
#endif

#ifdef YYPURE
#endif

#ifdef YYPUSH
#endif

#endif // _RE2C_UTIL_NOWARN_IN_BISON_