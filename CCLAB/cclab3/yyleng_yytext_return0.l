%%
[a-z]+ {
printf("lower case %s of length %d \n",yytext,yyleng);
return 0;
}
[0-9]+ {
printf("digits %s  of length %d \n",yytext,yyleng);
return 0;
}
%%
