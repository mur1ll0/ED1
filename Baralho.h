#ifndef Baralho_H
#define Baralho_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <time.h>


typedef struct _cartaBaralho{
  int number; //corresponde ao número de cada carta
  int naipe; //representa a naipe: 0 - Basto, 1- Espada, 2 - Ouro e 3 - Copa
  struct _cartaBaralho *right;
  struct _cartaBaralho *left;
}TpCartaBaralho;


/* função de inicialização */
TpCartaBaralho* inicializa(){
	return NULL;
}

/* função de inserção  a inserção ocorre sempre no inicio*/
 TpCartaBaralho *Inserir(TpCartaBaralho *head,int naipe, int number){

  TpCartaBaralho * novo =(TpCartaBaralho*) malloc(sizeof(TpCartaBaralho));


  novo->naipe = naipe;
  novo->number = number;
  novo->right = head; // torna head como 2° elemento da lista

  if(head!= NULL){
    head->left = novo; // insere sempre no inicio da lista tornando o novo sempre o 1° elemento
  }
  head = novo; //torna o novo como 1° elemento da lista
  novo->left = NULL;

  return novo;

}

TpCartaBaralho* Embaralha(TpCartaBaralho* head,int * naipe,int *number){
  TpCartaBaralho* novo = head;


  int cartas_restantes=40,n=2;

  do {
     srand(time(NULL));
     n = rand()%cartas_restantes;

     for(int i=1;i<=n;i++){

       *naipe=novo->naipe;
       *number=novo->number;

      }

      novo=novo->right;
      cartas_restantes--;
  }while(cartas_restantes !=0 && novo != NULL);

return ;



};

void imprime (TpCartaBaralho* head){
 TpCartaBaralho* novo = head; // p aponta para o elemento inicial
 puts("FUNÇÃO IMPRIME");
  // lista não está vazia
   do {
     printf("Naipe {%d} \tNumero {%d}\n",novo->naipe,novo->number);
     //printf("%d\n",40%100 );
     novo = novo->right; 	// avança para o próximo nó
   }while(novo != NULL);

}

#endif
/**/
