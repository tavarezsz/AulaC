#include <stdlib.h>
#include <stdio.h>

//grafo com lista encadeada

typedef struct nodo{int v; char nome[20];int visit; struct nodo *prox;} tnodo;

typedef struct grafo{int Nvert; tnodo **ladj;} tgrafo;

void insere(tgrafo G,int origem,int destino)
{
    tnodo *aux=(tnodo*)malloc(sizeof(tnodo));

    aux->prox=G.ladj[origem];
    aux->v=destino;
    aux->visit = -1; //flag dfs
    G.ladj[origem]=aux;
}

tgrafo cria_grafo(int N)
{
    tgrafo M;
    M.ladj=(tnodo**)calloc(N,sizeof(tnodo*));
    M.Nvert = N;
    return M;
}

void mostra_arestas(tgrafo G)
{
int i;
for (i=0;i<G.Nvert;i++)
	{
    printf("\n%d:\n",i);
	tnodo *aux=G.ladj[i];
	while (aux) //aux != NULL
		{

            printf("%d->%d  dist %d\n",i,aux->v,aux->visit);
            aux=aux->prox;
		}
	}	
}


void bfs(tgrafo G, int inicio) {
    
    int *percorridos = (int*)malloc(G.Nvert * sizeof(int));
    int quantPercorridos=0; //auxiliar para consulta

    G.ladj[inicio]->visit = 1;
    tnodo *ant = G.ladj[0];

    for (int i = inicio; i < G.Nvert; i++)
    {
        tnodo *aux = G.ladj[i];

        while (aux)
        {

            if(i==0){
                aux->visit = 1;
                aux = aux->prox;
                continue;
            }

            for(int j = 0;j<quantPercorridos;j++){//se já foi percorrido anteriormente, ignora
                if(aux->v == percorridos[j]){
                    aux = aux->prox;
                    if (aux==NULL)
                        //fzr um flag
                    
                }
                else
                    break;

            }

            //procurar a adjacencia do vertice atual
            int cont=0;
            ant = G.ladj[cont++];
            while (ant && cont < G.Nvert)
            {

                if(ant->v ==i){
                    aux->visit = ant->visit+1;
                    percorridos[quantPercorridos++] = aux->visit;
                    aux = aux->prox;
                    break;
                }

                ant = ant->prox;
                if(ant==NULL)
                {
                    ant = G.ladj[cont++];

                }
            }
    
            
        }
        

    }
    free(percorridos);
}


void dfs(tgrafo G){
    tnodo *aux;

    for(int i=0; i<G.Nvert;i++){
        aux = G.ladj[i];
        aux->visit=1;
        printf("\nvert :%d\n",i);
        while (aux->prox !=NULL)
        {
            aux->visit=1;
            printf("%d\n",aux->v);
            aux = aux->prox;
        }
    }

}

int main()
{
tgrafo M;
M=cria_grafo(7);
insere(M,0,1);
insere(M,1,2);
insere(M,2,3);
insere(M,1,4);
insere(M,0,2);
insere(M,3,4);
insere(M,4,5);

bfs(M,0);

mostra_arestas(M);

return 0;
}
