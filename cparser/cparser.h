/*
* Declarations for a C parser
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>

struct ast* root;
/* interface to the lexer */
extern int yylineno; /* from lexer */
extern int yylex(void);
extern int yyparse(void);

void yyerror(char *s, ...);

/* nodes in the abstract syntax tree */
struct ast {
    char* nodetype;
    unsigned int line_num;
    size_t num_children;
    struct ast **children;

};

struct tokenval{
    char* nodetype;
    char* nodevalue;
    unsigned int line_num;
};

/* build an AST */
struct ast *newast(char* nodetype, unsigned int line_num, size_t num_children, ...);
struct ast *newtoken(char* nodetype, char* nodevalue, unsigned int line_num);

/* evaluate an AST */
void eval(struct ast*, unsigned int);

/*print the tree*/
void printNode(struct ast *, unsigned int);




