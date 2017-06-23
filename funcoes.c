	#include <stdio.h>
	#include <stdlib.h>
	#include "Baralho.h"
	/* função de inicialização */
	TpCartaBaralho* inicializa(){
		return NULL;
	}

	/* função de inserção  a inserção ocorre sempre no inicio*/
	void InserirP(TpCartaBaralho **baralho,int naipe, int number){
		TpCartaBaralho * novo =(TpCartaBaralho*) malloc(sizeof(TpCartaBaralho));
		novo->naipe = naipe;
		novo->number = number;
		novo->right = *baralho; // torna baralho como 2° elemento da lista

		if((*baralho)!= NULL){
			(*baralho)->left = novo; // insere sempre no inicio da lista tornando o novo sempre o 1° elemento
		}
		novo->left = NULL;

		(*baralho)=novo;
	}
	TpCartaBaralho *Inserir(TpCartaBaralho *baralho,int naipe, int number){
		TpCartaBaralho * novo =(TpCartaBaralho*) malloc(sizeof(TpCartaBaralho));
		novo->naipe = naipe;
		novo->number = number;
		novo->right = baralho; // torna baralho como 2° elemento da lista


		if(baralho!= NULL){
			baralho->left = novo; // insere sempre no inicio da lista tornando o novo sempre o 1° elemento
		}
		novo->left = NULL;
		//torna o novo como 1° elemento da lista

		return novo;
	}

	void Embaralha(TpCartaBaralho* baralho,int *naipe,int *number){
		TpCartaBaralho* aux = baralho;
		int n=2;
		srand(time(NULL));
		n = rand()%cartas_restantes;
		for(int i=1;i<=n;i++){
			if(i==n){
				//puts("------------------------------------------------------");
				// /printf("Posição da lista{%d}\n",n );
				//printf("Naipe {%d} \tNumero {%d}\n",aux->naipe,aux->number);
				*naipe=aux->naipe;
				*number=aux->number;
				cartas_restantes--;


			}
			aux=aux->right;
		}baralho = drop(baralho,aux);
	}

	void imprime (TpCartaBaralho* baralho){
		TpCartaBaralho* novo = baralho; // novo aponta para o elemento inicial

		if(novo == NULL){
			puts("Lista vazia");
		}else {
			int cont=0;// lista não está vazia
			do {
			printf("Naipe {%d} \tNumero {%d} \t posição {%d}\n",novo->naipe,novo->number,cont);
			//printf("%d\n",40%100 );
			novo = novo->right; 	// avança para o próximo nó
			cont ++;
		}while(novo != NULL);printf("Total de cartas{%d}\n",cont );
	}
}

	TpCartaBaralho* drop(TpCartaBaralho* baralho,TpCartaBaralho* aux){
		if(aux->right!=NULL)// ultimo
			aux->right->left=aux->left;

		if (aux!=baralho){//todos meio
			aux->left->right=aux->right;
			}
		else{
			baralho=aux->right;

		}

		free(aux);
		return baralho;
	}

	TpCartaBaralho *jogaMesa(TpCartaBaralho *mesa,TpCartaBaralho *player1,TpCartaBaralho *comp){
		TpCartaBaralho * novo = player1;
		printf("------------Cartas da Mesa----------------------------\n");
		imprime(mesa);
		puts("------------------------------------------------------");

		puts("Escolha a posição que contem a carta que deseja jogar");
		int entradaUS=0;
		scanf("%d",&entradaUS );
		puts("------------------------------------------------------");

		for(int i=0; i<3; i++){
			if(i==entradaUS){
				mesa = Inserir(mesa,novo->naipe,novo->number);
				player1= drop(player1,novo);
				imprime(mesa);
				imprime(player1);
			}
			novo=novo->right;
		}
		return mesa;
	}

TpCartaBaralho* recolheMonte(TpCartaBaralho *mesa,TpCartaBaralho *player1,TpCartaBaralho *comp,TpCartaBaralho **montePlayer1){

		TpCartaBaralho * novo = mesa;
		TpCartaBaralho *AUX = inicializa();
		int NCartas,PosicaoCarta,somatorio=0;
		int cont=0;int escopa=0;

		puts("____________________________________________");
		puts("Informe a quantidade de cartas para recolher");
		puts("____________________________________________");
		scanf("%d",&NCartas);

		for(int i=0; i<NCartas;i++ ){
			puts("____________________________________________");
			puts("Digite a posição da carta");
			puts("____________________________________________");
			scanf("%d",&PosicaoCarta);
			novo=mesa;
			puts("_____________Cartas atualmente na mesa______");
			imprime(mesa);
			puts("____________________________________________");
				for(int j=0; j<=PosicaoCarta;j++){

					if(j==PosicaoCarta){

						if(novo->number >=10 ){
							somatorio -= 2 ;
						}
						somatorio+=novo->number;

						AUX= Inserir(AUX,novo->naipe,novo->number);
						mesa= drop(mesa,novo);
						cont++;


						puts("cartas que ainda restão na mesa");
						imprime(mesa);
						puts("____________________________________________");

						puts("cartas ja recolhidas");
						imprime(AUX);
						puts("____________________________________________");
					}

						novo=novo->right;
				}
		}printf("somatorio %d\n",somatorio );
		TpCartaBaralho * Nnovo = AUX;
		if(somatorio==15){
					// /puts("if");
					for (int teste=0;teste<cont;teste++){
						InserirP(montePlayer1,Nnovo->naipe,Nnovo->number);
						AUX= drop(AUX,Nnovo);
						Nnovo=Nnovo->right;
					}
					//puts("cartas recolhidas para o monte do player1");
					//imprime(*montePlayer1);
					//puts("Cartas restantes na mesa");
					//imprime(mesa);


		}else{
				for (int teste=0;teste<cont;teste++){
				mesa = Inserir(mesa,Nnovo->naipe,Nnovo->number);
				AUX= drop(AUX,Nnovo);

				Nnovo=Nnovo->right;
		}
		puts("Jogada não foi o suficiente para recolher voltou pra mesa");
		imprime(mesa);
	}if(mesa==NULL){
			escopa++;
			printf("Escova\n" );
	}

return mesa;
}
