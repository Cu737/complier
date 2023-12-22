#include "quadruples.h"
#include "cparser.h"
#include "./symbol_table/symbol.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>
void gen_code(struct ast* root);
char* int_to_cstar(int num);
void ErrorMessage(int type, const char* arg1, const char* arg2, int line);

int temp_count=0;

int error_flag = 0;
int cntt=0;
char error_str[128][128];

char* get_result(void)
{
   char *result = (char *)malloc(14 * sizeof(char));
   char *temp_char = (char *)malloc(10 * sizeof(char)); // 分配一个长度为 20 的字符数组
   sprintf(result, "%s%d", "temp",temp_count);
   //printf("%s\n",result);
    temp_count++;
    return result;
}

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
      else
      {
         node->value = node->children[0]->value;
      }
      
   }
}

void gen_condition_expression (struct ast *node)
{
   gen_code(node->children[0]);
   temp_count--;
    struct FourGroup* judge = tail;
   //假出口
   struct FourGroup*  falseJump= insert("jump","$","$","$");
   gen_code(node->children[2]);
   
   gen_code(node->children[4]);
   
   

   char *result = get_result();

   insert ("=",node->children[2]->value,"$",result);
   judge->jump = int_to_cstar(FourGroupId-1);
   insert ("=",node->children[4]->value,"$",result);
   falseJump->jump = int_to_cstar(FourGroupId-1);

   node->value = result;
   
}

int gen_single_transfer(struct ast *node)
{
   //向上传递值
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
   else if (node->num_children == 4)
   {
      insert(node->children[2]->value,node->children[3]->value,"$",node->children[1]->value);
     
      
   }
}


void gen_additive_expression(struct ast*node)
{
   //所有二目
   //除了expression
    if (node->num_children==3)
   {
      char * result = get_result();
      struct tokenval* token = (struct tokenval*)node->children[1];
      insert(token->nodevalue,node->children[0]->value,node->children[2]->value,result);
      node->value = result;
   }
}

void gen_unary_expression(struct ast*node)
{
   
   struct tokenval* token = (struct tokenval*)node->children[0];
   char *optype = token->nodevalue;
   
   

    if(strcmp(optype, "++") == 0)
    {  
      
      insert("+",node->children[1]->value,"1",node->children[1]->value);
      node->value = node->children[1]->value;
      
    }
    else if (strcmp(optype, "--") == 0)
    {
      
      insert("-",node->children[1]->value,"1",node->children[1]->value);
      node->value = node->children[1]->value;
      
    }
    else
    {
      char *result = get_result();
      if (strcmp(optype, "+") == 0)
      {
         insert("-",node->children[1]->value,"0",result);
         
      }
      else if (strcmp(optype, "-") == 0)
      {
         insert("-","0",node->children[1]->value,result);
      }
      else if (strcmp(optype, "!") == 0||strcmp(optype, "~") == 0||strcmp(optype, "sizeof") == 0)
      {
         if (strcmp(node->children[1]->nodetype, "TYPE") == 0)
         {
            struct tokenval* typenode = (struct tokenval*)node->children[1];
            

            insert(optype,typenode->nodevalue,"$",result);
         }
         else
         {
            insert(optype,node->children[1]->value,"$",result);
         }
         
      }
      else if (strcmp(optype, "*") == 0)
      {
         
            insert("ToAddress",node->children[1]->value,"$",result);
            
      }
      else if (strcmp(optype, "&") == 0)
      {
         
            insert("GetAddress",node->children[1]->value,"$",result);
            
      }

      node->value = result;
    }
   
}

void gen_postfix_expression(struct ast* node)
{
   //这边暂时只做了++ 和--
   //数组结构体和其他还没做

   
   if (node->num_children ==2)
   {
      
      char *result = get_result();
      char * optype = node->children[1]->nodetype;
      if (strcmp(optype, "INC_OP") == 0)
      {
         insert("=",node->children[0]->value,"$",result);
         insert("+",node->children[0]->value,"1",node->children[0]->value);
         node->value = result;
      }
      else if(strcmp(optype, "DEC_OP") == 0)
      {
         insert("=",node->children[0]->value,"$",result);
         insert("-",node->children[0]->value,"1",node->children[0]->value);
         node->value = result;
      }
      else if (strcmp(optype,"INT_LITERAL") ==0)
      {
         struct tokenval* token = (struct tokenval*)node->children[1];
         char *num = token->nodevalue;
         char *result1 = get_result();
         insert("+",node->children[0]->value,num,result1);
         char * result2 = get_result();
         insert("ToAdrress",result1,"$",result2);
         node->value = result2;
      }
      

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

      struct FourGroup* position_T = insert("JumpIf", c_node[2]->value, "$", int_to_cstar(FourGroupId + 2));
      struct FourGroup* position_F = insert("Jump", "$", "$", "$");
      gen_code(c_node[4]);
      gen_code(c_node[3]);

      struct FourGroup* goto_begin = insert("Jump", "$", "$", int_to_cstar(begin));
      char* F_index = int_to_cstar(FourGroupId);
      position_F->jump = F_index;
   }
   else if(strcmp(c_nodetype, "WHILE")==0){
      int begin = FourGroupId;
      gen_code(c_node[1]);
      struct FourGroup* true_exit = insert("JumpIf", c_node[1]->value, "$", int_to_cstar(FourGroupId + 2));
      struct FourGroup* false_exit = insert("Jump", "$", "$", "$");
      gen_code(c_node[2]);
      struct FourGroup* goto_begin = insert("Jump", "$", "$", int_to_cstar(begin));
      false_exit->jump = int_to_cstar(FourGroupId);
   }
}


void gen_selection_statement(struct ast* node)
{
      struct ast** c_node = node->children;
      size_t num_children = node->num_children;
      gen_code(c_node[1]);
      struct FourGroup* true_exit = insert("JumpIf", c_node[1]->value, "$", int_to_cstar(FourGroupId + 2));
      struct FourGroup* false_exit = insert("Jump", "$", "$", "$");
      gen_code(c_node[2]);
      false_exit->jump = int_to_cstar(FourGroupId);
      if(num_children==4)
      {
          gen_code(c_node[3]);
      }     
}

void gen_else_statement(struct ast* node)
{
      struct ast** c_node = node->children;
      size_t num_children = node->num_children;
      if(num_children==2){
         gen_code(c_node[1]);
      }
      else if(num_children==5)
      {
            gen_code(c_node[2]);
            struct FourGroup* true_exit = insert("JumpIf", c_node[2]->value, "$", int_to_cstar(FourGroupId + 2));
            struct FourGroup* false_exit = insert("Jump", "$", "$", "$");
            gen_code(c_node[3]);
            false_exit->jump = int_to_cstar(FourGroupId);
            gen_code(c_node[4]);
      }

}

void gen_code(struct ast* root)
{  
    char* nodetype = root->nodetype;
   //  printf("%s\n", nodetype);
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
   else if (strcmp(nodetype, "STAR_OP") == 0) {
       printf("%s\n",nodetype);
	}
   else if (strcmp(nodetype, "iteration_statement") == 0) {
       gen_iteration_statement(root);
   }
   else if (strcmp(nodetype, "selection_statement") == 0) {
       gen_selection_statement(root);    
	}
   else if (strcmp(nodetype, "else_statement") == 0) {
       gen_else_statement(root);
	}
   else if(strcmp(nodetype, "conditional_expression") == 0 &&root->num_children !=1)
   {
         gen_condition_expression(root);
   }else if (strcmp(nodetype,"assignment_expression")==0 && root->num_children ==4&&strcmp(root->children[3]->nodetype,"primary_expression_list")==0)
   {
      
      struct ast*temp = root->children[1]; //unary_expression
      temp = temp->children[0]; //fisrt postfix
      gen_code(temp->children[0]);//标识符读取
      char * id_str = temp->children[0]->value;

      temp = temp->children[1];
      struct tokenval* token = (struct tokenval*)temp;//提取数组数量
      int array_num = atoi(token->nodevalue);

      //初始化记录数组
      temp = root->children[3];
      char ** array_all = (char**)malloc(sizeof (char*)*array_num);
      
      int count = array_num;
      
      while(count >0)
      {
         count --;
         
         if(temp->num_children == 2)
         {
            gen_code(temp->children[1]);   
            array_all[count] = temp->children[1]->value;
            temp = temp->children[0];  

         }
         else
         {
            gen_code(temp->children[0]);
            temp = temp->children[0];
            array_all[count] = temp->value;
         }
         
      }
      for (int i =0; i<array_num; i++)
      {
         if(i==0)
         {
            char *result = get_result();
            insert("ToAdress",id_str,"$",result);
            insert("=",array_all[i],"$",result);

         }
         else
         {
            char *result = get_result();
            insert("+",id_str,int_to_cstar(i),result);
            char *result1 = get_result();
            insert("ToAdress",result,"$",result1);
            insert("=",array_all[i],"$",result1);
         }
        
      }
      

      
      
      
      
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
            else if (strcmp(nodetype, "unary_expression") == 0)
            {
                  //等于号
                  
                  gen_unary_expression(root);
            }
            else if (strcmp(nodetype, "postfix_expression") == 0)
            {
                  //等于号
                 
                  gen_postfix_expression(root);
            }
            else if (strcmp(nodetype, "additive_expression") == 0 ||strcmp(nodetype, "multiplicative_expression") == 0||strcmp(nodetype, "shift_expression") == 0
            ||strcmp(nodetype, "relational_expression") == 0||strcmp(nodetype, "equality_expression") == 0||strcmp(nodetype, "and_expression") == 0
            ||strcmp(nodetype, "exclusive_or_expression") == 0||strcmp(nodetype, "inclusize_or_expression") == 0||strcmp(nodetype, "logical_and_expression") == 0
            ||strcmp(nodetype, "logical_or_expression") == 0)
            {
                  
                  gen_additive_expression(root);
            }     
      }    
      //   printf("%zu -*%s: %u  (%s)\n",root ->num_children,root->nodetype,root->line_num,root->value);
    }
    
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
}