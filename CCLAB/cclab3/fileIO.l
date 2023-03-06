%{
#include<stdio.h>
%}
%%
[a-z]+ {
fprintf(yyout,"lower case %s of length %d \n",yytext,yyleng);
return 0;
}
[0-9]+ {
fprintf(yyout,"digits %s  of length %d \n",yytext,yyleng);
return 0;
}
%%
int main(){
	yyin = fopen("input.txt","r");
	yyout = fopen("output.txt","w");
	yylex();
}
