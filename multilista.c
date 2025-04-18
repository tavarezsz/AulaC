#include <stdio.h>
#include <stdlib.h>

typedef struct fila{
	int nro;
	struct fila *prox;
}Fila;

typedef struct lista{
	int cod;
	struct lista * prox;
	Fila *primeiro,*ultimo;
}Lista;

Lista *inicioLista = NULL;

void insereinicio(int val) {

	Lista *novo = (Lista *)malloc(sizeof(Lista));
	novo->cod = val;
	novo->prox = NULL;
	novo->primeiro = NULL;
	novo->ultimo = NULL;

	if(inicioLista == NULL) {
		inicioLista = novo;
	}
	else {
		novo->prox = inicioLista;
		inicioLista = novo;
	}
}

void escrevelista(){
	Lista *aux = inicioLista;
	
	printf("\nLista:\n");
	
	while(aux){
		printf("%d ",aux->cod);
		aux=aux->prox;
	}
	printf("\n---------\n");
}

void enfileirar(int nfila, int valor){
	
	Lista *aux = inicioLista;
	Fila *novo;
	

	while(aux->cod!=nfila)
		aux = aux->prox;
	
	if(aux){
		novo = (Fila *)malloc(sizeof(Fila));
		novo->nro = valor;
		novo->prox = NULL;
		
		if(aux->primeiro == NULL){
			aux->primeiro = novo;
			aux->ultimo = novo;
		}
		else{
			(aux->ultimo)->prox = novo;
			aux->ultimo = novo;
		}
	}
	
}

int desenfileirar(int f){
	Lista *aux = inicioLista;
	Fila *faux;
	int res=-1;
	
	while(aux->cod!=f){
		aux=aux->prox;
	}
	if(aux){
		faux = aux->primeiro;
		if(faux){
			aux->primeiro = faux->prox;
			res = faux->nro;
			free(faux);	
		}	
	}
	
	return res;
	
	
	
}

void escrevefila(int f){
	Lista *aux = inicioLista;
	Fila *faux;
	

	
	while(aux->cod!=f){
		aux=aux->prox;
	}
	
	if(aux){
		printf("\nFila %d:\n",aux->cod);
		faux = aux->primeiro;
		
		while(faux){
			printf("%d ", faux->nro);
			faux = faux->prox;
		}
	}
	
	printf("\n---------\n");
	
	
	
}

int main(){
	
	insereinicio(1);
	insereinicio(2);
	escrevelista();
	enfileirar(1,2);
	enfileirar(1,3);
	enfileirar(1,4);
	escrevefila(1);
	printf("%d desenfileirado\n",desenfileirar(1));
	escrevefila(1);
	
}
