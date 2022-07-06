/*Este algoritmo visa aplicar os conceitos de ordenacao de vetor com 5 valores apartir de
*2 lacos de repeticao comparativos entre si ordenando somente um vetor de forma crescente.
*/

#include<stdio.h>

int main(){
    int a[5],i,j,aux;
    //Inicializamos um vetor de 5 valores, 2 variaveis indices, e uma variavel auxiliar.
    for(i=0;i<5;i++){
        scanf("%d",&a[i]);
        //Atribuimos valores nas 5 posicoes do vetor.
    }
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){//Criamos um for dentro do outro, o for com o indice i e j.
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
        //Aqui exibimos na tela o vetor ja ordenado de forma crescente.
    }
    return 0;
}
