#include <stdio.h>
#include <stdlib.h>

//listas duplas
struct el {
	int info;
	struct el *prox, *ant;
	};

typedef struct el elemento;

elemento *inicio;

void insereinicio(int val) {

	elemento *novo = (elemento*)malloc(sizeof(elemento));
	novo->info = val;
	novo->prox = NULL;

	if(inicio == NULL) {
		inicio = novo;
		inicio->ant = NULL;
	}
	else {
		novo->prox = inicio;
		inicio->ant=novo;
		inicio = novo;

	}
	

}
void inserefim(int val) {
	elemento *aux = inicio;

	elemento *novo = (elemento*)malloc(sizeof(elemento));
	novo->info = val;
	novo->prox = NULL;

	if(inicio == NULL) {
		inicio = novo;
	}
	else {
		while(aux->prox !=NULL)
			aux = aux->prox;
		aux->prox = novo;
		novo->ant=aux;
	}
	

}
void escreveLista( elemento *ini) {

	if(ini!=NULL){
		printf("%d ",ini->info);
		ini = ini->prox;	
		escreveLista(ini);
	}
	else{
		printf("\n");
	}

}

void insereordenado(int val) {
    
    //A lista tem que estar ordenada para funcionar
	elemento *aux = inicio, *ant = inicio;
	elemento *novo = (elemento*)malloc(sizeof(elemento));
	novo->info = val;
	novo->prox = NULL;
	
	if(inicio==NULL){
	    inicio = novo;
    	return;
	}
    else if(novo->info <= inicio->info){ //se for o menor elemento
        insereinicio(val); 
        return;
    }

	while(aux != NULL && aux->info < novo->info) {
	    if(aux->prox == NULL){ //se for o maior elemento da lista
	        inserefim(val);
	        return;
	    }
		ant=aux;
		aux=aux->prox;
	}
	
	ant->prox=novo;
	novo->ant = ant;
	novo->prox = aux;
	aux->ant = novo;
	
}

void remover(int val){
    elemento *aux = inicio, *ant = inicio;
    
    if(inicio->info == val){ //remover o primeiro
        inicio = inicio->prox;
        inicio->ant=NULL;
        free(aux);
        return;
    }

    while(aux!=NULL && aux->info !=val){
        if(aux->prox ==NULL && aux->info == val){//se for o maior valor
            ant->prox = NULL;//desalocar do penultimo
            free(aux);
        }

        ant=aux;
        aux = aux->prox;
    }
    
    
    if(aux!=NULL){//remoção no meio
        ant->prox = aux->prox;
        (aux->prox)->ant = ant;
        free(aux);
        return;
    }
    else
    	printf("Valor não encontrado na lista");

}

void inverteLista(){
	elemento *aux = inicio;
	elemento *tmp;

	inicio = inicio->prox;
	aux->prox = NULL;
	
	while(inicio!=NULL){
		tmp = inicio;
		inicio = inicio->prox;
		tmp->prox = aux;
		aux = tmp;
	}
	
	inicio = aux;
	
	
}
    

int main()
{
    //testes
	inicio=NULL;
	insereinicio(5);
	insereordenado(7);
	inserefim(10);
	insereordenado(8);
	escreveLista(inicio);
	remover(5);
	remover(8);
	escreveLista(inicio);
	


	return 0;
}
