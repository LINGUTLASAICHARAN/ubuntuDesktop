%{
#include <math.h>
%}
%s expect
%%
expect-floats BEGIN(expect);
<expect>[0-9]+"."[0-9]+ {
    printf("found a float, = %f\n",atof(yytext));
}
<expect>\n {
    BEGIN(INITIAL);
}
[0-9]+ {
    printf("integer found = %d\n",atoi(yytext));
}
"." printf("dot found\n");
%%