#include<stdlib.h>
#include "lista.h"

/* Inicializa a lista como lista vazia. */
void inicializa_lista(Lista * ap_lista){
    *ap_lista = (Lista) malloc(sizeof(No));
    (*ap_lista)->antec = *ap_lista;
    (*ap_lista)->prox = *ap_lista;
}

/* Insere valor no fim da lista apontada por ap_lista. ap_lista aponta para o no cabeca da lista. */
void insere_fim(Lista ap_lista, TipoDado valor){
    Lista node = (Lista) malloc(sizeof(No));
    node->valor = valor;
    node->prox = ap_lista;
    node->antec = ap_lista->antec;
    ap_lista->antec->prox = node;
    ap_lista->antec = node;
}

/* Insere valor no inicio da lista apontada por ap_lista. ap_lista aponta para o no cabeca da lista. */
void insere_inicio(Lista ap_lista, TipoDado valor){
    Lista node = (Lista) malloc(sizeof(No));
    node->valor = valor;
    node->prox = ap_lista->prox;
    node->antec = ap_lista;
    ap_lista->prox->antec = node;
    ap_lista->prox = node;
}

/* Remove valor do fim da lista apontada por ap_lista e retorna este valor. */
TipoDado remove_fim(Lista ap_lista){
    Lista antec = ap_lista->antec;
    TipoDado valor = antec->valor;
    ap_lista->antec = antec->antec;
    free(antec);
    ap_lista->antec->prox = ap_lista;
    return valor;
}

/* Remove valor do inicio da lista apontada por ap_lista e retorna este valor. */
TipoDado remove_inicio(Lista ap_lista){
    Lista start = ap_lista->prox;
    TipoDado valor = start->valor;
    ap_lista->prox = start->prox;
    free(start);
    ap_lista->prox->antec = ap_lista;
    return valor;
}

/* Remove todas as ocorrencias de valor da lista apontada por ap_lista. 
 * Retorna o numero de ocorrencias removidas. */
int remove_ocorrencias(Lista ap_lista, TipoDado valor){
    Lista currently = ap_lista, next = currently->prox;
    int x=0;
    while(next != ap_lista){
        if(next->valor.coef == valor.coef && next->valor.grau == valor.grau){
            currently->prox = next->prox;
            currently->prox->antec = currently;
            free(next);
            x++;
        }else currently = currently->prox;
        next = currently->prox;
    }
    return x;
}

/* Busca elemento valor na lista. 
   Retorna a posição da primeira ocorrencia de valor na lista, comecando de 0=primeira posicao.
   Retorna -1 caso nao encontrado. */
int busca(Lista lista, TipoDado valor){
    Lista currently = lista->prox;
    int x=0;
    while(currently != lista){
        if(currently->valor.coef == valor.coef && currently->valor.grau == valor.grau) return x;
        x++;
        currently = currently->prox;
    }
    return -1;
}

/* Retorna o campo coef do primeiro no que contenha grau igual ao parametro grau, 
   e 0 (zero) caso nao encontre um tal no.  */
int coeficiente_do_grau(Lista lista, int grau){
    Lista currently = lista->prox;
    while(currently != lista){
        if(currently->valor.grau == grau) return currently->valor.coef;
        currently = currently->prox;
    }
    return 0;
}

/* Imprime a lista na saida padrao, no formato:
   [(1,3),(2,3),(4,2),(3,1),(4,17)]
   em uma linha separada. */
void imprime(Lista lista){
    Lista currently = lista->prox;
    printf("[");
    while(currently != lista){
        printf("(%d,%d)", currently->valor.grau, currently->valor.coef);
        if(currently->prox != lista) printf(",");
        currently = currently->prox;
    }
    printf("]\n");
}

/* Desaloca toda a memória alocada da lista.
 */
void desaloca_lista(Lista *ap_lista){
    Lista next, currently = (*ap_lista)->prox;
    while(currently != (*ap_lista)){
        next = currently->prox;
        free(currently);
        currently = next;
    }
    free(*ap_lista);
}
