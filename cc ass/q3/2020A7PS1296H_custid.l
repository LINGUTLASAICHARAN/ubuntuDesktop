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
    
char *p;
    char * str = yytext;
    int i = 0;
    while (!((str[i] <= 90 && str[i] >= 65) || (str[i] <= 57 && str[i] >= 48)))
    {
        i++;
    }
     temp_id[0] = '$';
    int j = 1;
    while (((str[i] <= 90 && str[i] >= 65) || (str[i] <= 57 && str[i] >= 48)))
    {
        temp_id[j] = str[i];
        i++;
        j++;
    }
    temp_id[j] = '\0';


    printf("%s---------",temp_id);


    if(yytext[1] != ' '){
        p = strtok(yytext, " "); // capture id        
    }
    else{
        p = strtok(yytext, " ");
        p = strtok(NULL, " ");
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
            // temp_sum += atoi(p); // add to tempsum
            if(atoi(p) > maxval){
                maxval = atoi(p);
                // strcpy(temp_id,id);
                        int i ;
                for( i = 0 ; temp_id[i] != '\0';i++){ // copy id
                          id[i] = temp_id[i];
                    }
                id[i] = '\0';
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
printf("%s\n",id );
printf("%d\n",count);
printf("%d\n",maxval);
FILE * o = fopen("output.txt","w");
fprintf(o,"$%d%s#",count,id);
}