#include<stdlib.h>
#include<stdio.h>
#include"polinomio.h"
/*
 * Implemente as seguintes funcoes de um Tipo Abstrato de Dados de um 
 * Polinômio de coeficientes inteiros. Utilize uma lista circular
 * duplamente ligada com no cabeca, mantendo sempre os coeficientes 
 * ordenados por grau. Somente os coeficientes nao zero devem ser armazenados.
 */

/* Inicializa um polinômio vazio. */
void inicializa_polinomio(Polinomio * ap_pol){
    *ap_pol = (Polinomio) malloc(sizeof(No));
    (*ap_pol)->prox = *ap_pol;
    (*ap_pol)->antec = *ap_pol;
    (*ap_pol)->valor.grau = -1;
}

/* Define que o coeficiente de grau grau do polinomio pol eh igual a coef. Deve manter os 
 * coeficientes ordenados por grau. */
void define_coeficiente(Polinomio pol, int grau, int coef){
    if(coef == 0) return;
    Polinomio currently = pol->prox, new = malloc(sizeof(No));
    while(grau > currently->valor.grau && currently->prox != pol) currently = currently->prox;
    if(currently->valor.grau == grau){
        currently->valor.coef = coef;
        return;    
    }
    new->valor.coef = coef;
    new->valor.grau = grau;
    new->prox = currently->prox;
    new->prox->antec = new;
    new->antec = currently;
    currently->prox = new;
}

/* Zera o polinomio, tornando-o um polinomio inicializado, mas igual a zero. Desaloca a memória liberada. */
void zera(Polinomio pol){
    desaloca_polinomio(&pol);
    inicializa_polinomio(&pol);
}

void remove_zero(Polinomio ap_node){
    ap_node->antec->prox = ap_node->prox;
    ap_node->prox->antec = ap_node->antec;    
    free(ap_node);
}

/* Computa a soma dos polinomios a e b colocando o resultado em res. 
 * Libera a memória anteriormente utilizada pelos nos descartados de res, e sobreescreve res. */
void soma(Polinomio res, Polinomio a, Polinomio b){
    Polinomio currently_a = a->prox, currently_res = res, currently_b = b->prox;
    while(currently_a != a){ 
        Polinomio new = malloc(sizeof(No)); 
        new->valor.grau = currently_a->valor.grau;
        new->valor.coef = currently_a->valor.coef;
        
        new->antec = currently_res;
        currently_res->prox = new;
        currently_res = currently_res->prox;
        currently_a = currently_a->prox;
    }
    currently_res->prox = res;
    res->antec = currently_res;
    while(currently_b != b){
        currently_res = res->prox;
        while(currently_b->valor.grau > currently_res->valor.grau && currently_res->prox != res){
            currently_res = currently_res->prox;
        }
        if(currently_b->valor.grau == currently_res->valor.grau){ 
            currently_res->valor.coef += currently_b->valor.coef;
        } else{
            Polinomio new = malloc(sizeof(No));
            new->valor.grau = currently_b->valor.grau;
            new->valor.coef = currently_b->valor.coef;
            new->antec = currently_res->antec;
            new->prox = currently_res;
            currently_res->antec->prox = new;
            currently_res->antec = new;
        }
        if(currently_res->valor.coef == 0) {
            remove_zero(currently_res);
        }
        currently_b = currently_b->prox;
    }
}

/* Computa a subtracao dos polinomios a e b colocando o resultado em res. 
 * Libera a memória anteriormente utilizada pelos nos descartados de res, e sobreescreve res. */
void subtrai(Polinomio res, Polinomio a, Polinomio b){
    Polinomio currently_a = a->prox, currently_res = res, currently_b = b->prox;
    while(currently_a != a){ 
        Polinomio new = malloc(sizeof(No)); 
        new->valor.grau = currently_a->valor.grau;
        new->valor.coef = currently_a->valor.coef;
        
        new->antec = currently_res;
        currently_res->prox = new;
        currently_res = currently_res->prox;
        currently_a = currently_a->prox;
    }
    currently_res->prox = res;
    res->antec = currently_res;
    while(currently_b != b){
        currently_res = res->prox;
        while(currently_b->valor.grau > currently_res->valor.grau && currently_res->prox != res){
            currently_res = currently_res->prox;
        }
        if(currently_b->valor.grau == currently_res->valor.grau){ 
            currently_res->valor.coef -= currently_b->valor.coef;
        }else{
            Polinomio new = malloc(sizeof(No));
            new->valor.grau = currently_b->valor.grau;
            new->valor.coef = -1 * currently_b->valor.coef;
            new->antec = currently_res->antec;
            new->prox = currently_res;
            currently_res->antec->prox = new;
            currently_res->antec = new;
        }
        if(currently_res->valor.coef == 0) {
            remove_zero(currently_res);
        }
        currently_b = currently_b->prox;
    }
}

/* /\* Computa a multiplicacao dos polinomios a e b colocando o resultado em res.  */
/*  * Libera a memória anteriormente utilizada pelos nos descartados de res, e sobreescreve res. *\/ */
/* void multiplica(Polinomio res, Polinomio a, Polinomio b){} */

/* Imprime o polinomio pol no formato do exemplo abaixo
 * [(0,2),(3,-2),(10,5)]
 * onde este polinomio tem 3 coeficientes, o de grau 0 com valor 2, o de grau 3 com valor -2 e o de
 * grau 10 com valor 5. 
 */
void imprime(Polinomio pol){
    printf("[");
    Polinomio currently = pol->prox;
    while(currently != pol){
        printf("(%d,%d)", currently->valor.grau, currently->valor.coef);
        if(currently->prox != pol) printf(",");
        currently = currently->prox;
    }
    printf("]\n");
}

/* Desaloca toda a memória alocada da lista.
 */
void desaloca_polinomio(Polinomio *ap_pol){
    Polinomio next, currently = (*ap_pol)->prox;
    while(currently != (*ap_pol)){
        next = currently->prox;
        free(currently);
        currently = next;
    }
    free(*ap_pol);
}

