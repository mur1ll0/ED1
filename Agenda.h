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


///Configura retorno do tipo tp_contato
tp_contato *inserirContato(tp_contato *ptr_Contato,int contadorInserir);

void mostrarContato(tp_contato *ptr_Contato,int contadorInserir);

//int buscarContato( int * vetorContato, int );

///#######################################################################################################################################
///------------------------------------------------------------MUR1LL0 CODE--------------------------------------------------------------#
///#######################################################################################################################################
tp_contato *inserirContato(tp_contato *ptr_Contato,int contadorInserir){
  ///--Parâmetros:
  ///*ptr_Contato ==> Ponteiro para a agenda de contatos
  ///contadorInserir ==> Quantidade de contatos para realocar o ponteiro

  ///Se for a primeira alocação
  if(ptr_Contato == NULL){
    ptr_Contato = (tp_contato *)malloc(sizeof(tp_contato)); //aloca memória
  }
  ///Se ja existir a agenda, realocar dinamicamente
  else{
    ptr_Contato = (tp_contato *)realloc(ptr_Contato, contadorInserir * sizeof(tp_contato));
  }


    if(ptr_Contato){// testa se alocou mem
      printf("Memoria alocada com sucesso\n");

    }else {
      printf("não foi possivel alocar\n" );
    }

//printf("%d\n",contadorInserir );
  ///Como contadorInserir sofre incremento antes, aqui deve considerar esse incremento usando -1
  getchar();
  puts("Digite o Nome do contato :");
  fgets(ptr_Contato[contadorInserir-1].nome,100,stdin); ///Perceba o contadorInserir-1

  puts("Digite o Telefone do contato (apenas inteiros sem espaço):");
  scanf("%d",&ptr_Contato[contadorInserir-1].telefone);
  getchar();

  puts("Digite o E-mail do contato :");
  fgets(ptr_Contato[contadorInserir-1].email,100,stdin);

  ///Retorna ponteiro atualizado
  return ptr_Contato;
}


void mostrarContato(tp_contato *ptr_Contato,int contadorInserir){
  puts("mostra");
  int i;
  for (i=0; i < contadorInserir; i++){
       printf("Nome %s\n",ptr_Contato[i].nome );
       printf("Fone %d\n",ptr_Contato[i].telefone);
       printf("Email %s\n",ptr_Contato[i].email );
 }
}
#endif
