#include <stdio.h>

int main()
{
    char name[20];
    char ID[20];
    char gender;
    int m1, m2, m3;
    
    printf("Enter your gender\n");
    scanf("%c", &gender);
    
    printf("Enter your name\n");
    scanf("%s", name);
    
    printf("Enter your ID\n");
    scanf("%s", ID);
    
    printf("Enter marks in three subjects\n");
    scanf("%d %d %d", &m1, &m2, &m3);
    
    printf("        Student Mark Statement\n\n");
    printf("Name        :       ");
    printf("%s\n", name);
    printf("ID          :       ");
    printf("%s\n", ID);
    printf("Gender      :       ");
    printf("%c\n", gender);
    printf("Subject(1)  :       ");
    printf("%d\n", m1);
    printf("Subject(2)  :       ");
    printf("%d\n", m2);
    printf("Subject(3)  :       ");
    printf("%d\n", m3);
    printf("Total       :       ");
    printf("%d\n", m1+m1+m3);
    printf("Average     :       ");
    printf("%0.2f\n",((float)m1+(float)m2+(float)m3)/3 );
    
    return 0;
}