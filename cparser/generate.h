#include "quadruples.h"
#include "cparser.h"
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>

int temp_count =0;

void gen_primary_expression(struct ast*node)
{
   //除了expression
    if (node->num_children==1 && node->children[0]!= NULL)
   {
      if(strcmp(node->children[0]->nodetype,"expression")!=0)
      {
         struct tokenval* token = (struct tokenval*)node->children[0];
         node->value = token->nodevalue;
      }
      
   }
}


int gen_single_transfer(struct ast *node)
{
   if (node->num_children==1 && node->children[0]!= NULL)
   {
      node->value = node->children[0]->value;
      return 1;
   }
   return 0;
}




void gen_assignment_expression(struct ast* node)
{
   //assignment ->unary
   if (node->num_children == 3)
   {
      insert(node->children[1]->value,node->children[2]->value,"$",node->children[0]->value);
   }
}


void gen_additive_expression(struct ast*node)
{
   //除了expression
    if (node->num_children==3)
   {
      char *result = (char *)malloc(14 * sizeof(char));
      char *temp_char = (char *)malloc(10 * sizeof(char)); // 分配一个长度为 20 的字符数组
      sprintf(result, "%s%d", "temp",temp_count);
      //printf("%s\n",result);
      temp_count++;
      struct tokenval* token = (struct tokenval*)node->children[1];
      insert(token->nodevalue,node->children[0]->value,node->children[2]->value,result);
      node->value = result;
   }
}

char* int_to_cstar(int num){
   char *buffer = (char *)malloc(14 * sizeof(char));
   sprintf(buffer, "%d", num);
   return buffer;
}

void gen_iteration_statement(struct ast* node)
{
   struct ast** c_node = node->children;
   char* c_nodetype = c_node[0]->nodetype;
   if (strcmp(c_nodetype, "FOR") == 0){
      gen_code(c_node[1]);
      int begin = FourGroupId;
      gen_code(c_node[2]);

      struct FourGroup* position_T = insert("JumpIf", c_node[2]->value, "", int_to_cstar(FourGroupId + 2));
      struct FourGroup* position_F = insert("Jump", "", "", "");
      gen_code(c_node[4]);
      gen_code(c_node[3]);

      struct FourGroup* goto_begin = insert("Jump", "", "", int_to_cstar(begin));

      char* F_index = int_to_cstar(FourGroupId);
      position_F->jump = F_index;
   }
   else if(strcmp(c_nodetype, "WHILE")==0){
      int begin = FourGroupId;
      gen_code(c_node[1]);
      struct FourGroup* true_exit = insert("JumpIf", c_node[1]->value, "", int_to_cstar(FourGroupId + 2));
      struct FourGroup* false_exit = insert("Jump", "", "", "");
      gen_code(c_node[2]);
      struct FourGroup* goto_begin = insert("Jump", "", "", int_to_cstar(begin));
      false_exit->jump = int_to_cstar(FourGroupId);
   }
}


void gen_code(struct ast* root)
{
    char* nodetype = root->nodetype;
    if (strcmp(nodetype, "ID") == 0) {
        printf("%s\n",nodetype);
    } else if (strcmp(nodetype, "INT_LITERAL") == 0) {
        printf("%s\n",nodetype);
    }else if (strcmp(nodetype, "ASSIGNOP") == 0) {
        printf("%s\n",nodetype);
    }else if (strcmp(nodetype, "CHAR_LITERAL") == 0) {
        printf("%s\n",nodetype);
    } else if (strcmp(nodetype, "STRING_LITERAL") == 0) {
        printf("%s\n",nodetype);
    } else if (strcmp(nodetype, "TYPE") == 0) {
        printf("%s\n",nodetype);
    } else if (strcmp(nodetype, "SIZEOF") == 0) {
        printf("%s\n",nodetype);
    } else if (strcmp(nodetype, "OR_OP") == 0) {
        printf("%s\n",nodetype);
    } else if (strcmp(nodetype, "AND_OP") == 0) {
        printf("%s\n",nodetype);
    } else if (strcmp(nodetype, "EQ_OP") == 0) {
        printf("%s\n",nodetype);
    } else if (strcmp(nodetype, "IF") == 0) {
        printf("%s\n",nodetype);
    } else if (strcmp(nodetype, "ELSE") == 0) {
        printf("%s\n",nodetype);
    } else if (strcmp(nodetype, "LE_OP") == 0) {
       printf("%s\n",nodetype);
    } else if (strcmp(nodetype, "GE_OP") == 0) {
       printf("%s\n",nodetype);
    } else if (strcmp(nodetype, "LEFT_OP") == 0) {
        printf("%s\n",nodetype);
    } else if (strcmp(nodetype, "RIGHT_OP") == 0) {
       printf("%s\n",nodetype);
    } else if (strcmp(nodetype, "INC_OP") == 0) {
        printf("%s\n",nodetype);
    } else if (strcmp(nodetype, "DEC_OP") == 0) {
       printf("%s\n",nodetype);
    } else if (strcmp(nodetype, "PTR_OP") == 0) {
       printf("%s\n",nodetype);
    } else if (strcmp(nodetype, "WHILE") == 0) {
       printf("%s\n",nodetype);
    } else if (strcmp(nodetype, "FOR") == 0) {
       printf("%s\n",nodetype);
    } else if (strcmp(nodetype, "GOTO") == 0) {
       printf("%s\n",nodetype);
    } else if (strcmp(nodetype, "CONTINUE") == 0) {
        printf("%s\n",nodetype);
    } else if (strcmp(nodetype, "BREAK") == 0) {
       printf("%s\n",nodetype);
    } else if (strcmp(nodetype, "RETURN") == 0) {
       printf("%s\n",nodetype);
    } else if (strcmp(nodetype, "(") == 0) {
       printf("%s\n",nodetype);
    } else if (strcmp(nodetype, ")") == 0) {
       printf("%s\n",nodetype);
    } else if (strcmp(nodetype, "[") == 0) {
        printf("%s\n",nodetype);
    } else if (strcmp(nodetype, "]") == 0) {
        printf("%s\n",nodetype);
    } else if (strcmp(nodetype, "{") == 0) {
        printf("%s\n",nodetype);
    } else if (strcmp(nodetype, "}") == 0) {
       printf("%s\n",nodetype);
    } else if (strcmp(nodetype, ".") == 0) {
       printf("%s\n",nodetype);
    } else if (strcmp(nodetype, "L_OP") == 0) {
        printf("%s\n",nodetype);
    } else if (strcmp(nodetype, "G_OP") == 0) {
       printf("%s\n",nodetype);
    } else if (strcmp(nodetype, "ADD_OP") == 0) {
       printf("%s\n",nodetype);
    } else if (strcmp(nodetype, "MINUS_OP") == 0) {
        printf("%s\n",nodetype);
    } else if (strcmp(nodetype, "MUL_OP") == 0) {
       printf("%s\n",nodetype);
    } else if (strcmp(nodetype, "DIV_OP") == 0) {
       printf("%s\n",nodetype);
    } else if (strcmp(nodetype, "QUESTION_MARK") == 0) {
       printf("%s\n",nodetype);
    } else if (strcmp(nodetype, "YES_OP") == 0) {
       printf("%s\n",nodetype);
    } else if (strcmp(nodetype, "NO_OP") == 0) {
       printf("%s\n",nodetype);
    } else if (strcmp(nodetype, "COLON") == 0) {
       printf("%s\n",nodetype);
    } else if (strcmp(nodetype, "PIPE") == 0) {
       printf("%s\n",nodetype);
    } else if (strcmp(nodetype, "CARET") == 0) {
       printf("%s\n",nodetype);
    } else if (strcmp(nodetype, "AMPERSAND") == 0) {
       printf("%s\n",nodetype);
    } else if (strcmp(nodetype, "NE_OP") == 0) {
       printf("%s\n",nodetype);
    } else if (strcmp(nodetype, "SUB_OP") == 0) {
       printf("%s\n",nodetype);
    } else if (strcmp(nodetype, "REMAIN_OP") == 0) {
       printf("%s\n",nodetype);
	}
    else
    {
        size_t num_children = root->num_children;
        if (num_children!=0)
        {
            for (size_t i = 0; i < root->num_children;i++)
            {
                if (root->children[i]!= NULL)
                {
                    gen_code(root->children[i]);
                }
                
            }
        }
        int flag = 0;
        if (strcmp(nodetype,"primary_expression") ==0||strcmp(nodetype,"assignment_operator") ==0)
        {
            //token值读取
            gen_primary_expression(root);
        }
        else if (strcmp(nodetype,"program") !=0 && strcmp(nodetype,"external_declaration") !=0 &&strcmp(nodetype,"declaration_specifiers") !=0
           && strcmp(nodetype,"type_specifier") !=0 && strcmp(nodetype,"params") !=0 && strcmp(nodetype,"param_list") !=0 
           && strcmp(nodetype,"param") !=0&& strcmp(nodetype,"compound_statement") !=0&& strcmp(nodetype,"statement_list_opt") !=0 
           && strcmp(nodetype,"statement_list") !=0 && strcmp(nodetype,"statement_and_declaration") !=0 && strcmp(nodetype,"statement") !=0 
           && strcmp(nodetype,"call_statement") !=0 &&strcmp(nodetype,"jump_statement") !=0)
        {
            //单传值
            flag = gen_single_transfer(root);
        }


        if (!flag)
        {
            if (strcmp(nodetype, "assignment_expression") == 0)
            {
                  //等于号
                  gen_assignment_expression(root);
            }
            else if (strcmp(nodetype, "additive_expression") == 0)
            {
                  gen_additive_expression(root);
            }
            else if (strcmp(nodetype, "iteration_statement") == 0)
            {
                  gen_iteration_statement(root);
            }
            
            
        }
        
        
        
        printf("%zu -*%s: %u  (%s)\n",root ->num_children,root->nodetype,root->line_num,root->value);
    }
    
    
}

