	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	//#include <stdio_ext.h>
	#include "Baralho.h"
	#include "funcoes.c"
	#include <time.h>

	int main (void) {

		int number=0,naipe=0;
		TpCartaBaralho *baralho = inicializa();
		TpCartaBaralho *player1 = inicializa();
		TpCartaBaralho *comp = inicializa();
		TpCartaBaralho *mesa = inicializa();
		TpCartaBaralho *montePlayer1 = inicializa();
		TpCartaBaralho *monteComp = inicializa();

		// CRIA BARALHO
		for (int i=0; i<=3; i++){
			for(int j=1; j<=12; j++){
				if ((j != 0) && (j != 8) && (j != 9)){
					baralho = Inserir(baralho,i,j);
					printf("Carta Naipe [%d]\t Number [%d]\t\n",i,j);//IMPRIME BARALHO
				}
			}
		}

		puts("------------------------------------------------------");
		for(int cont=0;cont<3;cont++){

			Embaralha(baralho,&naipe,&number);
			player1 = Inserir(player1,naipe,number);

		}
		printf("------------Cartas do player--------------------------\n");
		imprime(player1);
		puts("------------------------------------------------------");

		puts("------------------------------------------------------");
		for(int cont=0;cont<3;cont++){
			Embaralha(baralho,&naipe,&number);
			comp = Inserir(comp,naipe,number);

		}

		printf("------------Cartas do comp----------------------------\n");
		imprime(comp);
		puts("------------------------------------------------------");



		for(int cont=0;cont<4;cont++){
			Embaralha(baralho,&naipe,&number);
			mesa = Inserir(mesa,naipe,number);
		}


			mesa = jogaMesa(mesa,player1,comp);


			mesa =recolheMonte(mesa,player1,comp,&montePlayer1);



			printf("\n\n\n\n\nMesa APOS jogada \n" );
			imprime(mesa);
			printf("\n\n\n\n\nMonte APOS jogada \n" );
 			imprime(montePlayer1);




			//monteComp = recolheMonte(mesa,player1,comp);
	/*
		printf("------------Cartas restantes no baralho-------------\n");
		imprime(baralho);
		puts("------------------------------------------------------");
		*/
		return 0;

	}
