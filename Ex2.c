#include <stdio.h>
#include <stdlib.h>

  typedef struct {
    char nome [50];
    char endereco [100];
    int matricula;
  } estudante;

int main () {
  estudante *p=NULL;
  int EntradaUsuario=0;

  puts("Digite o Numero de posições do vetor");
  scanf("%d",&EntradaUsuario);

  p = (estudante *)malloc(EntradaUsuario * sizeof(estudante)); //aloca memória

    if(p){// testa se alocou mem
      printf("Memoria alocada com sucesso\n");

    }else {
      printf("não foi possivel alocar\n" );
      return 0;
    }

    for (int i=1; i <= EntradaUsuario; i++){

      puts("Digite o nome ");
      scanf("%s",p[i].nome);
      //__fpurge(stdin);

      puts("Digite o endereço ");
      scanf("%s",p[i].endereco);
      //fgets(p[i].endereco,101,stdin);
      //__fpurge(stdin);
      puts("Digite a Matricula");
      scanf("%d",&p[i].matricula);
      //__fpurge(stdin);




    }
    for (int i=1; i <= EntradaUsuario; i++){
      printf("Nome %s\n",p[i].nome );
      printf("endereco %s\n",p[i].endereco);
      printf("matricula %d\n",p[i].matricula );
    }
  return 0;
}
