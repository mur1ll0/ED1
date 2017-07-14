#ifndef Agenda_H
#define Agenda_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX 100

typedef struct _contato{
    char nome[MAX];
    int telefone;
    char email[MAX];
}tp_contato;


void inserirContato(tp_contato *ptr_Contato,int contadorInserir);

void mostrarContato(tp_contato *ptr_Contato,int contadorInserir);

//int buscarContato( int * vetorContato, int );

void inserirContato(tp_contato *ptr_Contato,int contadorInserir){

  ptr_Contato = (tp_contato *)malloc(1 * sizeof(tp_contato)); //aloca memória

   if(ptr_Contato){// testa se alocou mem
      printf("Memoria alocada com sucesso\n");

    }else {
      printf("não foi possivel alocar\n" );

}

//printf("%d\n",contadorInserir );

  getchar();
  puts("Digite o Nome do contato :");
  fgets(ptr_Contato[contadorInserir].nome,100,stdin);

  puts("Digite o Telefone do contato (apenas inteiros sem espaço):");
  scanf("%d",&ptr_Contato[contadorInserir].telefone);
  getchar();

  puts("Digite o E-mail do contato :");
  fgets(ptr_Contato[contadorInserir].email,100,stdin);

}


void mostrarContato(tp_contato *ptr_Contato,int contadorInserir){
  puts("mostra");
  for (int i=1; i <= contadorInserir; i++){
       printf("Nome %s\n",ptr_Contato[i].nome );
       printf("Fone %d\n",ptr_Contato[i].telefone);
       printf("Email %s\n",ptr_Contato[i].email );
 }
}
#endif
