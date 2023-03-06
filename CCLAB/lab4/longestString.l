%{
#include<stdio.h>
#include <string.h>
int length = -1;
char ans[1000];
%}
%%

[a-zA-Z]+ {
	if(yyleng > length){
	length = yyleng;
	strcpy(ans,yytext);
	}
}

%%
int main(){
	yylex();
	printf("%s\n",ans);
}
