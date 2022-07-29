#include<stdio.h>
#include<ctype.h>
int main(){
  int n,i;
  scanf("%d",&n);
  n=n*2;//Se ele quiser repetir 2 vezes o procedimentos, entao sera 4 numeros a serem processados.
  int v[n];.
  for(i=0;i<n;i=i+2){//O indice do for pulara de dois em dois, pois sao 2 numeros a serem comparados.
      scanf("%d%d",&v[i],&v[i+1]);
      if(v[i]>v[i+1]){
          printf("Maior entre %d e %d : %d\n",v[i],v[i+1],v[i]);
      }else if(v[i]==v[i+1]){
          printf("Iguais\n");
      }else{
          printf("Maior entre %d e %d : %d\n",v[i],v[i+1],v[i+1]);
      }
  }
  return 0;
}

