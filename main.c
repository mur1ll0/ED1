#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "Baralho.h"

TpCartaBaralho* Inserir(TpCartaBaralho *head,int naipe, int number);

int main () {
  TpCartaBaralho *head = inicializa();

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
return 0;
}
