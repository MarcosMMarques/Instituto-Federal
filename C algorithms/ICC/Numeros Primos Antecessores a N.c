//Neste algoritmo sera escrito todos os numeros primos existentes anteriores em relacao numero recebido pelo usuario.
#include<stdio.h>

int main(){
  int i,num,j,resposta=1;
  scanf("%d",&num);
  for(i=2;i<num;i++){
  //Criamos um for que vai verificar do numero 2(O primeiro primo) até o antecesso do numero dado pelo usuario.
    for(j=2;j<=i/2;j++){
    /*A cada verificacao se o numero e ou nao um primo, sera realizado ate a metade do numero, pois apos isso
    *nao se dara divisoes inteiras, nao precisando ser verificado.
    */
      if(i%j==0){
        resposta=0;
        //Caso ele seja divisivel por um numero(Sem ser um e ele mesmo), mudara a atribuicao de resposta para 0.
      }
    }
    if(resposta){//Caso resposta continue 1 apos a verificacao, ele sera exibido na tela, sendo um primo.
        printf("%d ",i);
    }
    resposta=1;
  }
  return 0;
}
