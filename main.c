#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "Baralho.h"
#include <time.h>
TpCartaBaralho* Inserir(TpCartaBaralho *head,int naipe, int number);
TpCartaBaralho*  Embaralha(TpCartaBaralho *head,int *naipe, int *number);
int main () {
  int number,naipe;

  TpCartaBaralho *head = inicializa();
  TpCartaBaralho *player1 = inicializa();
  TpCartaBaralho *comp = inicializa();
  TpCartaBaralho *mesa = inicializa();
  TpCartaBaralho *montePlayer1 = inicializa();
  TpCartaBaralho *monteComp = inicializa();

  //Inserir Naipe Paus
  head = Inserir(head,0,1);
  head = Inserir(head,0,2);
  head = Inserir(head,0,3);
  head = Inserir(head,0,4);
  head = Inserir(head,0,5);
  head = Inserir(head,0,6);
  head = Inserir(head,0,7);
  head = Inserir(head,0,10);
  head = Inserir(head,0,11);
  head = Inserir(head,0,12);
  //Inserir Naipe Espada
  head = Inserir(head,1,1);
  head = Inserir(head,1,2);
  head = Inserir(head,1,3);
  head = Inserir(head,1,4);
  head = Inserir(head,1,5);
  head = Inserir(head,1,6);
  head = Inserir(head,1,7);
  head = Inserir(head,1,10);
  head = Inserir(head,1,11);
  head = Inserir(head,1,12);
  //Inserir Naipe Ouro
  head = Inserir(head,2,1);
  head = Inserir(head,2,2);
  head = Inserir(head,2,3);
  head = Inserir(head,2,4);
  head = Inserir(head,2,5);
  head = Inserir(head,2,6);
  head = Inserir(head,2,7);
  head = Inserir(head,2,10);
  head = Inserir(head,2,11);
  head = Inserir(head,2,12);
  //Inserir Naipe Copas
  head = Inserir(head,3,1);
  head = Inserir(head,3,2);
  head = Inserir(head,3,3);
  head = Inserir(head,3,4);
  head = Inserir(head,3,5);
  head = Inserir(head,3,6);
  head = Inserir(head,3,7);
  head = Inserir(head,3,10);
  head = Inserir(head,3,11);
  head = Inserir(head,3,12);


  imprime(head);
  for(int i=1;i<=3;i++){
    Embaralha(head,&naipe,&number);
    player1 = Inserir(player1,naipe,number);
    Embaralha(head,&naipe,&number);
    imprime(player1);
    //Embaralhado(head,n);
  }
return 0;
}
