#ifndef Baralho_H
#define Baralho_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

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
  //printf("naipe {%d} numero {%d}\n",novo->naipe,novo->number);
  return novo;

}
void imprime (TpCartaBaralho* head){
 TpCartaBaralho* p = head; // p aponta para o elemento inicial

 if (p != NULL){ // lista não está vazia
   do {
     printf("naipe {%d}\n", p->naipe); // imprime info do nó
     printf("numero {%d}\n", p->number);
     p = p->right; 	// avança para o próximo nó
   }while(p != head);
 }else{
   printf("\nA lista está vazia\n");
 }
}
#endif
/**/
