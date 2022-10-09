/* Generated by re2c */
// re2c $INPUT -o $OUTPUT -csif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	BSIZE	8192

enum ScanContition {
	EStateNormal,
	EStateComment,
	EStateSkiptoeol,
	EStateString
};


typedef struct Scanner
{
	FILE			    *fp;
	unsigned char	    *cur, *tok, *lim, *eof;
	unsigned char 	    buffer[BSIZE];
	unsigned char       yych;
	enum ScanContition  cond;
	int                 state;
} Scanner;

size_t fill(Scanner *s, size_t len)
{
	size_t got = ~0, cnt;

	if (!s->eof && s->lim - s->tok < len)
	{
		if (s->tok > s->buffer)
		{
			cnt = s->tok - s->buffer;
			memcpy(s->buffer, s->tok, s->lim - s->tok);
			s->tok -= cnt;
			s->cur -= cnt;
			s->lim -= cnt;
			cnt = &s->buffer[BSIZE] - s->lim;
		}
		else
		{
			cnt = BSIZE;
		}
		if ((got = fread(s->lim, 1, cnt, s->fp)) != cnt)
		{
			s->eof = &s->lim[got];
		}
		s->lim += got;
	}
	if (s->eof && s->cur + len > s->eof)
	{
		return ~0; /* not enough input data */
	}
	return got;
}

size_t init(Scanner *s)
{
	s->cur = s->tok = s->lim = s->buffer;
	s->eof = 0;
	s->cond = EStateNormal;
	s->state = -1;

	return fill(s, 0);
}

void fputl(const char *s, size_t len, FILE *stream)
{
	while(len-- > 0)
	{
		fputc(*s++, stream);
	}
}

void scan(Scanner *s)
{
	s->tok = s->cur;

	switch (s->state) {
		default: goto yy0;
		case 0: goto yyFillLabel0;
		case 1: goto yyFillLabel1;
		case 2: goto yyFillLabel2;
		case 3: goto yyFillLabel3;
	}

	for(;;)
	{
		s->tok = s->cur;

		{
yy0:
			if (s->cond < 2) {
				if (s->cond < 1) {
					goto yyc_Normal;
				} else {
					goto yyc_Comment;
				}
			} else {
				if (s->cond < 3) {
					goto yyc_Skiptoeol;
				} else {
					goto yyc_String;
				}
			}
/* *********************************** */
yyc_Normal:
			s->state = 0;(0);
			if ((s->lim - s->cur) < 4) if (fill(s, 4) == ~0) break;
yyFillLabel0:
			s->yych = *s->cur;
			if (s->yych <= '\'') {
				if (s->yych == '"') goto yy3;
				if (s->yych >= '\'') goto yy4;
			} else {
				if (s->yych <= '/') {
					if (s->yych >= '/') goto yy5;
				} else {
					if (s->yych == '?') goto yy6;
				}
			}
			++s->cur;
yy2:
			s->state = -1;(-1);
			fputc(s->cur[-1], stdout);
		continue;
yy3:
			++s->cur;
			s->state = -1;(-1);
			s->cond = EStateString;(EStateString);
			fputc(s->cur[-1], stdout);
		continue;
yy4:
			s->yych = *(s->tok = ++s->cur);
			if (s->yych == '"') goto yy7;
			if (s->yych == '\\') goto yy9;
			goto yy2;
yy5:
			s->yych = *++s->cur;
			if (s->yych == '*') goto yy10;
			if (s->yych == '/') goto yy11;
			goto yy2;
yy6:
			s->yych = *(s->tok = ++s->cur);
			if (s->yych == '?') goto yy12;
			goto yy2;
yy7:
			s->yych = *++s->cur;
			if (s->yych == '\'') goto yy13;
yy8:
			s->cur = s->tok;
			goto yy2;
yy9:
			s->yych = *++s->cur;
			if (s->yych == '"') goto yy7;
			goto yy8;
yy10:
			++s->cur;
			s->state = -1;(-1);
			s->cond = EStateComment;(EStateComment);
			continue;
yy11:
			++s->cur;
			s->state = -1;(-1);
			s->cond = EStateSkiptoeol;(EStateSkiptoeol);
			continue;
yy12:
			s->yych = *++s->cur;
			switch (s->yych) {
				case '!': goto yy14;
				case '\'': goto yy15;
				case '(': goto yy16;
				case ')': goto yy17;
				case '-': goto yy18;
				case '/': goto yy19;
				case '<': goto yy20;
				case '=': goto yy21;
				case '>': goto yy22;
				default: goto yy8;
			}
yy13:
			++s->cur;
			s->state = -1;(-1);
			fputl("'\"'", 3, stdout);
		continue;
yy14:
			++s->cur;
			s->state = -1;(-1);
			fputc('|', stdout);
		continue;
yy15:
			++s->cur;
			s->state = -1;(-1);
			fputc('^', stdout);
		continue;
yy16:
			++s->cur;
			s->state = -1;(-1);
			fputc('[', stdout);
		continue;
yy17:
			++s->cur;
			s->state = -1;(-1);
			fputc(']', stdout);
		continue;
yy18:
			++s->cur;
			s->state = -1;(-1);
			fputc('~', stdout);
		continue;
yy19:
			++s->cur;
			s->state = -1;(-1);
			fputc('\\', stdout);
		continue;
yy20:
			++s->cur;
			s->state = -1;(-1);
			fputc('{', stdout);
		continue;
yy21:
			++s->cur;
			s->state = -1;(-1);
			fputc('#', stdout);
		continue;
yy22:
			++s->cur;
			s->state = -1;(-1);
			fputc('}', stdout);
		continue;
/* *********************************** */
yyc_Comment:
			s->state = 1;(1);
			if ((s->lim - s->cur) < 2) if (fill(s, 2) == ~0) break;
yyFillLabel1:
			s->yych = *s->cur;
			if (s->yych == '*') goto yy25;
			++s->cur;
yy24:
			s->state = -1;(-1);
			continue;
yy25:
			s->yych = *++s->cur;
			if (s->yych != '/') goto yy24;
			++s->cur;
			s->state = -1;(-1);
			s->cond = EStateNormal;(EStateNormal);
			continue;
/* *********************************** */
yyc_Skiptoeol:
			s->state = 2;(2);
			if ((s->lim - s->cur) < 5) if (fill(s, 5) == ~0) break;
yyFillLabel2:
			s->yych = *s->cur;
			if (s->yych <= '\r') {
				if (s->yych == '\n') goto yy28;
				if (s->yych >= '\r') goto yy29;
			} else {
				if (s->yych <= '?') {
					if (s->yych >= '?') goto yy30;
				} else {
					if (s->yych == '\\') goto yy31;
				}
			}
			++s->cur;
yy27:
			s->state = -1;(-1);
			continue;
yy28:
			++s->cur;
			s->state = -1;(-1);
			s->cond = EStateNormal;(EStateNormal);
			fputc('\n', stdout);
		continue;
yy29:
			s->yych = *++s->cur;
			if (s->yych == '\n') goto yy32;
			goto yy27;
yy30:
			s->yych = *(s->tok = ++s->cur);
			if (s->yych == '?') goto yy33;
			goto yy27;
yy31:
			s->yych = *(s->tok = ++s->cur);
			if (s->yych == '\n') goto yy35;
			if (s->yych == '\r') goto yy36;
			goto yy27;
yy32:
			++s->cur;
			s->state = -1;(-1);
			s->cond = EStateNormal;(EStateNormal);
			fputc('\r', stdout);
		fputc('\n', stdout);
		continue;
yy33:
			s->yych = *++s->cur;
			if (s->yych == '/') goto yy37;
yy34:
			s->cur = s->tok;
			goto yy27;
yy35:
			++s->cur;
			s->state = -1;(-1);
			continue;
yy36:
			s->yych = *++s->cur;
			if (s->yych == '\n') goto yy35;
			goto yy34;
yy37:
			s->yych = *++s->cur;
			if (s->yych == '\n') goto yy38;
			if (s->yych == '\r') goto yy39;
			goto yy34;
yy38:
			++s->cur;
			s->state = -1;(-1);
			continue;
yy39:
			s->yych = *++s->cur;
			if (s->yych == '\n') goto yy38;
			goto yy34;
/* *********************************** */
yyc_String:
			s->state = 3;(3);
			if ((s->lim - s->cur) < 2) if (fill(s, 2) == ~0) break;
yyFillLabel3:
			s->yych = *s->cur;
			if (s->yych == '"') goto yy42;
			if (s->yych == '\\') goto yy43;
			++s->cur;
yy41:
			s->state = -1;(-1);
			fputc(s->cur[-1], stdout);
		continue;
yy42:
			++s->cur;
			s->state = -1;(-1);
			s->cond = EStateNormal;(EStateNormal);
			fputc(s->cur[-1], stdout);
		continue;
yy43:
			s->yych = *++s->cur;
			if (s->yych == '\n') goto yy41;
			++s->cur;
			s->state = -1;(-1);
			fputl((const char*)s->cur-2, 2, stdout);
		continue;
		}

	}
}

int main(int argc, char **argv)
{
	Scanner in;

	if (argc != 2)
	{
		fprintf(stderr, "%s <file>\n", argv[0]);
		return 1;;
	}

	memset((char*) &in, 0, sizeof(in));

	if (!strcmp(argv[1], "-"))
	{
		in.fp = stdin;
	}
	else if ((in.fp = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Cannot open file '%s'\n", argv[1]);
		return 1;
	}

	if (init(&in) > 0)
	{
 		scan(&in);
 	}

	if (in.fp != stdin)
	{
		fclose(in.fp);
	}
	return 0;
}
