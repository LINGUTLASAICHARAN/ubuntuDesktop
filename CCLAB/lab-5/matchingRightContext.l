%%
a+/b { printf("T_AB : %s  ",yytext);}
a+/c { printf("T_AC : %s  ",yytext);}
b {printf("T_B : %s  ",yytext);}
c {printf("T_C : %s  ",yytext);}
. ECHO;
\n return 1;
%%

int main (){
    yylex();

}

/* input ab */