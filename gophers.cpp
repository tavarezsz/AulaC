#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INF 1000000000

#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)

#define cont(i,j) F[j][i]
#define dir(i,j) (C[i][j]-F[i][j])

//wrong answer, descobir porque

typedef struct e{
    float x;
    float y;
}entity;

int bfs(int s,int t,int tam,int *visit,int *pai,int *fila,int *menor,int **F,int **C)
{
	int TD=0,PA=1,i;
	visit[s]=1;
	fila[0]=s;
	menor[s]=INF;
	while (visit[t]==0 && TD!=PA)
		{
		int v=fila[TD++];
		for (i=0;i<tam;i++)
			if (visit[i]==0 && (dir(v,i) || cont(v,i)))
				{
				visit[i]=1;
				pai[i]=v;
				menor[i]=min (menor[v], max(dir(v,i),cont(v,i)));
				fila[PA++]=i;
				}
		}
	if (visit[t]==0) return 0;
	int minval=menor[t];
	int aux=t;
	while (aux!=s)
		{
		int v=pai[aux];
		if (dir(v,aux)>=minval)
			F[v][aux]+=minval;
		else 
		   	F[aux][v]-=minval;
		aux=v;	
		}
	return 1;      
}

int main(){
	
	int n,m,s,v;
	scanf("%d %d %d %d",&n,&m,&s,&v);
	
	int numvert = n+m+2;


	int visits[numvert];
    int pais[numvert];
    int filas[numvert];
    int menors[numvert];
    int **f = (int**)malloc(numvert*sizeof(int*));
	int **g = (int**)malloc(numvert*sizeof(int*));

	entity gopher[n+1];
	entity holes[m];

    for (int i = 0; i < numvert; i++)
    {
		f[i] = (int*)malloc(numvert*sizeof(int));
		g[i] = (int*)malloc(numvert*sizeof(int));
        visits[i] = 0;
        for (int j = 0; j < numvert; j++)
        {
            f[i][j] = 0;
			g[i][j] = 0;
        }
        
    }
    
	
	float x,y;	
	for(int i = 1;i<n+1;i++){
		scanf("%f %f",&x,&y);
		gopher[i].x = x;
        gopher[i].y = y;
	}
	
	for(int i = 0;i<m;i++){
		scanf("%f %f",&x,&y);
		holes[i].x = x;
        holes[i].y = y;
	}
	
	//criar grafo
	float dist;
	float distMax = s*v;

    for (int i = 0; i < numvert; i++)
    {
        for (int j = 0; j < numvert; j++)
        {
            g[i][j] = 0;
        }
    }
    
	
	for(int i=1;i<n+1;i++){ 

        g[0][i] = 1; //tratando s
        g[i][0] = 1;

		
		for(int j=0;j<m;j++){
            
            g[j+(n+1)][numvert-1] = 1; //tratando t
            g[numvert-1][j+(n+1)] = 1; //tratando t

            float dx = holes[j].x - gopher[i].x;
			float dy= holes[j].y - gopher[i].y;
            dist = sqrt(dx*dx+dy*dy);
			
			if(dist <= distMax){
				g[i][j+n+1] = 1;
                g[j+n+1][i] = 1;
			}
				
		}
	}


	
    
	g[0][numvert-1] = 0;



    while (1)
    {

        int ftot=0,i;
        for (i=0;i<numvert;i++){
                ftot+=f[0][i];
                visits[i] = 0;
            }
        

        if(!bfs(0,numvert-1,numvert,visits,pais,filas,menors,f,g)){
            printf("%d",n-ftot);
            break;
        }
    
    }

}
