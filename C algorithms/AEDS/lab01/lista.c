#include "lista.h"
#include<stdlib.h>
#include<stdio.h>

void inicializa_lista(Lista * ap_lista){
  *ap_lista = (Lista) malloc(sizeof(No));
  (*ap_lista)->proximo = NULL;
}

void insere_fim(Lista * ap_lista, int valor){
    if((*ap_lista)->proximo == NULL){
      insere_inicio(ap_lista, valor);
      return;
    }
    Lista novo = (Lista) malloc(sizeof(No)), no_final = (*ap_lista)->proximo;
    novo->valor = valor; 
    novo->proximo = NULL;
    while(no_final->proximo != NULL) no_final = no_final->proximo;
    no_final->proximo = novo;
}

void insere_inicio(Lista * ap_lista, int valor){
  Lista novo = (Lista) malloc(sizeof(No));
  novo->valor = valor;
  novo->proximo = (*ap_lista)->proximo;
  (*ap_lista)->proximo = novo;
}

int remove_fim(Lista * ap_lista){
  if((*ap_lista)->proximo == NULL){ 
    printf("[ERROR]: impossible remove inexisting element\n");
    return 0; 
  } 
  
  Lista penult = (*ap_lista);
  while(penult->proximo->proximo != NULL) penult = penult->proximo;
  int value = penult->proximo->valor;
  free(penult->proximo);
  penult->proximo = NULL;
  return value;
}

int remove_inicio(Lista * ap_lista){
  if((*ap_lista)->proximo == NULL){ 
    printf("[ERROR]: impossible remove inexisting element\n");
    return 0; 
  } 
  
  int value = (*ap_lista)->proximo->valor; 
  Lista inicio = (*ap_lista)->proximo;
  (*ap_lista)->proximo = inicio->proximo;
  free(inicio);
  return value;
}

int remove_ocorrencias(Lista *ap_lista, int valor){
  if((*ap_lista)->proximo == NULL){ 
    printf("[ERROR]: impossible remove inexisting element\n");
    return 0; 
  } 
  Lista currently = *ap_lista, next;
  int count=0;
  while(currently->proximo != NULL){
    next = currently->proximo;
    while(next->valor == valor){
      currently->proximo = next->proximo;
      free(next);
      count++;
      if(currently->proximo != NULL) next = currently->proximo;;
    }
    if(currently->proximo != NULL) currently = currently->proximo;
  }
  return count;
}

int busca(Lista lista, int valor){
  int i=0;
  do{
    lista = lista->proximo;
    if(lista->valor == valor){
      return i;
    }
    i++;
  }while(lista->proximo != NULL);

  return -1;
}

void imprime(Lista lista){
  printf("(");
  if(lista->proximo == NULL) {
    printf(")\n");
    return;
  }
  lista = lista->proximo;
  while(lista->proximo != NULL){
    printf("%d,", lista->valor);
    lista = lista->proximo;  
  }
  printf("%d", lista->valor);
  printf(")\n" );
}

void desaloca_lista(Lista *ap_lista){
  free(*ap_lista);
}
