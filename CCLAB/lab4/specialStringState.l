%{
#include<stdio.h>
char buf[100];
char * s;
%}
%x STRING
%%
\" {BEGIN STRING; s = buf;}
<STRING>\\n {*s++ = '\n';}
<STRING>\\t {*s++ = '\t';}
<STRING>\\\" {*s++ = '\"';}
<STRING>\" {*s = 0;  BEGIN 0;
printf("found %s\n",buf);}
<STRING>\n {printf("invalid String");exit(1);}
<STRING>. {*s++ = *yytext;}
%%
