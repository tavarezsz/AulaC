#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int n,m,s,v;
	scanf("%d %d %d %d",&n,&m,&s,&v);
	
	int numvert = n+m+2;
	
	int g[numvert][numvert];
	int gopher[n];
	int holes[m];
	
	int x;	
	for(int i = 0;i<n;i++){
		scanf("%d",&x);
		gopher[i] = x;
	}
	
	for(int i = 0;i<m;i++){
		scanf("%d",&x);
		holes[i] = x;
	}
	
	//criar grafo
	int dist;
	int distMax = s*v;
	
	for(int i=1;i<n;i++){ 

		g[0][i] = 1; //tratando s
		g[i][numvert-1] = 1; //tratando t
		
		for(int j=0;j<m;i++){
		
			dist = abs(gopher[i]) - abs(holes[j]);
			
			if(dist < distMax){
				printf("%d chega em %d",i,j);
				g[i][j] = 1;
			}
			else
				g[i][j] = 0;
				
		}
	}
	
	g[0][numvert-1] = 0;
	

	
}
