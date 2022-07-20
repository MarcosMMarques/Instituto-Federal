#include <stdio.h>
#include<locale.h>

int main(){
    setlocale(LC_ALL,"portuguese");
    int loop=1;
    int questao;

    while(loop==1){  //estrutura responsavel por repetir
    printf("Digite a questao que quer executar de 1 a 8:\n");
    scanf("%d",&questao);
    switch(questao){
        int n=0,valor1=0,valor2=0,valor3=0;
        float media=0,grausf=0,grausc=0,altura=0,largura=0,comprimento=0,volume=0,racional=0;
        char nome[50];
        case 1: //Quest�o 1
        printf("Digite um valor:\n");
        scanf("%d",&n);
        printf("\nO valor %d subtraido de 51 e: %d\n",n,n-51);
        break;

        case 2:  //Quest�o 2
        printf("\nDigite o primeiro valor:");
        scanf("%d",&valor1);

        printf("\nDigite o segundo valor:");
        scanf("%d",&valor2);

        printf("\nDigite o terceiro valor:");
        scanf("%d",&valor3);
        media=(valor1+valor2+valor3)/3;
        printf("\nA media e:%.2f\n",media);

        break;
        case 3: //Quest�o 3
        printf("\nDigite os graus em Fahrenheit:");
        scanf("%f",&grausf);
        grausc= (grausf-32)/1.8;
        printf("\nEm graus Celsius e %.2f\n",grausc);
        break;
        case 4: //Quest�o 4
        printf("\nEscreva um numero:\n");
        scanf("%d",&valor1);
        printf("\nSeu antecessor e %d\nSeu sucessor e %d\n",valor1-1,valor1+1);
        break;
        case 5: //Quest�o 5
            printf("\nDigite as proporcoes da caixa:");
            printf("\nEscreva a altura, largura e comprimento:\n");
            scanf("%f",&altura);
            scanf("%f",&largura);
            scanf("%f",&comprimento);
            printf("\nVolume:%.2f\n",altura*largura*comprimento);
        break;
        case 6: //Quest�o 6
            printf("\nDigite um numero para ser realizado sua tabuada:\n");
            scanf("%d",&valor1);
            printf("---------");
            printf("\n|%d*0= %d |",valor1,valor1*0);
            printf("\n|%d*1= %d |",valor1,valor1*1);
            printf("\n|%d*2= %d |",valor1,valor1*2);
            printf("\n|%d*3= %d |",valor1,valor1*3);
            printf("\n|%d*4= %d |",valor1,valor1*4);
            printf("\n|%d*5= %d |",valor1,valor1*5);
            printf("\n|%d*6= %d |",valor1,valor1*6);
            printf("\n|%d*7= %d |",valor1,valor1*7);
            printf("\n|%d*8= %d |",valor1,valor1*8);
            printf("\n|%d*9= %d |",valor1,valor1*9);
            printf("\n---------");
        break;
        case 7:  //Quest�o 7
            printf("\nDigite o nome do indigente:\n");
            scanf("%s",&nome);
            printf("\nOla %s\n",nome);
        break;
        case 8:  //Quest�o 8
            printf("\nDigite um valor inteiro e outro racional:\n");
            scanf("%d",&n);
            scanf("%f",&racional);
            printf("\nDivisao: \n%f",n/racional);
        break;
    }
    printf("\nSe quiser digitar outra questao digite 1, caso nao, digite 0:\n");
    scanf("%d",&loop); //Possibilidade de se romper o loop
    }
return 0;
}
