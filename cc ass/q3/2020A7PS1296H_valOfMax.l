%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int count = 0;

char input_date[10];


int maxval = 0;





%}



%%


"//".* {}


$[" "]*[A-Z][A-Z0-9]*[^$"\n"]* {

char temp_id[50];
int temp_sum = 0;
    
char *p;


    if(yytext[1] != ' '){
        p = strtok(yytext, " "); // capture id
        // printf("%s-----",p);

    }
    else{
        p = strtok(yytext, " ");
        p = strtok(NULL, " ");

        // printf("%s-----",p);

    }



 
    p = strtok(NULL, " ");
    while (p != NULL)
    {
        int check = 0;
        if(strcmp(p,input_date) == 0){ // check date
            check = 1;
        }


        char temp[10];
        int i,j;
        // strncpy(temp,p,2);
        for( i = 0 ,  j= 0 ; p[j] != '/'; i++,j++){
            temp[i] = p[j];
        }
        temp[i] = '\0';
        int day = atoi(temp);


        // strncpy(temp,p+3,2);

        for( i = 0 ,  j= 3 ; i < 2; i++,j++){
            temp[i] = p[j];
        }
        temp[2] = '\0';
        int month = atoi(temp);

        // printf("\n%s--\n",p);
        if(day > 30 || month > 12){
            printf("\n----invalid date----\n");
            printf("\n%d / %d\n",day,month);
            exit(0);
        }
        

        p = strtok(NULL, " ");
        if( check==1){
            count++;
            if(maxval < atoi(p)){
                maxval = atoi(p);
            }
        }

        p = strtok(NULL, " ");
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
printf("maximum value = %d\n",maxval );
printf("count = %d\n",count);


FILE * o = fopen("output.txt","w");

if(maxval == 0){
    fprintf(o,"$%d$%d#",count,maxval);
}
    else
    fprintf(o,"$%d$%d#",count,maxval);
}