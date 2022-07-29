/*Este algoritmo visa aplicar os conceitos de ordenacao de vetor com 5 valores apartir de
*2 lacos de repeticao comparativos entre si ordenando somente um vetor de forma crescente.
*/

#include<stdio.h>

int main(){
    int a[5],i,j,aux;
    for(i=0;i<5;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
           if(a[i]<a[j]){
            //Quando o vetor na posicao j for maior do que o vetor na posicao i,sera feito uma troca desse valores.
              aux=a[i];//Com a ajuda da variavel auxiliar, para que nao sobrescreva o valor de a[i], e perca esse dado.
              a[i]=a[j];
              a[j]=aux;
          }
        }
    }
    for(i=0;i<5;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
