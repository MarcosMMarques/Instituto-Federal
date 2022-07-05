/*Neste algoritmo e nos requisitado a sequencia de fibonacci até o termo n, determinado pelo usuário
*A sequencia de fibonacci comeca com 1, e consiste que a proxima casa sera a soma das 2 casas antecedentes
*Por exemplo: 6 primeiros termos da sequencia de Fibonacci:{1(comeco) 1(1+0) 2(1+1) 3(2+1) 5(3+2) 8(5+3)}*/
#include<stdio.h>
int main(){
  int n,i;
  scanf("%d",&n);
  //Aqui lemos a quantidade de termos que o usuario quer que seja impresso na tela.
  int v[n+1];
  v[0]=0;
  //Para que seja possivel somarmos a primeira casa com 0, criamos um vetor com o numero de termos que o usuario quer
  //com uma casa a mais, para que seja possivel a realização da sequencia.
  for(i=1;i<n+1 && n>0;i++){
      //O laco de repeticao so sera executado se o numero digitado pelo usuario for maior que 0.
      v[i]=v[i-1]+v[i-2];
      //Aqui e realizado a operacao das duas casas antecedentes a casa desejada.
      if(i==1){
        v[i]=1;
        //Como os primero termo é 1, atribuimos a segunda posicao do vetor 1, para que a proxima casa
        //seja realizado a conta corretamente, 0+1=1,1+1=2, 2+1=3, etc.
      }
      printf("%d ",v[i]);
      //Aqui e exibido na tela os n termos da sequencia de Fibonacci.
  }
  return 0;
}


