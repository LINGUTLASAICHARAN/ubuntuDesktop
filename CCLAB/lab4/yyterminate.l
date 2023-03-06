%{
#include<stdio.h>
%}
%%
[a-z]+ {printf("lower case  --- ");
ECHO;
printf("\nbegin yyterminate\n");
yyterminate();
printf("end yyterminate");
}
[a-zA-Z]+ {printf("Mixed case\n");ECHO;}

%%
int main(){

yylex();
printf("closing Bye...\n");

}

