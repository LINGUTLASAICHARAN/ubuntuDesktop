%{
#include <stdio.h>

int m = 0;
%}

%s PRI

%%
"printf" {BEGIN PRI;}
<PRI>

%%

int main (){
    yyin = fopen("input.c","r");
    yyout = fopen("output.txt","w");
    yylex();
    return 0;
}