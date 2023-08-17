#include "matriz.h"
#include <stdlib.h>
#include <stdio.h>
/*
 * Implemente as seguintes funcoes de um Tipo Abstrato de Dados de uma
 * Matriz esparsa de elementos inteiros. Utilize uma lista circular
 * duplamente ligada com no cabeca bidimensional, sendo uma dimensão
 * para linha e outra para colunas. Somente os elementos nao zero
 * devem ser armazenados. Uma matriz tem dois parâmetros, número de
 * linhas, nlin, e número de colunas, ncol. As linhas da matriz terão
 * índices de 0 a nlin-1. As colunas de 0 a ncol-1. Cada elemento está
 * em precisamente uma linha e uma coluna. Cada par linha e coluna
 * contém precisamente um elemento inteiro.
 */

/* Inicializa uma matriz de zeros com nlin linhas e ncol colunas. 
 * Supõe que não há nada a ser desalocado. */
void inicializa_matriz(Matriz * ap_mat, int nlin, int ncol) {
   ap_mat->cabeca = (ListaBidim) malloc(sizeof(No));
   ap_mat->n_linhas = nlin;
   ap_mat->n_colunas = ncol;
   ap_mat->cabeca->linha = ap_mat->cabeca->coluna = -1; 
   ap_mat->cabeca->acima = ap_mat->cabeca->abaixo = ap_mat->cabeca;
   ap_mat->cabeca->direita = ap_mat->cabeca->esquerda = ap_mat->cabeca;     
}

/* Desaloca a memória atualmente utilizada por *mat. Em seguida, 
   inicializa *mat para ser uma matriz de zeros com nlin linhas e
   ncol colunas.  */
void zera(Matriz *ap_mat, int nlin, int ncol){
   ListaBidim next, node_aux = ap_mat->cabeca->direita;
   desaloca_matriz(&(*ap_mat));
   inicializa_matriz(&(*ap_mat), nlin, ncol);
}

ListaBidim find_line(ListaBidim head, int lin){
   ListaBidim currently = head->abaixo;
   while(currently != head){
      if(currently->linha == lin) return currently;
      currently = currently->abaixo;
   }
   return NULL;
}

ListaBidim find_column(ListaBidim head, int col){
   ListaBidim currently = head->direita;
   while(currently != head){
      if(currently->coluna == col) return currently;
      currently = currently->direita;
   }
   return NULL;
}

void insert_line(ListaBidim head, ListaBidim head_line){
   ListaBidim currently = head;
   while(currently->abaixo->linha != -1 && currently->abaixo->linha < head_line->linha) currently = currently->abaixo;
   head_line->abaixo = currently->abaixo;
   currently->abaixo->acima = head_line; 
   currently->abaixo = head_line;
   head_line->acima = currently;
   if(head_line->coluna == -1) return;
}

void insert_column(ListaBidim head, ListaBidim head_column){
   ListaBidim currently = head;
   while(currently->direita->coluna != -1 && currently->direita->coluna < head_column->coluna) currently = currently->direita;
   head_column->direita = currently->direita;
   currently->direita->esquerda = head_column; 
   currently->direita = head_column;
   head_column->esquerda = currently;
   if(head_column->coluna == -1) return;
}

/* Define que o elemento na linha lin e coluna col valerá val. 
   O parâmetro lin está em [0,n_linhas-1] e ncol em [0,n_colunas-1].*/
void define_elemento(Matriz mat, int lin, int col, int val){
   if(lin < 0 || col < 0 || lin >= mat.n_linhas || col >= mat.n_colunas) return;
   ListaBidim head_line = find_line(mat.cabeca, lin);
   ListaBidim head_column = find_column(mat.cabeca, col);
   if(head_line != NULL && head_column != NULL){
      ListaBidim element = find_column(head_line, col);
      if(element != NULL){
         if(val != 0){ 
            element->valor = val;
            return;
         }
         element->acima->abaixo = element->abaixo;
         element->esquerda->direita = element->direita;
         element->direita->esquerda = element->esquerda;
         element->abaixo->acima = element->acima;
         free(element);
         return;
      }
   }
   if(val == 0) return;
   if(head_line == NULL){
      head_line = (ListaBidim) malloc(sizeof(No));
      head_line->linha = lin;
      head_line->coluna = -1;
      head_line->direita = head_line->abaixo = head_line->esquerda = head_line->acima = head_line;
      insert_line(mat.cabeca, head_line); 
   }
   if(head_column == NULL){
      head_column = (ListaBidim) malloc(sizeof(No));
      head_column->linha = -1;
      head_column->coluna = col;
      head_column->direita = head_column->abaixo = head_column->esquerda = head_column->acima = head_column;
      insert_column(mat.cabeca, head_column); 
   }
   ListaBidim element = (ListaBidim) malloc(sizeof(No));
   element->valor = val;
   element->linha = lin;
   element->coluna = col;
   element->direita = element->abaixo = element->esquerda = element->acima = element;
   insert_line(head_column, element);
   insert_column(head_line, element);
}

ListaBidim find_position(Matriz mat, int lin, int col){
   ListaBidim line_head = mat.cabeca->abaixo;
   while(line_head->linha != lin && line_head != mat.cabeca) line_head = line_head->abaixo;
   if(line_head == mat.cabeca) return NULL;
   ListaBidim aux = line_head->direita;
   while(aux != line_head){
      if(aux->coluna == col) return aux;
      aux = aux->direita;
   }
   return NULL;
}

/* Computa a soma das matrizes a e b colocando o resultado em *ap_res.
 * Libera a memória anteriormente utilizada pelos nos de
 * *ap_res, e sobreescreve *ap_res. */
 bool soma(Matriz *ap_res, Matriz a, Matriz b){
   if(a.n_colunas != b.n_colunas || a.n_linhas != b.n_linhas) return false;
   inicializa_matriz(&(*ap_res), a.n_linhas, a.n_colunas);

   ListaBidim line_a = a.cabeca->abaixo;
   while(line_a != a.cabeca){
      ListaBidim aux = line_a->direita;
      while(aux != line_a){
         define_elemento(*ap_res, aux->linha, aux->coluna, aux->valor);
         aux = aux->direita;
      }
      line_a = line_a->abaixo;
   }
   ListaBidim line_b = b.cabeca->abaixo;
   while(line_b != b.cabeca){
      ListaBidim aux = line_b->direita;
      while(aux != line_b){
         ListaBidim postion = find_position(*ap_res, aux->linha, aux->coluna);
         if(postion != NULL){
            if(postion->valor + aux->valor != 0){
               define_elemento(*ap_res, aux->linha, aux->coluna, postion->valor + aux->valor);
            }else {
               define_elemento(*ap_res, aux->linha, aux->coluna, 0);
            }
         } else if(postion == NULL) {
            define_elemento(*ap_res, aux->linha, aux->coluna, aux->valor);
         }
         aux = aux->direita;
      }
      line_b = line_b->abaixo;
   }
   return true;
 }

/* Computa a subtracao das matrizes a e b colocando o resultado em *ap_res.
 * Libera a memória anteriormente utilizada pelos nos de
 * *ap_res, e sobreescreve *ap_res. */
 bool subtrai(Matriz *ap_res, Matriz a, Matriz b){
   if(a.n_colunas != b.n_colunas || a.n_linhas != b.n_linhas) return false;
   inicializa_matriz(&(*ap_res), a.n_linhas, a.n_colunas);

   ListaBidim line_a = a.cabeca->abaixo;
   while(line_a != a.cabeca){
      ListaBidim aux = line_a->direita;
      while(aux != line_a){
         define_elemento(*ap_res, aux->linha, aux->coluna, aux->valor);
         aux = aux->direita;
      }
      line_a = line_a->abaixo;
   }
   ListaBidim line_b = b.cabeca->abaixo;
   while(line_b != b.cabeca){
      ListaBidim aux = line_b->direita;
      while(aux != line_b){
         ListaBidim postion = find_position(*ap_res, aux->linha, aux->coluna);
         if(postion != NULL){
            if(postion->valor - aux->valor != 0){
               define_elemento(*ap_res, aux->linha, aux->coluna, postion->valor - aux->valor);
            }else {
               define_elemento(*ap_res, aux->linha, aux->coluna, 0);
            }
         } else if(postion == NULL) {
            define_elemento(*ap_res, aux->linha, aux->coluna, 0 - aux->valor);
         }
         aux = aux->direita;
      }
      line_b = line_b->abaixo;
   }
   return true;
 }

/* Computa a multiplicacao das matrizes a e b colocando o resultado em *ap_res.
 * Libera a memória anteriormente utilizada pelos nos de
 * *ap_res, e sobreescreve *ap_res. */
 bool multiplica(Matriz *ap_res, Matriz a, Matriz b){
   if(a.n_colunas != b.n_linhas) return false;
   zera(&(*ap_res), a.n_linhas, b.n_colunas);

   ListaBidim line_A = a.cabeca->abaixo;
   while (line_A != a.cabeca) {
      ListaBidim column_B = b.cabeca->direita;
      while (column_B != b.cabeca) {
         int line = line_A->linha;
         int column = column_B->coluna;

         int sum = 0;
         ListaBidim element_A = line_A->direita;
         ListaBidim element_B = column_B->abaixo;

         while (element_A != line_A && element_B != column_B) {
            if (element_A->coluna == element_B->linha) {
               sum += element_A->valor * element_B->valor;
               element_A = element_A->direita;
               element_B = element_B->abaixo;
            } else if (element_A->coluna < element_B->linha) {
               element_A = element_A->direita;
            } else {
               element_B = element_B->abaixo;
            }
         }

         if (sum != 0)
            define_elemento(*ap_res, line, column, sum);

         column_B = column_B->direita;
      }

      line_A = line_A->abaixo;
   }

   return true;
}

/* Imprime a matriz mat no formato do exemplo abaixo
 * (nlin=100,ncol=200,[0,3]=5,[0,8]=10,[2,9]=50,[5,3]=10,[5,15]=20,[99,0]=33)
 * onde esta matriz tem 100 linhas e 200 colunas, e seus únicos
 * elementos não zero são os seguintes:
 * - da linha 0 coluna 3, com valor 5
 * - da linha 0 coluna 8, com valor 10
 * - da linha 2 coluna 9, com valor 50
 * - da linha 5 coluna 3, com valor 10
 * - da linha 5 coluna 15, com valor 20
 * - da linha 99 coluna 0, com valor 33.
 * Os elementos devem ser impressos em ordem crescente de linhas e dois 
 * elementos da mesma linha em ordem crescente de coluna. 
 */
void imprime(Matriz mat){
   printf("(nlin=%d,ncol=%d", mat.n_linhas, mat.n_colunas);
   ListaBidim line = mat.cabeca->abaixo;
   while(line != mat.cabeca){
      ListaBidim aux = line->direita;
      while(aux != line){
         printf(",[%d,%d]=%d", aux->linha, aux->coluna, aux->valor);
         aux = aux->direita;
      }
      line = line->abaixo;
   }
   printf(")\n");
}

/* Desaloca toda a memória alocada da matriz. */
void desaloca_matriz(Matriz *ap_mat){
   ListaBidim aux = ap_mat->cabeca->acima, next;
   while(aux != ap_mat->cabeca){
      next = aux->direita;
      while(next != aux){
         next = next->direita;
         free(next->esquerda);
      }
      aux = aux->acima;
   }
   aux = ap_mat->cabeca->direita;
   while(aux != ap_mat->cabeca){
      aux = aux->direita;
      free(aux->esquerda);
   }
   free(ap_mat->cabeca);
}