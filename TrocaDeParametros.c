#include <stdio.h>

void swap (int *a, int *b){
  int Auxiliar=0;
  Auxiliar=*a;
  *a=*b;
  *b=Auxiliar;
}

void swap (int *a, int *b);

int main (){
  int a,b;
  puts("Digite 2 inteiros");
  scanf("%d %d",&a,&b);

  puts("Valor antes da troca");
  printf("A {%d} B {%d}\n",a,b);
  swap(&a,&b);
  puts("Valor após a troca");
  printf("A {%d} B {%d}\n",a,b);

  return 0;
}
