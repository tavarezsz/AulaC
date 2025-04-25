#include <stdio.h>
#include <stdlib.h>

#define tam 5

int nivel[tam];
int low[tam];


int g[tam][tam] = {
	{0,1,1,0,0},
	{1,0,1,1,1},
	{1,1,0,0,0},
	{0,1,0,0,1},
	{0,1,0,1,0},
};




void dfs(int v, int niv, int N, int g**){
	nivel[v] = niv;
	
	for(int i=0;i<N;i++){
		if(g[v][i] ==1 && nivel[i] == -1){
			g[v][i] = 2;
			g[i][v] = 0;
			dfs(i,niv+1,N);
		}
	}
	
}



int lowpt(int v, int N, int g**){
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

int isArt(int v,int N,int raiz){
    
    int cont=0;
    if(v == raiz){
        for(int i = 0; i<N;i++){
    		if(g[v][i] == 2){ 
    		    cont++;

    		}
    	}
    	if(cont>1) return 1;
    	else return 0;
    }
    	
	for(int i = 0; i<N;i++){
	    
		if(g[v][i] == 2 && (low[i] == v || low[i] == i)){ //se o low do filho for o pai ou ele mesmo
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

	
	/*

	int n,m,x,y, cont=1;
	
	scanf("%d %d",&n,&m);
	
	for(int i=0;i<n;i++){
		scanf("%d %d",&x,&y);
	}
	*/
	
	
	
	dfs(0,0,tam);
	int raiz = lowpt(0,tam);
	
	for (int i = 0; i < tam; i++) {
	    printf("%d",low[i]);
	}
	
	printf("\n%d", isArt(0,tam,0));
	
	
}
