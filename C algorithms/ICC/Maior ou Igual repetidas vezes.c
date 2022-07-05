#include<stdio.h>
#include<ctype.h>
int main(){
  int n,i;
  scanf("%d",&n);//A quantidade de vezes que o usuario quer comparar 2 numeros.
  n=n*2;//Se ele quiser repetir 2 vezes o procedimentos, entao sera 4 numeros a serem processados.
  int v[n];//Inicializamos um vetor de tamanho n apos ser dobrado.
  for(i=0;i<n;i=i+2){//O indice do for pulara de dois em dois, pois sao 2 numeros a serem comparados.
      scanf("%d%d",&v[i],&v[i+1]);
      //Scaneamos os valores
      if(v[i]>v[i+1]){//Caso haja um maior entre eles, verificamos se o primeiro e maior que o segundo.
          printf("Maior entre %d e %d : %d\n",v[i],v[i+1],v[i]);
      }else if(v[i]==v[i+1]){//Caso nao, verificamos se eles são iguais.
          printf("Iguais\n");
      }else{//Se todas as condições atras forem falsas, entao o segundo e maior.
          printf("Maior entre %d e %d : %d\n",v[i],v[i+1],v[i+1]);
      }
  }
  return 0;
}
