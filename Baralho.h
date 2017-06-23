	#ifndef Baralho_H
	#define Baralho_H

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	//#include <stdio_ext.h>
	#include <time.h>

	int cartas_restantes=40;

	typedef struct _cartaBaralho{
	  int number; //corresponde ao número de cada carta
	  int naipe; //representa a naipe: 0 - Basto, 1- Espada, 2 - Ouro e 3 - Copa
	  struct _cartaBaralho *right;
	  struct _cartaBaralho *left;
	}TpCartaBaralho;

	TpCartaBaralho* Inserir(TpCartaBaralho *baralho,int naipe, int number);
	TpCartaBaralho* jogaMesa(TpCartaBaralho *mesa,TpCartaBaralho *player1,TpCartaBaralho *comp);
	TpCartaBaralho*  recolheMonte(TpCartaBaralho *mesa,TpCartaBaralho *player1,TpCartaBaralho *comp,TpCartaBaralho **montePlayer1);
	TpCartaBaralho*  drop(TpCartaBaralho* baralho,TpCartaBaralho* aux);
	void Embaralha(TpCartaBaralho *baralho,int *naipe,int *number);
	void InserirP(TpCartaBaralho **baralho,int naipe, int number);

	#endif
	/**/
