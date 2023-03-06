%{
#include<stdio.h>
int words = 0, numbers = 0;
%}
%%
[a-zA-Z]* {words++;}
[0-9]* {numbers++;}
[?%$#] {}
[\n] return 0;
%%
int main(){
	yyin = fopen("input.txt","r");
	
	yylex();
	printf("words = %d nums = %d\n",words,numbers);
}
