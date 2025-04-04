#include <stdio.h>

#define inf 1000000000

int dijkstra(int G[5][5], int s, int t)
{
int count =0;
int d[5],visit[5];
int minArv[5];
for (int i=0;i<5;i++) {d[i]=inf;visit[i]=0;}
d[s]=0;
while(1)
   {
   int menor=inf;
   int vm=0;
   for (int i=0;i<5;i++){
    if (d[i]<menor && visit[i]==0)
        {
        menor=d[i];
        vm=i;
        }
    }
   if (menor==inf) break;
   //if (vm==t) break;
   visit[vm]=1;
   minArv[count++]=vm;
   for (int i=0;i<5;i++)
        if (G[vm][i]>0 && visit[i]==0 && d[i]>d[vm]+G[vm][i])
            d[i]=d[vm]+G[vm][i];
   }
	for(int i=0;i<5;i++){
   		printf("%d - %d\n",i,d[i]);

    }

    printf("Arvore minima\n");
    for(int i=0;i<5;i++){
        printf("%d -> ",minArv[i]);

    }
return d[t];
}

int main(){
    int graf[5][5]= {
        {0,2,2,0,0},
        {2,0,7,1,5},
        {2,7,0,3,0},
        {0,1,3,0,2},
        {0,5,0,2,0},
    };

    printf("\n%d",dijkstra(graf,4,3));
}

