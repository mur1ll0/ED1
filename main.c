#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "Baralho.h"
#include <time.h>

/* função de inicialização */
TpCartaBaralho* inicializa(){
	return NULL;
}

/* função de inserção  a inserção ocorre sempre no inicio*/
TpCartaBaralho *Inserir(TpCartaBaralho *baralho,int naipe, int number){
	TpCartaBaralho * novo =(TpCartaBaralho*) malloc(sizeof(TpCartaBaralho));
	novo->naipe = naipe;
	novo->number = number;
	novo->right = baralho; // torna baralho como 2° elemento da lista

	if(baralho!= NULL){
		baralho->left = novo; // insere sempre no inicio da lista tornando o novo sempre o 1° elemento
	}
	baralho = novo; //torna o novo como 1° elemento da lista
	novo->left = NULL;
	return novo;
}

void Embaralha(TpCartaBaralho* baralho,int *naipe,int *number){
	TpCartaBaralho* aux = baralho;
	int n=2;
	srand(time(NULL));
	n = rand()%cartas_restantes;
	for(int i=1;i<=n;i++){
		if(i==n){
			puts("------------------------------------------------------");
			printf("Valor Randomico {%d}\n",n );
			printf("Naipe {%d} \tNumero {%d}\n",aux->naipe,aux->number);
			*naipe=aux->naipe;
			*number=aux->number;
			cartas_restantes--;
			puts("------------------------------------------------------");
			printf("Ainda temos {%d} cartas restantes\n\n\n",cartas_restantes );
		}
		aux=aux->right;
	}drop(baralho,aux);
}

void imprime (TpCartaBaralho* baralho){
	TpCartaBaralho* novo = baralho; // novo aponta para o elemento inicial
	puts("FUNÇÃO IMPRIME");
	// lista não está vazia
	do {
		printf("Naipe {%d} \tNumero {%d}\n",novo->naipe,novo->number);
		//printf("%d\n",40%100 );
		novo = novo->right; 	// avança para o próximo nó
	}while(novo != NULL);
}

void drop(TpCartaBaralho* baralho,TpCartaBaralho* aux){



	if(aux->right!=NULL)
	aux->right->left=aux->left;
	if (aux!=baralho)
	aux->left->right=aux->right;
	else
	baralho=aux->right;
	free(aux);
}

int main (void) {
	int number=0,naipe=0;

	TpCartaBaralho *baralho = inicializa();
	TpCartaBaralho *player1 = inicializa();
	TpCartaBaralho *comp = inicializa();
	TpCartaBaralho *mesa = inicializa();
	//TpCartaBaralho *montePlayer1 = inicializa();
	//TpCartaBaralho *monteComp = inicializa();

	//Inserir Naipe Paus
	baralho = Inserir(baralho,0,1);
	baralho = Inserir(baralho,0,2);
	baralho = Inserir(baralho,0,3);
	baralho = Inserir(baralho,0,4);
	baralho = Inserir(baralho,0,5);
	baralho = Inserir(baralho,0,6);
	baralho = Inserir(baralho,0,7);
	baralho = Inserir(baralho,0,10);
	baralho = Inserir(baralho,0,11);
	baralho = Inserir(baralho,0,12);
	//Inserir Naipe Espada
	baralho = Inserir(baralho,1,1);
	baralho = Inserir(baralho,1,2);
	baralho = Inserir(baralho,1,3);
	baralho = Inserir(baralho,1,4);
	baralho = Inserir(baralho,1,5);
	baralho = Inserir(baralho,1,6);
	baralho = Inserir(baralho,1,7);
	baralho = Inserir(baralho,1,10);
	baralho = Inserir(baralho,1,11);
	baralho = Inserir(baralho,1,12);
	//Inserir Naipe Ouro
	baralho = Inserir(baralho,2,1);
	baralho = Inserir(baralho,2,2);
	baralho = Inserir(baralho,2,3);
	baralho = Inserir(baralho,2,4);
	baralho = Inserir(baralho,2,5);
	baralho = Inserir(baralho,2,6);
	baralho = Inserir(baralho,2,7);
	baralho = Inserir(baralho,2,10);
	baralho = Inserir(baralho,2,11);
	baralho = Inserir(baralho,2,12);
	//Inserir Naipe Copas
	baralho = Inserir(baralho,3,1);
	baralho = Inserir(baralho,3,2);
	baralho = Inserir(baralho,3,3);
	baralho = Inserir(baralho,3,4);
	baralho = Inserir(baralho,3,5);
	baralho = Inserir(baralho,3,6);
	baralho = Inserir(baralho,3,7);
	baralho = Inserir(baralho,3,10);
	baralho = Inserir(baralho,3,11);
	baralho = Inserir(baralho,3,12);


	imprime(baralho);

	for(int cont=0;cont<3;cont++){

		Embaralha(baralho,&naipe,&number);
		player1 = Inserir(player1,naipe,number);

	}
	printf("------------Cartas do player--------\n");
	imprime(player1);

	for(int cont=0;cont<3;cont++){
		Embaralha(baralho,&naipe,&number);
		comp = Inserir(comp,naipe,number);

	}
	printf("------------Cartas do comp--------\n");
	imprime(comp);

	for(int cont=0;cont<4;cont++){
		Embaralha(baralho,&naipe,&number);
		mesa = Inserir(mesa,naipe,number);

	}
	printf("------------Cartas da Mesa--------\n");
	imprime(mesa);


	printf("------------Cartas restantes no baralho--------\n");
	imprime(baralho);

	return 0;
}
