#include<stdio.h>
int main(){
	int qh;
	float vp;
	float s;
	printf("Escreva o valor que paga por horas trabalhadas ");
	scanf("%f",&vp);
		printf("Escreva quantas horas vc trabalho neste mes ");
		scanf("%d",&qh);
		s=vp*qh;
	printf("O seu salario deste mes foi: %f",s);
	return 0;
}
