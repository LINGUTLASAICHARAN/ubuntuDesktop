%{
#include <stdio.h>

int m = 0;
%}

%s COMMENT

%%
"/*" {BEGIN COMMENT;}
<COMMENT>(.|[\n]) {}
<COMMENT>"*/" {BEGIN(INITIAL); }
%%

int main (){
    yyin = fopen("input.c","r");
    yyout = fopen("output.txt","w");
    yylex();
    return 0;
}

/* need input.txt */