#include <stdio.h>
#include <string.h>
# include<stdlib.h>
int main()
{

    char str[] = "$ABC123     05/03 100;        03/02    200; 05/02 500;";
    char temp_id[50];


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


    printf("%s",temp_id);
    



    // char date[] = "05/02";
    // char  id[50];
    // int val = 0;
    // int count = 0;
    // char * p;

    // if(str[1] ==' '){
    //     p = strtok(str, " ");
    //     p = strtok(NULL, " ");
    //     id[0]='$';
    //     int i ,j = 0;
    //     for(i = 1 ; p[j] != '\0';i++,j++){
    //         id[i] = p[j];
    //     }
    //     id[i+1] = '\0';
    //     printf("%s---------",p);
    //     printf("%d",(int )strlen(p));
    // }
    // else{
    //     p = strtok(str, " ");
    //     for(int i = 0 ; p[i] != '\0';i++){
    //         id[i] = p[i];
    //     }
    //     printf("%d",(int)strlen(p));
    //     printf("%s---------",p);
    // }
    


    // p = strtok(NULL, " ");
    // while (p != NULL)
    // {
    //     int i = 0;
    //     // printf("%s  --",p);
    //     if(strcmp(p,date) == 0){
    //         i = 1;
    //     }
        
    //     p = strtok(NULL, " ");
    //     // printf("%s--\n",p);
    //     if( i==1){
    //         count++;
    //         val += atoi(p);
    //     }

    //     p = strtok(NULL, " ");
    // }
    // // printf("%s---",id);

   
}