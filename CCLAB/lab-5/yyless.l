%%
foobar {ECHO; yyless(3);}
[a-z]+ ECHO;
%%

/* input foobar */

/* try with yyless(0) */