/*Esse algoritmo tem o objetivo de gerar numeros aleatorios utilizando o segundo atual.
*Os algoritmos de numeros aleatorios tem o impecilho de ser gerado um numero aleatorio
*uma vez, mas a cada nova execucao, gera-se o mesmo numero repetidas vezes. Para
*resolvermos isto, utilizamos o time(NULL), que como citei no inicio, utiliza do
*segundo atual apartir de certa data(1 de Janeiro de 1970), utilizando uma base
*para se gerar um numero aleatorio diferente a cada execucao com o passar do tempo.
* Incluimos a <stdlib.h> que contem as funcoes rand() e srand() e a <time.h> que
*contem a funcao time().
*/

#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int main()
{
  int i;
  srand(10);
  printf("Sorteiar o mesmo valor a cada nova execucao:");
  for (i=0; i < 1; i++)//Vai se gerar um valor aleatorio.
  {
    printf("\n%d\n",rand()%10);
    //O valor estara entre 1 a 10
  }
  printf("Sorteiar um valor aleatorio a cada nova execucao:");
  srand(time(NULL));
  /* srand(time(NULL)) inicializa a semente com base no segundo atual
  *apartir de 1970, gerando assim ent�o um n�mero realmente aleat�rio
  *a cada execucao*/
  for (i=0; i < 1; i++)//Vai se gerar um valor aleatorio.
  {
    printf("\n%d",rand()%10);
    //O valor estara entre 1 a 10
  }
  return 0;
}
