//O usuario ira escrever um numero e o algoritmo fara a verificacao se e um numero primo
#include<stdio.h>

int main(){
int num,i,resposta=0;
//Inicializamos 3 variaveis inteiras, e atribuimos a variavel resposta o algarismo zero
scanf("%d",&num);
    for(i=2;i<=num/2;i++){
        /*Este for funcionara como um loop de algarismo do 2 ate a metade do algorismo digitado, porque?
        *Bom, apartir da metade de um algarismo, sua divisao nao sera mais inteira, entao para verificarmos se
        *um numero e primou ou nao, verificamos se todos os numeros de 2 ate a sua metade podem dividi-lo.*/
        if(num%i==0){
            //Se ele for divisivel por algum numero antes entre 2 ate sua metade, dando resto 0, a variavel resposta recebe 1
            resposta=1;
        }
    }
    if(resposta){//Se a variavel resposta for 1, entao isso indica que o numero foi divisivel por 1 ou mais algarismos, nao sendo primo.
        printf("Nao e primo");
    }else{//Caso a variavel resposta continue 0 ate o fim da execucai, e um numero primo.
        printf("E primo");
    }
return 0;
}

