#include <stdio.h>
#include <stdlib.h>
#define min(a,b) (a)<(b)?(a):(b)

void strongconnect(int v,int *index,int tam, int **G,int *pilha,int *lowlink,int *onStack,int *nivel,int *pilhaCont){
	
	printf("Verificando %d\n",v);
	nivel[v] = *index;
	lowlink[v] = *index;
	*index++;
	pilha[*pilhaCont++] = v;
	onStack[v] = 1;
	
	int w;
	
	
	for(int i=0;i<tam;i++){
		if(G[v][i] > 0){//todos que tem relação
			if(nivel[i] == -1){
				strongconnect(i,index,tam,G,pilha,lowlink,onStack,nivel,pilhaCont);
				lowlink[v] = min(lowlink[v],lowlink[i]);
				
			}
			else if(!onStack[i])
				lowlink[v] = min(lowlink[v],nivel[i]);
		}
	}
	if(lowlink[v] == nivel[v]){
		do{ //nova componente
		printf("\n");
		
		w = pilha[*pilhaCont--];
		onStack[w] = 0;
		printf("%d",w);
	} while(w != v);
		
	}
	
	
}

void tarjan(int **G,int tam){
	
	int pilha[tam]={-1};
	int onStack[tam] = {0};
	int pilhaCont=0;
	
	int nivel[tam] = {-1};
	int lowlink[tam] = {0};
	
	int curIndex=0;
	
	for(int i=0;i<tam;i++)
		if(nivel[i] == -1)
			strongconnect(i,&curIndex,tam,G,pilha,lowlink,onStack,nivel,&pilhaCont);
}



int main(){
	
	int grafo[5][5]= {
	{0,1,0,0,0},
	{1,0,1,1,0},
	{0,1,0,1,0},
	{0,1,1,0,1},
	{0,0,0,0,0},
	};
	
	tarjan(grafo,5);
	
	return 0;
}
