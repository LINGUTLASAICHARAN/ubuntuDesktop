%{
#include<stdio.h>
%}
%%
[a-z]+ {printf("lower case token =  ");
ECHO; return 0;
printf("\nbegin yyterminate\n");
}
[a-zA-Z]+ {printf("Mixed case\n");ECHO;}

%%
int main(){

yylex();
printf("yylex ended\n");
FILE * fp;
fp = fopen("input.txt","r");
printf("yylex again\n");
yyrestart(fp);
yylex();
printf("\nend of second call\n");

}

