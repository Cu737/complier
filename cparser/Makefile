cparser: cparser.l cparser.y cparser.h
	bison -d  cparser.y
	flex -ocparser.lex.c cparser.l
	cc -o $@ cparser.tab.c cparser.lex.c cparser.c
