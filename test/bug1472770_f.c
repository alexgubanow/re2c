/* Generated by re2c */
#line 1 "bug1472770_f.re"
// re2c $INPUT -o $OUTPUT -f
#define NULL ((char*) 0)
#define YYCTYPE char
#define YYCURSOR p
#define YYLIMIT p
#define YYMARKER q
#define YYFILL(n)

YYCTYPE yych;
int yySavedState;

#define YYGETSTATE()	yySavedState
#define YYSETSTATE(n)	yySavedState = n;

#include <stdio.h>

int scan(char *p)
{
	int n = 0;
	char *q;
	
	printf("[--------------\n");
	printf("%s\n", p);
	printf("]--------------\n");
start:

#line 30 "bug1472770_f.c"
{
	switch (YYGETSTATE()) {
		default: goto yy0;
		case 0: goto yyFillLabel0;
	}
yy0:
	goto yy1;
yy2:
	++YYCURSOR;
yy1:
	YYSETSTATE(0);
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
yyFillLabel0:
	yych = *YYCURSOR;
	switch (yych) {
		case 0x00: goto yy3;
		case '\n': goto yy4;
		default: goto yy2;
	}
yy3:
	++YYCURSOR;
	YYSETSTATE(-1);
#line 33 "bug1472770_f.re"
	{
		return n;
	}
#line 57 "bug1472770_f.c"
yy4:
	++YYCURSOR;
	YYSETSTATE(-1);
#line 28 "bug1472770_f.re"
	{
		++n;
		goto start;
	}
#line 66 "bug1472770_f.c"
}
#line 36 "bug1472770_f.re"

}

int main(int argc, char **argv)
{
	int n = 0;
	char *largv[4];

	if (argc < 2)
	{
		argc = 4;
		argv = largv;
		argv[1] = "";
		argv[2] = "1\n\n";
		argv[3] = "1\n2\n";
	}
	while(++n < argc)
	{
		printf("%d\n", scan(argv[n]));
	}
	return 0;
}
