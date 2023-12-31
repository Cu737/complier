%{
#include "generate.h"
%}

%union {
    struct ast *a;
    char * c;
}

%token <c> ID TYPE INT_LITERAL CHAR_LITERAL STRING_LITERAL SIZEOF
OR_OP AND_OP EQ_OP NE_OP LE_OP GE_OP LEFT_OP RIGHT_OP INC_OP DEC_OP PTR_OP STAR_OP
IF ELSE WHILE FOR GOTO CONTINUE BREAK RETURN   
'(' ')' '[' ']'  '.' '<' '>' '+' '-' '*' '/'  '?' '|' '~' '&' '^' ':' '!' '%' '='
TRUE FALSE CONST SWITCH CASE DEFAULT DO SCANF PRINTF ASSIGNDIV
ASSIGNSTAR ASSIGNCOM ASSIGNPLUS ASSIGNMINUS FLOAT_LITERAL HEAD


%type <a>  program external_declaration function_definition declaration_specifiers type_specifier var_declaration
compound_statement statement_list statement expression_statement expression assignment_expression assignment_operator
conditional_expression logical_or_expression logical_and_expression inclusize_or_expression exclusive_or_expression
and_expression equality_expression relational_expression shift_expression additive_expression multiplicative_expression
cast_expression unary_expression postfix_expression primary_expression argument_expression_list statement_list_opt
selection_statement jump_statement iteration_statement else_statement params param_list param call_statement
statement_and_declaration primary_expression_list

%%



program:
    /* empty */{
        printf("starting print syntex tree \n");
    }
    | program external_declaration 
    { 
      $$ = newast("program", $2->line_num, 1, $2);
      eval($$, 0);
      gen_code($$);
      free($$);
    }
    

external_declaration:
    function_definition
    { $$ = newast("external_declaration", $1->line_num, 1, $1); }
    | var_declaration
    { $$ = newast("external_declaration", $1->line_num, 1, $1); }

function_definition:
    declaration_specifiers ID '(' params ')' compound_statement
    { $$ = newast("function_definition", $1->line_num, 4, $1, newtoken("ID", $2, @2.first_line), $4, $6); }
    
var_declaration:
    declaration_specifiers postfix_expression ';'
    { 
        $$ = newast("var_declaration", $1->line_num, 2, $1, $2);
    }
    | declaration_specifiers STAR_OP ID ';'
    { $$ = newast("var_declaration", $1->line_num, 3, $1, newtoken("STAR_OP", $2, @2.first_line), newtoken("ID", $3, @3.first_line));} //modify
    |    declaration_specifiers postfix_expression 
    { 
        $$ = newast("var_declaration", $1->line_num, 2, $1, $2);
        ErrorMessage(1,";","",yylineno);
        error_flag=1;
    }
    |    declaration_specifiers STAR_OP ID error
    { 
        $$ = newast("var_declaration", $1->line_num, 3, $1, newtoken("STAR_OP", $2, @2.first_line), newtoken("ID", $3, @3.first_line));
        ErrorMessage(1,";","",$1->line_num);
        error_flag=1;
    }

    
declaration_specifiers:
    type_specifier 
    { $$ = newast("declaration_specifiers", $1->line_num, 1, $1); }
    | declaration_specifiers type_specifier 
    { $$ = newast("declaration_specifiers", $1->line_num, 2, $1, $2); }

type_specifier:
    TYPE 
    { $$ = newast("type_specifier", @1.first_line, 1, newtoken("TYPE", $1, @1.first_line)); }

params:
	param_list	{ $$ = newast("params", $1->line_num, 1, $1); }
    |	/**/	{ $$ = NULL; }

param_list:
	param ',' param_list       
    { $$ = newast("param_list", $1->line_num, 2, $1, $3); }
    |param	                        
    { $$ = newast("param_list", $1->line_num, 1, $1); }

param:
	type_specifier ID                              
    { $$ = newast("param", $1->line_num, 2, $1, newtoken("ID", $2, @2.first_line)); }
    |type_specifier ID '[' ']'     
    { $$ = newast("param", $1->line_num, 2, $1, newtoken("ID", $2, @2.first_line)); }
    | STRING_LITERAL
    { $$ = newast("param", @1.first_line, 1, newtoken("STRING_LITERAL", $1, @1.first_line)); }
    | INT_LITERAL
    { $$ = newast("param", @1.first_line, 1, newtoken("INT_LITERAL", $1, @1.first_line)); }
    | CHAR_LITERAL
    { $$ = newast("param", @1.first_line, 1, newtoken("CHAR_LITERAL", $1, @1.first_line)); }
    | ID
    { $$ = newast("param", @1.first_line, 1, newtoken("ID", $1, @1.first_line));}


compound_statement:
    '{' statement_list_opt '}'
    { $$ = newast("compound_statement", @1.first_line, 1, $2); }
    | error
    { ErrorMessage(1,"}","",yylineno) ;error_flag=1; }

statement_list_opt:
    /* empty */
    { $$=NULL; }
    |
    statement_list
    { $$ = newast("statement_list_opt", $1->line_num, 1, $1); }

statement_list:
    statement_and_declaration
     { $$ = newast("statement_list", $1->line_num, 1, $1); }
    | statement_list statement_and_declaration 
    { $$ = newast("statement_list", $1->line_num, 2, $1, $2); }

statement_and_declaration:
    var_declaration
    { $$ = newast("statement_and_declaration", $1->line_num, 1, $1); }
    |statement
    { $$ = newast("statement_and_declaration", $1->line_num, 1, $1); }
    

statement:
    expression_statement 
    { $$ = newast("statement", $1->line_num, 1, $1); }
    | compound_statement 
    { $$ = newast("statement", $1->line_num, 1, $1); }
    | selection_statement 
    { $$ = newast("statement", $1->line_num, 1, $1); }
    | iteration_statement 
    { $$ = newast("statement", $1->line_num, 1, $1); }
    | jump_statement 
    { $$ = newast("statement", $1->line_num, 1, $1); }
    | call_statement
    { $$ = newast("statement", $1->line_num, 1, $1); }
    

call_statement:
    ID '(' params ')' ';'
     { $$ = newast("call_statement", @1.first_line, 2, newtoken("ID", $1, @1.first_line), $3); }
    |ID '(' params error ';'
    { $$ = newast("call_statement", @1.first_line, 2, newtoken("ID", $1, @1.first_line), $3); 
     ErrorMessage(1,")","",$3->line_num);
     error_flag=1;
     }
    |    ID '(' params ')' error
     { $$ = newast("call_statement", @1.first_line, 2, newtoken("ID", $1, @1.first_line), $3); 
     ErrorMessage(1,";","",$3->line_num);
     error_flag=1;
     }


expression_statement:
    ';' 
    { $$ = NULL; }
    | expression ';' 
    { $$ = newast("expression_statement", $1->line_num, 1, $1); }
    | expression error
    { $$ = newast("expression_statement", $1->line_num, 1, $1);ErrorMessage(1,";","",yylineno),error_flag=1;}

expression:
    assignment_expression 
    { $$ = newast("expression", $1->line_num, 1, $1); }
    | expression ',' assignment_expression 
    { $$ = newast("expression", $1->line_num, 2, $1, $3); }

assignment_expression:
    conditional_expression 
    { $$ = newast("assignment_expression", $1->line_num, 1, $1); }
    | unary_expression assignment_operator assignment_expression 
    { $$ = newast("assignment_expression", $1->line_num, 3, $1, $2, $3); }
    | declaration_specifiers unary_expression assignment_operator assignment_expression // modify1
    { $$ = newast("assignment_expression", $1->line_num, 4, $1, $2, $3, $4); }
    | declaration_specifiers unary_expression assignment_operator '{' primary_expression_list '}'
    { $$ = newast("assignment_expression", $1->line_num, 4, $1, $2, $3, $5); }

assignment_operator:
    '='
    { 
        $$ = newast("assignment_operator", @1.first_line, 1, newtoken("ASSIGNOP", $1, @1.first_line)); 
        }

conditional_expression:
    logical_or_expression 
    { $$ = newast("conditional_expression", $1->line_num, 1, $1); }
    | logical_or_expression '?' expression ':' conditional_expression 
    { $$ = newast("conditional_expression", $1->line_num, 5, $1, newtoken("QUESTION_MARK", $2, @2.first_line), $3, newtoken("COLON", $4, @4.first_line), $5); }

logical_or_expression:
    logical_and_expression 
    { $$ = newast("logical_or_expression", $1->line_num, 1, $1); }
    | logical_or_expression OR_OP logical_and_expression 
    { $$ = newast("logical_or_expression", $1->line_num, 3, $1, newtoken("OR_OP", $2, @2.first_line), $3); }

logical_and_expression:
    inclusize_or_expression 
    { $$ = newast("logical_and_expression", $1->line_num, 1, $1); }
    | logical_and_expression AND_OP inclusize_or_expression 
    { $$ = newast("logical_and_expression", $1->line_num, 3, $1, newtoken("AND_OP", $2, @2.first_line), $3); }

inclusize_or_expression:
    exclusive_or_expression 
    { $$ = newast("inclusize_or_expression", $1->line_num, 1, $1); }
    | inclusize_or_expression '|' exclusive_or_expression 
    { $$ = newast("inclusize_or_expression", $1->line_num, 3, $1, newtoken("PIPE", $2, @2.first_line), $3); }

exclusive_or_expression:
    and_expression 
    { $$ = newast("exclusive_or_expression", $1->line_num, 1, $1); }
    | exclusive_or_expression '^' and_expression 
    { $$ = newast("exclusive_or_expression", $1->line_num, 3, $1, newtoken("CARET", $2, @2.first_line), $3); }

and_expression:
    equality_expression 
    { $$ = newast("and_expression", $1->line_num, 1, $1); }
    | and_expression '&' equality_expression 
    { $$ = newast("and_expression", $1->line_num, 3, $1, newtoken("AMPERSAND", $2, @2.first_line), $3); }

equality_expression:
    relational_expression 
    { $$ = newast("equality_expression", $1->line_num, 1, $1); }
    | equality_expression EQ_OP relational_expression 
    { $$ = newast("equality_expression", $1->line_num, 3, $1, newtoken("EQ_OP", $2, @2.first_line), $3); }
    | equality_expression NE_OP relational_expression 
    { $$ = newast("equality_expression", $1->line_num, 3, $1, newtoken("NE_OP", $2, @2.first_line), $3); }

relational_expression:
    shift_expression 
    { $$ = newast("relational_expression", $1->line_num, 1, $1); }
    | relational_expression '<' shift_expression 
    { $$ = newast("relational_expression", $1->line_num, 3, $1, newtoken("L_OP", $2, @2.first_line), $3); }
    | relational_expression '>' shift_expression 
    { $$ = newast("relational_expression", $1->line_num, 3, $1, newtoken("G_OP", $2, @2.first_line), $3); }
    | relational_expression LE_OP shift_expression 
    { $$ = newast("relational_expression", $1->line_num, 3, $1, newtoken("LE_OP", $2, @2.first_line), $3); }
    | relational_expression GE_OP shift_expression 
    { $$ = newast("relational_expression", $1->line_num, 3, $1, newtoken("GE_OP", $2, @2.first_line), $3); }

shift_expression:
    additive_expression 
    { $$ = newast("shift_expression", $1->line_num, 1, $1); }
    | shift_expression LEFT_OP additive_expression 
    { $$ = newast("shift_expression", $1->line_num, 3, $1, newtoken("LEFT_OP", $2, @2.first_line), $3); }
    | shift_expression RIGHT_OP additive_expression 
    { $$ = newast("shift_expression", $1->line_num, 3, $1, newtoken("RIGHT_OP", $2, @2.first_line), $3); }

additive_expression:
    multiplicative_expression 
    { $$ = newast("additive_expression", $1->line_num, 1, $1); }
    | additive_expression '+' multiplicative_expression 
    { $$ = newast("additive_expression", $1->line_num, 3, $1, newtoken("ADD_OP", $2, @2.first_line), $3); }
    | additive_expression '-' multiplicative_expression 
    { $$ = newast("additive_expression", $1->line_num, 3, $1,newtoken("SUB_OP", $2, @2.first_line), $3); }

multiplicative_expression:
    cast_expression 
    { $$ = newast("multiplicative_expression", $1->line_num, 1, $1); }
    | multiplicative_expression STAR_OP cast_expression 
    { $$ = newast("multiplicative_expression", $1->line_num, 3, $1, newtoken("MUL_OP", $2, @2.first_line), $3); }
    | multiplicative_expression '/' cast_expression 
    { $$ = newast("multiplicative_expression", $1->line_num, 3, $1, newtoken("DIV_OP", $2, @2.first_line), $3); }
    | multiplicative_expression '%' cast_expression 
    { $$ = newast("multiplicative_expression", $1->line_num, 3, $1, newtoken("REMAIN_OP", $2, @2.first_line), $3); }

cast_expression:
    unary_expression 
    { $$ = newast("cast_expression", $1->line_num, 1, $1); }
    | '(' TYPE ')' cast_expression 
    { $$ = newast("cast_expression", @1.first_line, 2, newtoken("TYPE", $2, @2.first_line), $4);}
    | '(' TYPE error cast_expression 
    { $$ = newast("cast_expression", @1.first_line, 2, newtoken("TYPE", $2, @2.first_line), $4);
    ErrorMessage(1,")","",yylineno);
    error_flag=1;
    }
    | error TYPE ')' cast_expression 
    { $$ = newast("cast_expression", @1.first_line, 2, newtoken("TYPE", $2, @2.first_line), $4);
    ErrorMessage(1,"(","",yylineno);
    error_flag=1;
    }

unary_expression:
    postfix_expression 
    { $$ = newast("unary_expression", $1->line_num, 1, $1); }
    | INC_OP unary_expression 
    { $$ = newast("unary_expression", @1.first_line, 2, newtoken("INC_OP", $1, @1.first_line), $2); }
    | DEC_OP unary_expression 
    { $$ = newast("unary_expression", @1.first_line, 2, newtoken("DEC_OP", $1, @1.first_line), $2); }
    | STAR_OP unary_expression 
    { $$ = newast("unary_expression", @1.first_line, 2, newtoken("STAR_OP", $1, @1.first_line), $2); }  //modify 2
    | '&' unary_expression 
    { $$ = newast("unary_expression", @1.first_line, 2, newtoken("AMPERSAND", $1, @1.first_line), $2); }  
    | '+' cast_expression 
    { $$ = newast("unary_expression", @1.first_line, 2, newtoken("ADD_OP", "+", @1.first_line), $2); }
    | '-' cast_expression 
    { $$ = newast("unary_expression", @1.first_line, 2, newtoken("MINUS_OP", "-", @1.first_line), $2); }
    | '!' cast_expression 
    { $$ = newast("unary_expression", @1.first_line, 2, newtoken("YES_OP", "!", @1.first_line), $2); }
    | '~' cast_expression 
    { $$ = newast("unary_expression", @1.first_line, 2, newtoken("NO_OP", "~", @1.first_line), $2); }
    | SIZEOF unary_expression 
    { $$ = newast("unary_expression", @1.first_line, 2, newtoken("SIZEOF", $1, @1.first_line), $2); }
    | SIZEOF TYPE 
    { $$ = newast("unary_expression", @1.first_line, 2, newtoken("SIZEOF", $1, @1.first_line), newtoken("TYPE", $2, @2.first_line)); }

postfix_expression:
    primary_expression 
    { $$ = newast("postfix_expression", $1->line_num, 1, $1); }
    | postfix_expression '[' INT_LITERAL ']'  //modify
    { $$ = newast("postfix_expression", $1->line_num, 2, $1, newtoken("INT_LITERAL", $3, @3.first_line));}
    | postfix_expression '(' argument_expression_list ')' 
    { $$ = newast("postfix_expression", $1->line_num, 2, $1, $3);}
    | postfix_expression '.' ID 
    { $$ = newast("postfix_expression", $1->line_num, 2, $1, newtoken("ID", $3, @3.first_line));}
    | postfix_expression PTR_OP ID 
    { $$ = newast("postfix_expression", $1->line_num, 3, $1, newtoken("PTR_OP", $2, @2.first_line), newtoken("ID", $3, @3.first_line)); }
    | postfix_expression INC_OP 
    { $$ = newast("postfix_expression", $1->line_num, 2, $1, newtoken("INC_OP", $2, @2.first_line)); }
    | postfix_expression DEC_OP 
    { $$ = newast("postfix_expression", $1->line_num, 2, $1, newtoken("DEC_OP", $2, @2.first_line)); }

primary_expression:
    ID 
    { $$ = newast("primary_expression", @1.first_line, 1, newtoken("ID", $1, @1.first_line));}
    | INT_LITERAL 
    { $$ = newast("primary_expression", @1.first_line, 1, newtoken("INT_LITERAL", $1, @1.first_line)); }
    | FLOAT_LITERAL 
    { $$ = newast("primary_expression", @1.first_line, 1, newtoken("FLOAT_LITERAL", $1, @1.first_line)); }
    | CHAR_LITERAL 
    { $$ = newast("primary_expression", @1.first_line, 1, newtoken("CHAR_LITERAL", $1, @1.first_line)); }
    | STRING_LITERAL 
    { $$ = newast("primary_expression", @1.first_line, 1, newtoken("STRING_LITERAL", $1, @1.first_line)); }
    | '(' expression ')' 
    { $$ = newast("primary_expression", @1.first_line, 1, $2); }

primary_expression_list:
    primary_expression
    { $$ = newast("primary_expression_list", $1->line_num, 1, $1); }
    | primary_expression_list ',' primary_expression
    { $$ = newast("primary_expression_list", $1->line_num, 2, $1, $3); }

argument_expression_list:
    assignment_expression 
    { $$ = newast("argument_expression_list", $1->line_num, 1, $1); }
    | argument_expression_list ',' assignment_expression 
    { $$ = newast("argument_expression_list", $1->line_num, 2, $1, $3); }


selection_statement:
    IF '(' expression ')' compound_statement 
    { $$ = newast("selection_statement", @1.first_line, 3, newtoken("IF", $1, @1.first_line), $3, $5); }
    | IF '(' expression ')' compound_statement else_statement 
    { $$ = newast("selection_statement", @1.first_line, 4, newtoken("IF", $1, @1.first_line), $3, $5, $6); }
    |    IF error expression ')' compound_statement 
    { $$ = newast("selection_statement", @1.first_line, 3, newtoken("IF", $1, @1.first_line), $3, $5); 
    ErrorMessage(1,"(","", @1.first_line);
    error_flag=1;
    }
    |    IF '(' expression error compound_statement 
    { $$ = newast("selection_statement", @1.first_line, 3, newtoken("IF", $1, @1.first_line), $3, $5); 
    ErrorMessage(1,")","", @1.first_line);
    error_flag=1;
    }
    | IF error expression ')' compound_statement else_statement 
    { $$ = newast("selection_statement", @1.first_line, 4, newtoken("IF", $1, @1.first_line), $3, $5, $6); 
    ErrorMessage(1,"(","", @1.first_line);
    error_flag=1;
    }
    | IF '(' expression error compound_statement else_statement 
    { $$ = newast("selection_statement", @1.first_line, 4, newtoken("IF", $1, @1.first_line), $3, $5, $6); 
    ErrorMessage(1,")","", @1.first_line);
    error_flag=1;
    }
    
else_statement:
    ELSE compound_statement
    { $$ = newast("else_statement", @1.first_line, 2, newtoken("ELSE", $1, @1.first_line), $2); }
    | ELSE IF '(' expression ')' compound_statement else_statement
    { $$ = newast("else_statement", @1.first_line, 5, newtoken("ELSE", $1, @1.first_line), newtoken("IF", $2, @2.first_line), $4, $6, $7); }
    | ELSE IF error expression ')' compound_statement else_statement
    { $$ = newast("else_statement", @1.first_line, 5, newtoken("ELSE", $1, @1.first_line), newtoken("IF", $2, @2.first_line), $4, $6, $7);
    ErrorMessage(1,"(","", @4.first_line);
    error_flag=1;
     }
    | ELSE IF '(' expression error compound_statement else_statement
    { $$ = newast("else_statement", @1.first_line, 5, newtoken("ELSE", $1, @1.first_line), newtoken("IF", $2, @2.first_line), $4, $6, $7); 
    ErrorMessage(1,")","", @4.first_line);
    error_flag=1;
    }

iteration_statement:
    WHILE '(' expression ')' statement 
    { $$ = newast("iteration_statement", @1.first_line, 3, newtoken("WHILE", $1, @1.first_line), $3, $5); }
    | FOR '(' expression_statement expression_statement expression ')' statement 
    { $$ = newast("iteration_statement", @1.first_line, 5, newtoken("FOR", $1, @1.first_line), $3, $4, $5, $7); }
    | FOR '(' var_declaration expression_statement expression ')' statement 
    { $$ = newast("iteration_statement", @1.first_line, 5, newtoken("FOR", $1, @1.first_line), $3, $4, $5, $7); }
    | WHILE error expression ')' statement
    {$$ = newast("iteration_statement", @1.first_line, 3, newtoken("WHILE", $1, @1.first_line), $3, $5); 
    ErrorMessage(1,"(","",$3->line_num);
    error_flag=1;}
    | WHILE '(' expression error statement
    {$$ = newast("iteration_statement", @1.first_line, 3, newtoken("WHILE", $1, @1.first_line), $3, $5); 
    ErrorMessage(1,")","",$3->line_num);
    error_flag=1;}
    
    | FOR error expression_statement expression_statement expression ')' statement 
    { $$ = newast("iteration_statement", @1.first_line, 5, newtoken("FOR", $1, @1.first_line), $3, $4, $5, $7); 
    ErrorMessage(1,"(","",$3->line_num);
    error_flag=1;
    }
    | FOR '('expression_statement expression_statement expression error statement 
    { $$ = newast("iteration_statement", @1.first_line, 5, newtoken("FOR", $1, @1.first_line), $3, $4, $5, $7); 
    ErrorMessage(1,")","",$3->line_num);
    error_flag=1;
    }
    | FOR error var_declaration expression_statement expression ')' statement 
    { $$ = newast("iteration_statement", @1.first_line, 5, newtoken("FOR", $1, @1.first_line), $3, $4, $5, $7);
    ErrorMessage(1,"(","",$3->line_num);
    error_flag=1;
     }
    | FOR '(' var_declaration expression_statement expression error statement 
    { $$ = newast("iteration_statement", @1.first_line, 5, newtoken("FOR", $1, @1.first_line), $3, $4, $5, $7);
    ErrorMessage(1,")","",$3->line_num);
    error_flag=1;
     }

jump_statement:
    GOTO ID  ';' 
    { $$ = newast("jump_statement", @1.first_line, 2, newtoken("GOTO", $1, @1.first_line), newtoken("ID", $2, @2.first_line)); }
    |GOTO ID  error
    { $$ = newast("jump_statement", @1.first_line, 2, newtoken("GOTO", $1, @1.first_line), newtoken("ID", $2, @2.first_line));
    ErrorMessage(1,";","",yylineno);
    error_flag=1;
     }
    | CONTINUE ';' 
    { $$ = newast("jump_statement", @1.first_line, 1, newtoken("CONTINUE", $1, @1.first_line)); }
    | CONTINUE error
    { $$ = newast("jump_statement", @1.first_line, 1, newtoken("CONTINUE", $1, @1.first_line));
    ErrorMessage(1,";","",@1.first_line);
    error_flag=1;
     }
    | BREAK ';' 
    { $$ = newast("jump_statement", @1.first_line, 1, newtoken("BREAK", $1, @1.first_line)); }
    | BREAK error 
    { $$ = newast("jump_statement", @1.first_line, 1, newtoken("BREAK", $1, @1.first_line));
    ErrorMessage(1,";","",@1.first_line);
    error_flag=1;
     }
    | RETURN ';' 
    { $$ = newast("jump_statement", @1.first_line, 1, newtoken("RETURN", $1, @1.first_line)); }
    | RETURN error 
    { $$ = newast("jump_statement", @1.first_line, 1, newtoken("RETURN", $1, @1.first_line));
    ErrorMessage(1,";","",@1.first_line);
    error_flag=1;   
    }
    | RETURN expression ';' 
    { $$ = newast("jump_statement", @1.first_line, 2, newtoken("RETURN", $1, @1.first_line), $2); }
    | RETURN expression error 
    { $$ = newast("jump_statement", @1.first_line, 2, newtoken("RETURN", $1, @1.first_line), $2);
    ErrorMessage(1,";","",@1.first_line);
    error_flag=1;
    }

%%




