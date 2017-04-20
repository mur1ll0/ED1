#include <stdio.h>
#include <stdlib.h>


int main () {
  int *p; // cria ponteiro para int
  int EntradaUsuario=0;

  puts("Digite o Numero de posições do vetor");
  scanf("%d",&EntradaUsuario);

  p = (int *)malloc(EntradaUsuario * sizeof(int)); //aloca memória

    if(p){// testa se alocou mem
      printf("Memoria alocada com sucesso\n");

    }else {
      printf("não foi possivel alocar\n" );
      return 0;
    }
int i=0;


for (i=0;i < EntradaUsuario;i++){
  puts("Digite os valores do vetor");
  scanf("%d",&p[i]);

}

for (;i>0;i--){
  printf("Posição {%d} Valor {%d}\n",i-1,p[i-1] );
}


  return 0;
}
