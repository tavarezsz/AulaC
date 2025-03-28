#include <stdio.h>
#include <stdlib.h>

struct el {
	int info;
	struct el *prox;
	};

typedef struct el elemento;

elemento *inicio;

void insereinicio(int val) {

	elemento *novo = (elemento*)malloc(sizeof(elemento));
	novo->info = val;
	novo->prox = NULL;

	if(inicio == NULL) {
		inicio = novo;
	}
	else {
		novo->prox = inicio;
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
	novo->prox = aux;
	
}

void remover(int val){
    //terminar
    elemento *aux = inicio, *ant = inicio;
    
    if(inicio->info == val){ //remover o primeiro
        inicio = inicio->prox;
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
    
    if(aux!=NULL){
        ant->prox = aux->prox;
        free(aux);
    }

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

void insereCirc(int val){
	elemento *novo, *aux;
	novo->info = valor;
	novo->prox = NULL;
	
	if(inicio == NULL){
		novo->prox = novo;
		inicio = novo;
	}
	else{
		if(inicio->prox == inicio){
			inicio->prox = novo;
			novo->prox = inicio;
		}
		else{//inserir no fim
			aux = inicio;
			while(aux){
				if(aux->prox)
			}
			
		}
	}
	
	
}
    

int main()
{
    //testes
	inicio=NULL;
	insereinicio(5);
	inserefim(8);
	inserefim(12);
	insereordenado(9);
	insereordenado(9);
	
	escreveLista(inicio);
	
	inverteLista();
	escreveLista(inicio);


	return 0;
}
