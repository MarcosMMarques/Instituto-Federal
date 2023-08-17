#include "Arvore.h"
#include<stdio.h>
#include<stdlib.h>

void imprime_rec(Arvore arv) {
  if (arv == NULL) {
    printf(".");
    return;
  }
  printf("[%d:e=", arv->valor);
  imprime_rec(arv->esq);
  printf(",d=");
  imprime_rec(arv->dir);
  printf("]");
}

void imprime(Arvore arv) {
  imprime_rec(arv);
  printf("\n");
}

bool insere(Arvore* ap_arv, int x){
  if(*ap_arv == NULL){
    Arvore new_node = (Arvore) malloc(sizeof(No));
    new_node->valor = x;
    new_node->dir = NULL;
    new_node->esq = NULL;
    (*ap_arv) = new_node;
    return true;
  }
  if(x < (*ap_arv)->valor){
    return insere(&(*ap_arv)->esq, x);
  }else if(x > (*ap_arv)->valor){
    return insere(&(*ap_arv)->dir, x);
  }
  return false;
}

bool busca(Arvore arv, int x){
  if(arv == NULL) return false;
  if((arv)->valor == x) return true;
  if(x < arv->valor){
    busca(arv->esq, x);
  }else if(x > arv->valor){
    busca(arv->dir, x);
  }
}

bool remove_(Arvore* ap_arv, int x){
  if(busca((*ap_arv), x) == false) return false;

  if((*ap_arv)->valor == x){
    if((*ap_arv)->esq == NULL && (*ap_arv)->dir == NULL){
      Arvore removed = *ap_arv;
      free(removed);
      *ap_arv = NULL;
    } else if((*ap_arv)->esq != NULL && (*ap_arv)->dir == NULL){
      Arvore aux = (*ap_arv)->esq, removed = *ap_arv;
      free(removed);
      *ap_arv = aux;
    } else if((*ap_arv)->esq == NULL && (*ap_arv)->dir != NULL){
      Arvore aux = (*ap_arv)->dir, removed = *ap_arv;
      free(removed);
      *ap_arv = aux;
    } else {
      Arvore aux = (*ap_arv)->esq;
      while(aux->dir != NULL) aux = aux->dir;
      int value = aux->valor;
      remove_(&(*ap_arv), aux->valor);
      (*ap_arv)->valor = value;
    }
    return true;
  }

  if(x < (*ap_arv)->valor){  
    remove_(&((*ap_arv)->esq), x);
  } else {
    remove_(&((*ap_arv)->dir), x);
  }
}

// bool remove_(Arvore* ap_arv, int x){ 
//   if((*ap_arv) == NULL)
//     return false;
//   if((*ap_arv)->valor == x){ 
//     if((*ap_arv)->esq == NULL && (*ap_arv)->dir == NULL){
//       Arvore pointer = (*ap_arv);
//       (*ap_arv) = NULL;
//       free(pointer);
//       return true;
//     }else if((*ap_arv)->esq == NULL){
//       Arvore pointer = (*ap_arv);
//       (*ap_arv) = (*ap_arv)->dir; 
//       free(pointer);
//       return true;
//     }else if((*ap_arv)->dir == NULL){
//       Arvore pointer = (*ap_arv);
//       (*ap_arv) = (*ap_arv)->esq; 
//       free(pointer);
//       return true;
//     }else{
//       Arvore helper = (*ap_arv)->esq;
//       while (helper->dir != NULL)
//         helper = helper->dir;
//       (*ap_arv)->valor = helper->valor;
//       return remove_(&(*ap_arv)->esq,helper->valor);
//     }
//   }
//   if((*ap_arv)->valor > x)
//     return remove_(&(*ap_arv)->esq,x);
//   else if((*ap_arv)->valor < x)
//     return remove_(&(*ap_arv)->dir,x);
  
// } 