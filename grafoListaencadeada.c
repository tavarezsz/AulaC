#include <stdlib.h>
#include <stdio.h>

typedef struct nodo{int v; struct nodo *prox;} tnodo;

typedef struct grafo{int Nvert; tnodo **ladj;} tgrafo;

void insere(tgrafo G,int origem,int destino)
{
tnodo *aux=(tnodo*)malloc(sizeof(tnodo));
aux->prox=G.ladj[origem];
aux->v=destino;
G.ladj[origem]=aux;
}

tgrafo cria_grafo(int N)
{
grafo M;
M.ladj=(tnodo**)calloc(N,sizeof(tnodo*));
M.Nvert = N;
return M;
}

void mostra_arestas(tgrafo G)
{
int i;
for (i=0;i<G.Nvert;i++)
	{
	tnodo *aux=G.ladj[i];
	while (aux)
		{
		printf("%d->%d\n",i,aux->v);
		aux=aux->prox;	
		}
	}	
}

int main()
{
grafo M;
M=cria_grafo(3);
insere(M,0,1);
mostra_arestas(M);
insere(M,1,2);
mostra_arestas(M);
}
