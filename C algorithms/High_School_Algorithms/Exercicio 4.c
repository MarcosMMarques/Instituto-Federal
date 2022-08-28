#include<stdio.h>
int main(){
	int n1,n2,n3,n4,m;
	printf("Escreva as 4 notas bimestrais: ");
	scanf("%d",&n1);
		scanf("%d",&n2);
		scanf("%d",&n3);
		scanf("%d",&n4);
		m=(n1+n2+n3+n4)/4;
	printf("media: %d",m);
	return 0;
}
