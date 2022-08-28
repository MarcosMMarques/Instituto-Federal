#include<stdio.h>
int main(){
	int r;
	float a;
	printf("Informe o Raio do circulo");
	scanf("%d",&r);
	a=3.14*(r*r);
	printf("Area do circulo: %.2f",a);
	return 0;
}
