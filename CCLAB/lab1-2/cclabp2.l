%{
#include<stdio.h>
int i =0;
%}
letter [a-zA-Z]*
digit[0-9]
%%
{letter} + printf("String of Alphabets  , %s , lenght %d\n",yytext,yyleng);
{digit} + printf("Number  , %s , %d\n",yytext,yyleng);
%%
int main(){
yylex();
int f;
}
