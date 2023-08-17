#include<stdio.h>
#include<string.h>
#include "grafo.h"

int main() {
  int vertices, edges, v1, v2;
  Grafo g;
  scanf("%d %d", &vertices, &edges);
  initialize_grafo(&g, vertices);
  for(int i=0; i<edges; i++){
    scanf("%d %d", &v1, &v2);
    add_edge(&g, v1, v2);
  }
  // for(int i=0;i<vertices;i++){
  //   imprime(g, i);
  // }
  scanf("%d %d", &v1, &v2);
  int r = distance(&g, v1, v2);
  if(r == -1) printf("infinito");
  else printf("%d", r);
  free_grafo(&g);

  return 0;
}
