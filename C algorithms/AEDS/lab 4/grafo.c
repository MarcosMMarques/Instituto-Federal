#include<stdlib.h>
#include<stdio.h>
#include"grafo.h"
#include <limits.h>

void initialize_grafo(Grafo * ap_g, int vertices){
    (*ap_g).vertices = vertices;
    (*ap_g).array_v = (List *) malloc(vertices * sizeof(List));
    for(int i=0; i<vertices;i++){
        (*ap_g).array_v[i] = (List) malloc(sizeof(Node));
        (*ap_g).array_v[i]->next = (*ap_g).array_v[i];
    } 
}

void initialize_queue(Queue * ap_q){
    *ap_q = (Queue) malloc(sizeof(Node_q));
    (*ap_q)->next = *ap_q;
    (*ap_q)->previous = *ap_q;
}

void free_queue(Queue * ap_q){
    Queue next, currently = (*ap_q)->next;
    while(currently != (*ap_q)){
        next = currently->next;
        free(currently);
        currently = next;
    }
    free(*ap_q);
}

void add_queue(Queue * ap_q, int vertice, int dist){
    Queue new = (Queue) malloc(sizeof(Node_q));
    new->vertice = vertice;
    // new->color = color;
    new->dist = dist;
    new->next = *ap_q;
    if((*ap_q)->previous == *ap_q) (*ap_q)->next = new;
    (*ap_q)->previous->next = new;
    new->previous = (*ap_q)->previous;
    (*ap_q)->previous = new;    
}

int elements_in_queue(Queue *ap_q){
    Queue currently = (*ap_q)->next;
    int count = 0;
    while(currently != *ap_q){
        count++;
        currently = currently->next;
    }
    return count;
}

void add_edge(Grafo * ap_g, int vertice1, int vertice2){
    List new1 = (List) malloc(sizeof(Node)), new2 = (List) malloc(sizeof(Node));
    new1->neighbor = vertice2;
    new1->next = (*ap_g).array_v[vertice1]->next;  
    (*ap_g).array_v[vertice1]->next = new1;

    new2->neighbor = vertice1;
    new2->next = (*ap_g).array_v[vertice2]->next;  
    (*ap_g).array_v[vertice2]->next = new2;
}

int first_in_queue(Queue *ap_q){
    if(elements_in_queue(ap_q) != 0) return (*ap_q)->next->vertice;
    return -1; 
}

void remove_queue(Queue *ap_q){
    Queue next = (*ap_q)->next;
    (*ap_q)->next = next->next;
    next->next->previous = *ap_q;
    free(next);
}

int distance(Grafo *ap_g, int vertice1, int vertice2){
    Queue q;
    int dist=0, color[(*ap_g).vertices];
    List currently;
    for(int i=0; i < (*ap_g).vertices; i++){
        color[i] = 0;
    }
    color[vertice1] = 1;
    initialize_queue(&q);
    add_queue(&q, vertice1, 1);
    while(elements_in_queue(&q) != 0){ 
        dist++;
        int elements_quantity = elements_in_queue(&q);
        for(int i=0; i < elements_quantity; i++){
            currently = (*ap_g).array_v[first_in_queue(&q)]->next; 
            while(currently != (*ap_g).array_v[first_in_queue(&q)] && currently->neighbor != vertice2){
                if(color[currently->neighbor] == 0){
                    add_queue(&q, currently->neighbor, dist);
                    color[currently->neighbor] = 1;
                }
                currently = currently->next;
            }
            if(currently->neighbor == vertice2) {
                free_queue(&q);
                return dist;
            }
            remove_queue(&q); 
        }
    }
    free_queue(&q);
    return -1;
}


void imprime(Grafo g, int vertice){
    printf("\n[");
    List currently = g.array_v[vertice]->next;
    while(currently != g.array_v[vertice]){
        printf("(%d,%d)", vertice, currently->neighbor);
        if(currently->next != g.array_v[vertice]) printf(",");
        currently = currently->next;
    }
    printf("]\n");
}

void free_grafo(Grafo *ap_g){
    for(int i=0; i < (*ap_g).vertices; i++){
        List currently = (*ap_g).array_v[i]->next, next;
        while(currently != (*ap_g).array_v[i]){
            next = currently->next;
            free(currently);
            currently = next;
        }
        free((*ap_g).array_v[i]);
    }
    free((*ap_g).array_v);
}

