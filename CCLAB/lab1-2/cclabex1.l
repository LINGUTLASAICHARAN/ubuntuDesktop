%{
#include<stdio.h>
int i =0;
%}
letter [a][b]*
digit[0-9]
%%
{letter} { printf("pattern matched  , %s , lenght %d\n",yytext,yyleng); i=1;}

%%
int main(){
yylex();
if(i ==1){printf("accepted\n");}
}
