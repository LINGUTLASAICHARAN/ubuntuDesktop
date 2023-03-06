%{
#include<stdio.h>
int npink = 0, npin = 0,nink=0;
%}
%%
pink {npink ++;printf("pink fired\n");REJECT;}
pin  {npin ++;printf("pin fired\n");REJECT;}
ink {nink ++;printf("ink fired\n");REJECT;}
begin |
beginning {printf("%s\n",yytext);REJECT;}
. printf("xx%c",*yytext);
\n return 0;
%%
int main(){
	
	yylex();
	//printf("\npink %d\n",npink);
	//printf("ink %d\n",nink);
	//printf("pin %d\n",npin);
	
}
