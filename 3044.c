#include <stdio.h>
#include <stdlib.h>

#define tam 4

int nivel[tam];
int low[tam];


int g[tam][tam] = {
	{0,1,0,0},
	{0,1,1,0},
	{0,0,1,1},
	{0,0,1,0},
};




void dfs(int v, int niv, int N){
	nivel[v] = niv;
	
	for(int i=0;i<N;i++){
		if(g[v][i] ==1 && nivel[i] == -1){
			g[v][i] = 2;
			g[i][v] = 0;
			dfs(i,niv+1,N);
		}
	}
	
}



int lowpt(int v, int N){
	if(low[v] !=-1) 
		return low[v];
		
	low[v]=v;
		
	for(int i=0;i<N;i++){
		if(g[v][i] == 2 && nivel[lowpt(i,N)] < nivel[low[v]]){
			
			low[v] = low[i];
		}
		else{
			if(g[v][i]==1 && nivel[i]<nivel[low[v]])
				low[v] = i;
		}
		
	}
	return low[v];
	
}

int isArt(int v,int N){
	
	for(int i = 0; i<N;i++){
		if(g[v][i] == 2 && low[i] == v){ //se o low do filho for o pai
			return 1;
		}
	}
	return 0;
}

int main(){
	
	
	for(int i=0;i<tam;i++){
		nivel[i] = -1;
		low[i] = -1;
	}

	

	int n,m,x,y, cont=1;
	
	scanf("%d %d",&n,&m);
	
	for(int i=0;i<n;i++){
		scanf("%d %d",&x,&y);
	}
	
	
	
	dfs(0,0,tam);
	int raiz = lowpt(0,tam);
	
	printf("%d", isArt(2,tam));
	
	
}
