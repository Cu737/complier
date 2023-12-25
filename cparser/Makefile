cparser: cparser.l cparser.y cparser.h quadruples.h generate.h ./symbol_table/symbol.h ./code_optim/basic_block.h ./code_optim/dag.h
	bison -d  cparser.y
	flex -ocparser.lex.c cparser.l
	cc -o $@ cparser.tab.c cparser.lex.c cparser.c quadruples.c ./symbol_table/symbol.c ./code_optim/basic_block.c ./code_optim/dag.c

