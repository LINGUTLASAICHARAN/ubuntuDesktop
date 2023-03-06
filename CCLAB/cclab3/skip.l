%{
#include<stdio.h>
%}
%%
[a-zA-Z\t][a-zA-Z]* printf("%s",yytext);
[0-9]* 
[?%$#] {}
%%
int main(){
	yyin = fopen("input.txt","r");
	
	yylex();
}
