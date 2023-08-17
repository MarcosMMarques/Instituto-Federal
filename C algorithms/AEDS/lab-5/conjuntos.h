#ifndef __GRAFO_H__
#define __GRAFO_H__

typedef struct Node_aux {
  int neighbor;  
  struct Node_aux * next;
} Node;
typedef Node * List;

typedef struct {
  int vertices;
  List *array_v;
}Grafo;

typedef struct Node_q_aux{
  int vertice;
  int dist;
  struct Node_q_aux * next;
  struct Node_q_aux * previous;
} Node_q;
typedef Node_q * Queue;

typedef enum{false, true} bool;

void initialize_grafo(Grafo * ap_g, int vertices);

void add_edge(Grafo * ap_g, int vertice1, int vertice2);

int distance(Grafo *ap_g, int vertice1, int vertice2);

void free_grafo(Grafo *ap_g);

void imprime(Grafo g, int vertice);

#endif
