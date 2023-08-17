#include<stdio.h>
#include<stdlib.h>

int main() {
  int s, w;
  scanf("%d %d", &s, &w);
  int target = 0;
  unsigned long long int *setW, index=0;

  for(int i=0; i < s; i++) target = target | (1 << i);
  for(int i=0; i < s; i++) index = index & (0 << i);

  setW = (unsigned long long int *) calloc(w, sizeof(unsigned long long int));
  
  for(int i = 0; i < w; i++){
    int quantify_elements;
    scanf("%d", &quantify_elements);

    for(int j=0;j<quantify_elements;j++){
      int element;
      scanf("%d", &element);
      setW[i] = setW[i] | (1 << element);
    }

  }

  int sum;
  for(int i = 0; i < (1 << w); ++i){
    index=0;
    sum = 0;
    for(int j = 0; j < w; ++j){
      if(i & (1 << j) && ((sum & setW[j]) == 0)){
        sum += setW[j];
        index = index | (1 << j);
      }
    }
    if(sum == target) break;
  }
  if(sum != target){
    printf("Insoluvel\n");
    return 0;
  }

  int count = 0;
  for(int i = 0; i < 20; ++i){
    if(index & (1 << i)) count++;
  }
  printf("%d\n", count);
  for(int i = 0, aux = 0; i < 20; ++i, ++aux){
    if(index & (1 << i)){
      int quantity = 0;
      for(int j = 0; j < 20; j++){
        if(setW[aux] & (1 << j)) quantity++; 
      }
      printf("%d", quantity);
      for(int j = 0; j < 20; j++){
        if(setW[aux] & (1 << j)) printf(" %d", j); 
      }
      printf("\n");
    }
  }
  free(setW);
  return 0;
}
