%{
#include<stdio.h>
int i =0;
%}
letter [a][b]*
dot .


%%
{letter} { printf("pattern matched  , %s , lenght %d\n",yytext,yyleng);

 i=1;}
. + printf("hello dot \n");

%%
int main(){
yylex();
if(i ==1){printf("accepted\n");}
printf("in main again\n");
}
