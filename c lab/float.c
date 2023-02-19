#include <stdio.h>
void main()
{

    float fa,fb;

    //code for reading data from console / User input
    printf("Enter two float values\n");
    scanf("%f%f",&fa,&fb);
    //addition
    printf("Sum of %0.2f and %0.2f is %0.2f\n",fa,fb,(fa+fb));
    //subtraction
    printf("The subtraction of %0.2f and %0.2f is %0.2f\n",fa,fb, fa-fb);
    //multiplication
    printf("The multiplication of %0.2f and %0.2f is %0.2f\n",fa,fb, fa * fb);
    // division
    printf("The division of %0.2f and %0.2f is %0.2f\n",fa,fb, fa/fb);
}