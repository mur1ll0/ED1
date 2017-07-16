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

tp_contato *inserirContato(tp_contato *ptr_Contato,int tamanho);

int partition(tp_contato *vetor, int p, int q);
void quickSort(tp_contato *ptr_Contato,int p, int q);

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

int partition(tp_contato *vetor, int p, int q){
    int i = p, j = q;
    tp_contato *pivo = (tp_contato *)malloc(sizeof(tp_contato));
    tp_contato *aux = (tp_contato *)malloc(sizeof(tp_contato));

    ///strcpy(string_destino, string_origem);
    ///Quando é apenas struct, e nao vetor de struct: Acessar com -> ao invés de .

    strcpy(pivo->email, vetor[p].email);
    strcpy(pivo->nome, vetor[p].nome);
    pivo->telefone = vetor[p].telefone;

    ///STRCAT
    /*
    Ao comparar str1 com str2:
    resultado < 0 se str1 for menor que str2
    resultado > 0 se str1 for maior que str2
    resultado = 0 se forem iguais
    */

    while(i < j){
        while(strcmp(vetor[i].nome, pivo->nome) < 0 && i < q) i++;
        while(strcmp(vetor[j].nome, pivo->nome) > 0 && j > p) j--;
        if (strcmp(vetor[i].nome, vetor[j].nome) > 0){
            strcpy(aux->email, vetor[i].email);
            strcpy(aux->nome, vetor[i].nome);
            aux->telefone = vetor[i].telefone;

            strcpy(vetor[i].email, vetor[j].email);
            strcpy(vetor[i].nome, vetor[j].nome);
            vetor[i].telefone = vetor[j].telefone;

            strcpy(vetor[j].email, aux->email);
            strcpy(vetor[j].nome, aux->nome);
            vetor[j].telefone = aux->telefone;
        }
		else if (strcmp(vetor[i].nome, vetor[j].nome) == 0) j--;
    }
    free(aux);
    free(pivo);
    return i;
}

void quickSort(tp_contato *ptr_Contato,int p, int q){
    int r;

	r = partition(ptr_Contato, p, q);
	if(r-1 > p) quickSort(ptr_Contato, p, r-1);
	if(r+1 < q) quickSort(ptr_Contato, r+1, q);
}


#endif
