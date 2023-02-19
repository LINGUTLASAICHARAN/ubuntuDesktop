#include <stdio.h>

int main(){
	int a, b;
	printf("Enter the first number\n");
	scanf("%d", &a);
	printf("Enter the second number\n");
	scanf("%d", &b);
	int greater;
	if(a > b){
		printf("a is greater than b\n");
		greater = a;
	}
	else{
		printf("b is greater than a\n");
		greater = b;
	}
	printf("Larger among the %d and %d is %d\n", a, b, greater);
	return 0;
}