#include<stdio.h>
int main(){
	float f,c;
	printf("Escreva a temperatura em celsius: ");
	scanf("%f",&c);
		f=(c*9/5)+32;
	printf("Fahrenheit: %f",f);
	return 0;
}
