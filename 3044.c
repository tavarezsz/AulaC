#include <stdio.h>
#include <stdlib.h>

#define tam 5


void dfs(int v, int niv, int N, int **g,int *nivel){
	nivel[v] = niv;
	
	for(int i=0;i<=N;i++){
		if(g[v][i] ==1 && nivel[i] == -1){
			g[v][i] = 2;
			g[i][v] = 0;
			dfs(i,niv+1,N,g,nivel);
		}
	}
	
}



int lowpt(int v, int N, int **g, int *nivel,int *low){
	if(low[v] !=-1) 
		return low[v];
		
	low[v]=v;
		
	for(int i=0;i<=N;i++){
		if(g[v][i] == 2 && nivel[lowpt(i,N, g, nivel,low)] < nivel[low[v]]){
			
			low[v] = low[i];
		}
		else{
			if(g[v][i]==1 && nivel[i]<nivel[low[v]])
				low[v] = i;
		}
		
	}
	return low[v];
	
}

int isArt(int v,int N,int raiz,int *low,int **g){
    
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
    	
	for(int i = 0; i<=N;i++){
	    
		if(g[v][i] == 2){ 
		    
		    if (low[i] == v || low[i] == i) //se o low do filho for o pai ou ele mesmo
			    return 1;
		}
	}
	return 0;
}

int main(){
    
	int n,ar,x,y, cont=1;
	
	scanf("%d %d",&n,&ar);


    int nivel1[n];
    int low1[n];
    
    int **m = (int **)malloc(sizeof(int)*n);

    for(int i=0;i<=n;i++){
		nivel1[i] = -1;
		low1[i] = -1;
	}

    for(int i=0;i<=n;i++){
		m[i] = (int *)malloc(sizeof(int) * n);
        for (int j = 0; j <= n; j++)
        {
            m[i][j] = 0;
        }
        
	}


	
	for(int i=0;i<=ar;i++){
		scanf("%d %d",&x,&y);
		x--;y--;
        m[x][y] = 1;
        m[y][x] = 1;
	}
	
	


	
	
	
	
	dfs(0,0,n,m,nivel1);
    int raiz = lowpt(0,n,m,nivel1,low1);
    
    for(int i=0;i<=n;i++){
        
        printf("%d - %d %d\n",i,nivel1[i],low1[i]);
        
	}
	
	for(int i=0;i<=n;i++){
        for (int j = 0; j <= n; j++)
        {
            printf("%d ",m[i][j]);
        }
        
        printf("\n");
        
	}
	
	
    for(int i=0;i<=n;i++){
        if(isArt(i,n,0,low1,m) == 1)
            printf("%d",i+1);
    }
	
	
}
