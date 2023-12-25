#include "cparser.h"
#include "stdio.h"
#include "./symbol_table/symbol.h"

extern void print_error();
int error_flag=0;
int cntt=0;
char error_str[128][128];
#include "./code_optim/basic_block.h"

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
       printNode(node, depth);}
    else if (strcmp(nodetype, "FLOAT_LITERAL") == 0) {
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
   sprintf(error_str[cntt++], "❌ \033[31mERROR : %s in \033[44mline %d\033[0m\n",s,yylineno);

}

void ErrorMessage(int type, const char *arg1, const char *arg2, int line){
   printf("this is insertError!\n");
   printf("%d", type);
   switch (type)
   {  
   case 1:
      sprintf(error_str[cntt++],"❌ ERROR : need a \"%s\" in \033[44mline %d\033[0m\n", arg1, line);
      break;
   case 2:
      sprintf(error_str[cntt++],"❌ TYPE ERROR : Inconsistent types on either side of the symbol %s in \033[44mline %d\033[0m\n", arg1, line);
      break;
   default:
      break;
   
}
}

void print_error(){
   printf("\033[31m%s\033[0m", error_str[0]);
   if(cntt > 0){
      printf("\033[31m%s\033[0m", error_str[1]);
   }
   
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

    initializeSymbolTable(&symbolTable);

   //  if (yyparse() != 0) {
   //      // 解析失败
   //      print_error();
   //      fclose(input_file);
   //      return 0;
   //  }

   yyparse();

    printFourGroup();
    printfAllEntry(&symbolTable);
    printfAllEntry(&constSymbolTable);

    // BasicBlock* basic_blocks;
    // int num_blocks;
    // generate_basic_blocks(head, FourGroupId - 1, &basic_blocks, &num_blocks);
    // optimize_basic_blocks(basic_blocks, num_blocks);
    // printFourGroup();
    
	if(error_flag == 0)
	{
		printf("test \n\n");
	} else {
      print_error();
		printf("parse_error zjr hhhhhh \n\n");
	}
    
    
    // Close the file
    fclose(input_file);

    return 0;
}


