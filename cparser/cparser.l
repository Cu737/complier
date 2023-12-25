%option noyywrap nodefault yylineno
%{
	
    #include "cparser.h"
    #include "cparser.tab.h"
	#define YY_USER_ACTION yylloc.first_line = yylloc.last_line = yylineno;
%}

%{
int IDcount=0;//IDcount
char map[100][100];//符号表
int scope[100];
int now_scope = 1;
int next=0;
int outputtedIdentifiers[100] = {0};



%}


white [\t\n ]+
digit [0-9]
letter [A-Za-z]
str \"[^"]*\"
char    '[^']'
head "#include"<[^"]*.h>
shortcomment "//"(.*)|\n
float_number [1-9]{digit}*"."{digit}*
id ({letter}|_)({letter}|{digit}|_)*
number [1-9]{digit}*|0
commentbegin "/*"
commentelement .|\n
commentend "*/"
%x COMMENT
%%
{commentbegin} {BEGIN COMMENT;}
<COMMENT>{commentelement} {}
<COMMENT>{commentend} {BEGIN INITIAL;}
{white} ;
{number} {yylval.c = strdup(yytext); return INT_LITERAL;}
{float_number} {yylval.c = strdup(yytext); return FLOAT_LITERAL;}
"void*" {yylval.c = strdup(yytext); next = 1; return TYPE;}
"char*" {yylval.c = strdup(yytext); next = 1; return TYPE;}
"int*"  {yylval.c = strdup(yytext); next = 1; return TYPE;}
"float*"  {yylval.c = strdup(yytext); next = 1; return TYPE;}
"void" {yylval.c = strdup(yytext); next = 1; return TYPE;}
"char" {yylval.c = strdup(yytext); next = 1; return TYPE;}
"int"  {yylval.c = strdup(yytext); next = 1; return TYPE;}
"float"  {yylval.c = strdup(yytext); next = 1; return TYPE;}
"bool"  {yylval.c = strdup(yytext); next = 1; return TYPE;}
"true"  {yylval.c = strdup(yytext); next = 1; return TRUE;}
"false"  {yylval.c = strdup(yytext); next = 1; return FALSE;}
"sizeof" {yylval.c = strdup(yytext); return SIZEOF;}
"const" {yylval.c = strdup(yytext); return CONST;}
"return" {yylval.c = strdup(yytext); return RETURN;}
"continue" {yylval.c = strdup(yytext); return CONTINUE;}
"break" {yylval.c = strdup(yytext); return BREAK;}
"if" {yylval.c = strdup(yytext); return IF;}
"else" {yylval.c = strdup(yytext); return ELSE;}
"switch" {yylval.c = strdup(yytext); return SWITCH;}
"case" {yylval.c = strdup(yytext); return CASE;}
"default" {yylval.c = strdup(yytext); return DEFAULT;}
"for" {yylval.c = strdup(yytext); return FOR;}
"do" {yylval.c = strdup(yytext); return DO;}
"while" {yylval.c = strdup(yytext); return WHILE;}
{char}  {yylval.c = strdup(yytext); return CHAR_LITERAL;}
{str}  {yylval.c = strdup(yytext); return STRING_LITERAL;}
{head}  {yylval.c = strdup(yytext);}
{shortcomment} {}
{id} {
	int flag = 0;
	int i = 0;
	int old_ID=-1;
	for(i=IDcount-1;i>=0;i--){
		if(strcmp(yytext,map[i])==0){
			old_ID = i+1;
			if(scope[old_ID-1] ==-1){
				old_ID = -1;
				continue;
			}
			flag=1;break;
		}
	}
	if(next == 1){
		if(flag==1&&old_ID !=-1&&scope[old_ID-1] == now_scope)
		{//fprintf(yyout,"too many times declarations!\n");
		}
		else{
			IDcount++;
			strcpy(map[IDcount-1],yytext);
			scope[IDcount-1] = now_scope;
			// fprintf(yyout,"ID %s %d\n",yytext,(IDcount-1)*4+70);
		}
	}
	else{
		if(old_ID == -1) { //fprintf(yyout,"have not been declared!\n");
		}
		else {
				if (outputtedIdentifiers[old_ID - 1] == 0) {
                fprintf(yyout, "ID %s %d\n", yytext, (old_ID - 1) * 4 + 70);
                // 标记标识符已输出
                outputtedIdentifiers[old_ID - 1] = 1;
				}
			}
	}
	yylval.c = strdup(yytext);
	return ID;
}

"{" {
	now_scope ++;
	if(next ==1) next--;
	yylval.c = strdup(yytext); return '{';
	}
	

"}" {    
	now_scope --;
	for(int i=IDcount-1;i>=0;i--){
		if(scope[i] > now_scope){
			scope[i] = -1;
		}
	}
	yylval.c = strdup(yytext); return '}';
	}

"[" {if(next == 1) next--; yylval.c = strdup(yytext); return '[';}
"]" {if(next == 1) next--; yylval.c = strdup(yytext); return ']';}
"(" {yylval.c = strdup(yytext); return '(';}
")" {yylval.c = strdup(yytext); return ')';}
"~" {yylval.c = strdup(yytext); return '~';}
"++" {yylval.c = strdup(yytext); return INC_OP;}
"--" {yylval.c = strdup(yytext); return DEC_OP;}
"!" {yylval.c = strdup(yytext); return '!';}
"*" {yylval.c = strdup(yytext); return STAR_OP;}
"/" {yylval.c = strdup(yytext); return '/';}
"%" {yylval.c = strdup(yytext); return '%';}
"+" {yylval.c = strdup(yytext); return '+';}
"-" {yylval.c = strdup(yytext); return '-';}
">" {yylval.c = strdup(yytext); return '>';}
"<" {yylval.c = strdup(yytext); return '<';}
">=" {yylval.c = strdup(yytext); return GE_OP;}
"<=" {yylval.c = strdup(yytext); return LE_OP;}
"<<" {yylval.c = strdup(yytext); return LEFT_OP;}
">>" {yylval.c = strdup(yytext); return RIGHT_OP;}
"==" {if(next == 1) next--; yylval.c = strdup(yytext); return EQ_OP;}
"!=" {yylval.c = strdup(yytext); return NE_OP;}
"&&" {yylval.c = strdup(yytext); return AND_OP;}
"||" {yylval.c = strdup(yytext); return OR_OP;}
"=" {if(next == 1) next--; yylval.c = strdup(yytext); return '=';}
"/=" {yylval.c = strdup(yytext); return ASSIGNDIV;}
"*=" {yylval.c = strdup(yytext); return ASSIGNSTAR;}
"%=" {yylval.c = strdup(yytext); return ASSIGNCOM;}
"+=" {yylval.c = strdup(yytext); return ASSIGNPLUS;}
"-=" {yylval.c = strdup(yytext); return ASSIGNMINUS;}
"," {yylval.c = strdup(yytext); return ',';}
"#" {yylval.c = strdup(yytext); return '#';}
";" {yylval.c = strdup(yytext); if(next == 1) next--; return ';';}
":" {yylval.c = strdup(yytext); return ':';}
"&" {yylval.c = strdup(yytext); return '&';}
"|" {yylval.c = strdup(yytext); return '|';}
"?" {yylval.c = strdup(yytext); return '?';}
"^" {yylval.c = strdup(yytext); return '^';}
"->" {yylval.c = strdup(yytext); return PTR_OP;}
"." {yylval.c = strdup(yytext); return '.';}
. { yyerror("Mystery character %c\n",*yytext); error_flag=1;}
%%