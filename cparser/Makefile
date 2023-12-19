cparser: cparser.l cparser.y cparser.h quadruples.h generate.h ./symbol_table/symbol.h
	bison -d  cparser.y
	flex -ocparser.lex.c cparser.l
	cc -o $@ cparser.tab.c cparser.lex.c cparser.c quadruples.c ./symbol_table/symbol.c

