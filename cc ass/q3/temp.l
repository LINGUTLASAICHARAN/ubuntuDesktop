%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int count = 0;

char input_date[10];

char id[20];

int maxval = 0;





%}



%%


"//".* {}


$[" "]*[A-Z][A-Z0-9]*[^$"\n"]* {

char temp_id[50];
int temp_sum = 0;
    
char *p = strtok(yytext, " "); // capture id

int  i;
for( i = 0 ; p[i] != '\0';i++){ // copy id
           temp_id[i] = p[i];
}
temp_id[i+1] = '\0';



    // printf("\n%s--\n",temp_id);
    p = strtok(NULL, " ");
    while (p != NULL)
    {
        int i = 0;
        if(strcmp(p,input_date) == 0){ // check date
            i = 1;
        }
        
        p = strtok(NULL, " ");
        if( i==1){
            count++;
            temp_sum += atoi(p); // add to tempsum
        }

        p = strtok(NULL, " ");
    }
    if(temp_sum > maxval){
        maxval = temp_sum;
        int i ;
        for( i = 0 ; temp_id[i] != '\0';i++){ // copy id
           id[i] = temp_id[i];
        }
        id[i+1] = '\0';
    }



}



%%

int main(int argc, char** argv) {
    FILE* data_file = fopen("data.txt", "r");
    FILE* input_file = fopen("input.txt", "r");
    fscanf(input_file, "%s", input_date);
    fclose(input_file);
    FILE* output_file = fopen("output.txt", "w");
    yyin = data_file;
    yylex();
printf("%s\n",id );
printf("%d\n",count);
FILE * o = fopen("output.txt","w");
fprintf(o,"$%d%s#",count,id);
}