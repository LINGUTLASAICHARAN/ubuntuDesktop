/* LEX code to replace a word with another
taking input from file */

/* Definition section */
/* character array line can be
accessed inside rule section and main() */

%{
#include<stdio.h>
#include<string.h>
char line[100];

%}

/* Rule Section */
/* Rule 1 writes the string stored in line
character array to file output.txt */
/* Rule 2 copies the matched token
i.e every character except newline character
	to line character array */

%%
['\n'] { fprintf(yyout,"%s\n",line);}
(.*)	 { strcpy(line,yytext); line[0] = '\0'; }
<<EOF>> { fprintf(yyout,"%s",line); return 0;}
%%


int yywrap()
{
	return 1;
}

/* code section */
int main()
{
		extern FILE *yyin, *yyout;
		/* open the source file
		in read mode */
	yyin=fopen("input.txt","r");

		
		/* open the output file
		in write mode */
	yyout=fopen("output.txt","w");
	yylex();
}

