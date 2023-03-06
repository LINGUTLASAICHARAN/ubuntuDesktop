%%
"un" {printf("\nThe unput charactrr is = ");
ECHO;
}
[a-z]+ {printf("lower case token is = ");
ECHO;
unput('n');
unput('u');
printf("\nThe token after unput is  =  ");
ECHO;}
[a-zA-Z]+ {printf("\n Mixed Token is =" );
ECHO;
}
%%