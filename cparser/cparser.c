#include "cparser.h"


struct ast *
newast(char* nodetype, unsigned int line_num, size_t num_children, ...)
{
    struct ast *node = malloc(sizeof(struct ast));
    if(!node){
        fprintf(stderr, "Memory allocation error for ast\n");
        exit(EXIT_FAILURE);
    }
    node->nodetype = nodetype;
    node->line_num = line_num;
    node->num_children = num_children;
    node->value = "";


    node->children = malloc(num_children * sizeof(struct ast *));
    if(!node->children) {
        fprintf(stderr, "Memory allocation error for ast children\n");
        exit(EXIT_FAILURE);
    }

    va_list args;
    va_start(args, num_children);
    for (size_t i=0; i<num_children; ++i){
        node->children[i] = va_arg(args, struct ast *);
    }

    va_end(args);
    //printf("newast: %s, (%u)\n", nodetype, line_num);
    //printf("%s\n", node->children[0]->nodetype);
    return node;
};

struct ast *
newtoken(char* nodetype, char* nodevalue, unsigned int line_num)
{
    struct tokenval *token = malloc(sizeof(struct tokenval));
    if(!token){
        fprintf(stderr, "Memory allocation error for token \n");
        exit(EXIT_FAILURE);
    }
    token->nodetype = nodetype;
    token->nodevalue = nodevalue;
    token->line_num = line_num;
    
    printf("newtoken: %s, %s (%u)\n", nodetype, nodevalue, line_num);
    return (struct ast*) token;
}

void eval(struct ast *node, unsigned int depth)
{
    char* nodetype = node->nodetype;
    char* nodevalue;
    unsigned int line_num;

    if (strcmp(nodetype, "ID") == 0) {
        printNode(node, depth);
    } else if (strcmp(nodetype, "INT_LITERAL") == 0) {
        printNode(node, depth);
    }else if (strcmp(nodetype, "ASSIGNOP") == 0) {
       printNode(node, depth);
    }else if (strcmp(nodetype, "CHAR_LITERAL") == 0) {
        printNode(node, depth);
    } else if (strcmp(nodetype, "STRING_LITERAL") == 0) {
        printNode(node, depth);
    } else if (strcmp(nodetype, "TYPE") == 0) {
        printNode(node, depth);
    } else if (strcmp(nodetype, "SIZEOF") == 0) {
        printNode(node, depth);
    } else if (strcmp(nodetype, "OR_OP") == 0) {
        printNode(node, depth);
    } else if (strcmp(nodetype, "AND_OP") == 0) {
       printNode(node, depth);
    } else if (strcmp(nodetype, "EQ_OP") == 0) {
        printNode(node, depth);
    } else if (strcmp(nodetype, "IF") == 0) {
       printNode(node, depth);
    } else if (strcmp(nodetype, "ELSE") == 0) {
        printNode(node, depth);
    } else if (strcmp(nodetype, "LE_OP") == 0) {
       printNode(node, depth);
    } else if (strcmp(nodetype, "GE_OP") == 0) {
       printNode(node, depth);
    } else if (strcmp(nodetype, "LEFT_OP") == 0) {
        printNode(node, depth);
    } else if (strcmp(nodetype, "RIGHT_OP") == 0) {
       printNode(node, depth);
    } else if (strcmp(nodetype, "INC_OP") == 0) {
        printNode(node, depth);
    } else if (strcmp(nodetype, "DEC_OP") == 0) {
       printNode(node, depth);
    } else if (strcmp(nodetype, "PTR_OP") == 0) {
       printNode(node, depth);
    } else if (strcmp(nodetype, "WHILE") == 0) {
       printNode(node, depth);
    } else if (strcmp(nodetype, "FOR") == 0) {
       printNode(node, depth);
    } else if (strcmp(nodetype, "GOTO") == 0) {
       printNode(node, depth);
    } else if (strcmp(nodetype, "CONTINUE") == 0) {
        printNode(node, depth);
    } else if (strcmp(nodetype, "BREAK") == 0) {
       printNode(node, depth);
    } else if (strcmp(nodetype, "RETURN") == 0) {
       printNode(node, depth);
    } else if (strcmp(nodetype, "(") == 0) {
       printNode(node, depth);
    } else if (strcmp(nodetype, ")") == 0) {
       printNode(node, depth);
    } else if (strcmp(nodetype, "[") == 0) {
        printNode(node, depth);
    } else if (strcmp(nodetype, "]") == 0) {
        printNode(node, depth);
    } else if (strcmp(nodetype, "{") == 0) {
        printNode(node, depth);
    } else if (strcmp(nodetype, "}") == 0) {
       printNode(node, depth);
    } else if (strcmp(nodetype, ".") == 0) {
       printNode(node, depth);
    } else if (strcmp(nodetype, "L_OP") == 0) {
        printNode(node, depth);
    } else if (strcmp(nodetype, "G_OP") == 0) {
       printNode(node, depth);
    } else if (strcmp(nodetype, "ADD_OP") == 0) {
       printNode(node, depth);
    } else if (strcmp(nodetype, "MINUS_OP") == 0) {
        printNode(node, depth);
    } else if (strcmp(nodetype, "MUL_OP") == 0) {
       printNode(node, depth);
    } else if (strcmp(nodetype, "DIV_OP") == 0) {
       printNode(node, depth);
    } else if (strcmp(nodetype, "QUESTION_MARK") == 0) {
       printNode(node, depth);
    } else if (strcmp(nodetype, "YES_OP") == 0) {
       printNode(node, depth);
    } else if (strcmp(nodetype, "NO_OP") == 0) {
       printNode(node, depth);
    } else if (strcmp(nodetype, "COLON") == 0) {
       printNode(node, depth);
    } else if (strcmp(nodetype, "PIPE") == 0) {
       printNode(node, depth);
    } else if (strcmp(nodetype, "CARET") == 0) {
       printNode(node, depth);
    } else if (strcmp(nodetype, "AMPERSAND") == 0) {
       printNode(node, depth);
    } else if (strcmp(nodetype, "NE_OP") == 0) {
       printNode(node, depth);
    } else if (strcmp(nodetype, "SUB_OP") == 0) {
       printNode(node, depth);
    } else if (strcmp(nodetype, "REMAIN_OP") == 0) {
       printNode(node, depth);
	} else if (strcmp(nodetype, "STAR_OP") == 0) {
       printNode(node, depth);
	}
    
    else{
        /* for nonterrminals */
        size_t num_children = node->num_children;
        line_num = node->line_num;
        for (unsigned int i = 0; i < depth; ++i) {
            printf(" ");
        }
        printf("-*%s: (%u)\n", nodetype, line_num);
        for(size_t i = 0; i<num_children; ++i){
            if (node->children[i] == NULL)
            {   continue;   }
            eval(node->children[i], depth+1);
        }
    }
}

void printNode(struct ast *node, unsigned int depth) {
    struct tokenval* token = (struct tokenval*)node;
    char* nodetype = token->nodetype;
    char* nodevalue = token->nodevalue;
    unsigned int line_num = token->line_num;
    for (unsigned int i = 0; i < depth; ++i) {
        printf(" ");
    }
    printf("-*%s: %s (%u)\n", nodetype, nodevalue, line_num);
}

void yyerror(char *s, ...)
{
    va_list ap;
    va_start(ap, s);

    fprintf(stderr, "%d: error:", yylineno);
    vfprintf(stderr, s, ap);
    fprintf(stderr, "\n");
}

int main(int argc, char *argv[])
{
   if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file.c>\n", argv[0]);
        return 1;
    }

    FILE* input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error opening file %s\n", argv[1]);
        return 1;
    }

    // Set the input file for the lexer
    yyset_in(input_file);

    // Call the parser
    yyparse();

    

    printFourGroup();
    

    // Close the file
    fclose(input_file);

    return 0;
}

