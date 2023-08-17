#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int coord[2];
} Ponto;
 typedef Ponto * Vertice;
 typedef struct{
      Vertice coord1, coord2, coord3;
     Vertice coord[3];
 } Triangulo;

 void initialize(Triangulo *ap_t){
     for(int i=0; i<3; i++){
         (*ap_t).coord[i] = (Vertice) malloc(sizeof(Ponto));
     }
     (*ap_t).coord[0]->coord[0] = 1;
     (*ap_t).coord[0]->coord[1] = 2;
     (*ap_t).coord[1]->coord[0] = 3;
     (*ap_t).coord[1]->coord[1] = 4;
     (*ap_t).coord[2]->coord[0] = 5;
     (*ap_t).coord[2]->coord[1] = 6;
 }

 int main(){
     Triangulo t;
     initialize(&t);
     printf("(%d, %d)", t.coord[0]->coord[0], t.coord[0]->coord[1]);
     printf("(%d, %d)", t.coord[1]->coord[0], t.coord[1]->coord[1]);
     printf("(%d, %d)", t.coord[2]->coord[0], t.coord[2]->coord[1]);
     return 0;
 }

Questao 2 

/*(20% da nota) Declare uma estrutura de dados lista ligada simples (não circular, não duplamente
ligada), com nó cabeça, de inteiros. Em seguida, escreva código para consecutivamente:
(a) inicializar uma lista vazia;
(b) inserir o elemento 100 na lista;
(c) inserir o elemento 200 após o 100;
(d) inserir o elemento 50 no início da lista;
Após estas operações, sua lista terá os elementos (50, 100, 200) nesta ordem. Desenhe este estado
da sua estrutura de dados. Em seguida, escreva código para consecutivamente nesta ordem:
(a) inserir o elemento 500 na terceira posição da lista, deslocando o anterior terceiro elemento
para a quarta posição. (No caso atual, o elemento 500 será inserido entre 100 e 200);
(b) remover o segundo elemento da lista, o elemento 100.

*/

 typedef struct node_aux{
     int value;
     struct node_aux * next;
 }Node;

 typedef Node * List;

 void intialize(List *ap_list){
     *ap_list = (List) malloc(sizeof(Node));
     (*ap_list)->next = NULL;
 }


 void insert_value(List ap_list, int value){
     List aux = ap_list->next;
     while (value > aux->next->value || aux->next != NULL)
         aux = aux->next;
     List node = (List)malloc(sizeof(Node));
     node->next = aux->next;
     aux->next = node;
     node->value = value;
 }



 void remove_element(List ap_list, int value){
     List aux = ap_list->next;
     while (value != aux->next->value)
         aux = aux->next;
        
     List remover;
     if(aux->next != NULL)
         remover = aux->next;
     if(remover->next != NULL)
         aux->next = remover->next;
     free(remover);
 }

 int main(){
     List l;
     intialize(&l);
     List new_100 = (List) malloc(sizeof(Node));
     new_100->value = 100;
     new_100->next = NULL;
     l->next = new_100;
     List new_200 = (List) malloc(sizeof(Node));
     new_200->value = 200;
     new_200->next = NULL;
     new_100->next = new_200;
     List new_50 = (List) malloc(sizeof(Node));
     new_50->value = 50;
     new_50->next = new_100;
     l->next = new_50;
     List new_500 = (List) malloc(sizeof(Node));
     new_500->value = 500;
     new_500->next = new_200;
     new_100->next = new_500;
     new_50->next = new_50->next->next;
     free(new_100);
     insert_value(l, 100);
     insert_value(l, 200);
     insert_value(l, 50);
     insert_value(l, 500);
     remove_element(l, 100);

     List currently = l->next;
     while(currently != NULL){
         printf("%d ",currently->value);
         currently = currently->next;
     }
     return 0;
 }


 Repita os passos da questão anterior utilizando uma lista circular duplamente
 ligada com nó cabeça. (Você deve declarar a estrutura e escrever os códigos das operações.)

  typedef struct node_aux{
     int value;
     struct node_aux * next;
     struct node_aux * prev;
 }Node;

 typedef Node * List;

 void initialize(List * ap_list){
     *ap_list = (List) malloc(sizeof(Node));
     (*ap_list)->next = (*ap_list);
     (*ap_list)->prev = (*ap_list);
 }

 int main(){
     List l;
     initialize(&l);
     List new_100 = (List) malloc(sizeof(Node));
     new_100->value = 100;
     new_100->next = l;
     new_100->prev = l;
     l->next = new_100;
     l->prev = new_100;
     List new_200 = (List) malloc(sizeof(Node));
     new_200->value = 200;
     new_200->next = l;
     l->prev = new_200;
     new_200->prev = new_100;
     new_100->next = new_200;
     List new_50 = (List) malloc(sizeof(Node));
     new_50->value = 50;
     new_50->next = new_100;
     new_50->prev = l;
     new_100->prev = new_50;
     l->next = new_50;
     List new_500 = (List) malloc(sizeof(Node));
     new_500->value = 500;
     new_500->next = new_200;
     new_200->prev = new_500;
     new_100->next = new_500;
     Remove
     new_50->next = new_50->next->next;
     new_200->prev = new_50;
     free(new_100);
     List currently = l->next;
     while(currently != l){
         printf("%d ",currently->value);
         currently = currently->next;
     }
     return 0;
 }

/*Utilize alguma lista ligada para implementar uma fila de número ponto flutuante.
Escreva o código da declaração da estrutura, da inicialização e das operações
(a) inicializa: inicia lista vazia;
(b) insere_fila: insere um número ponto flutuante no fim da fila;
(c) remove_fila: remove o primeiro elemento da fila e retorna seu valor;
(d) eh_vazia: retorna um booleano que descreve se a fila está vazia.*/

 typedef struct Node_aux{
     float value;
     struct Node_aux * next;
     struct Node_aux * prev;
 } Node;
 typedef Node * Queue;

 typedef enum{false, true} bool;

 void initiatilize(Queue *ap_queue){
     *ap_queue = (Queue) malloc(sizeof(Node));
     (*ap_queue)->next = *ap_queue;
     (*ap_queue)->prev = *ap_queue;   
 }

 void insert_queue(Queue queue, float value){
     Queue new_node = (Queue)malloc(sizeof(Node));
     new_node->value = value;
     new_node->next = queue;
     queue->prev->next = new_node;
     queue->prev = new_node;
 }

 float remove_queue(Queue queue){
     if(!empty(queue)) return;       
     float removed = queue->next->value;
     Queue nodeAux = queue->next;
     queue->next = queue->next->next;
     queue->next->prev = queue;
     free(nodeAux);
     return removed;
 }

 bool empty(Queue queue){
     if(queue->next != queue) return false;;
     return true;
 }

/*Descreva seus motivos para a preferir cada uma das seguintes escolhas feitas na
sua implementação da questão anterior:
(a) Uso ou não de nó cabeça;
(b) Uso ou não de circularidade da lista;
(c) Uso ou não de dupla ligação na lista.*/

 a) Tenho preferência pelo uso do nó cabeça por conta da verificação de vazio ser mais facilitada.

 b) Pelo comum inserção no final, a circularidade ajuda a implementar a dupla ligação de forma mais fácil

 c) A dupla ligação ajuda no acesso ao último elemento da lista

 typedef struct{
     int hasher;
     int data;
 }dado;

typedef struct{
    int hash[5000];
}container;

inserir(container x, int data){
    x.hash[data % 9973] = algo aí;
}
