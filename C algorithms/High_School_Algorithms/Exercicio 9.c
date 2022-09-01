#include<stdio.h>
int main(){
	float f,c;
	printf("Escreva a temperatura em fahrenheit ");
	scanf("%f",&f);
		c=(5*(f-32)/9);
	printf("Celsius: %f",c);
	return 0;
}
