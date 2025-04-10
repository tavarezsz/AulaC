#include <stdio.h>
#include <stdlib.h>

//1135 beecrowd
long long int lca(int s, int v,int *pai, int *dpai, int *nivel){
	long long int d=0;
	
	while(s!=v){
		if(nivel[s] > nivel[v]){
			d+=dpai[s];
			s=pai[s];
		}
		else if (nivel[v] > nivel[s]){
			d+=dpai[v];
			v=pai[v];
		}
		else{
			d=d+dpai[v]+dpai[s];
			s=pai[s];
			v=pai[v];
		}
	}
	return d;
}

int main(){

	
	int n,ai,li, s,t;
	
	int q;
	
	int *pai,*dpai,*nivel;
	

	
	while(1){
		
		scanf("%d",&n);
		if(n==0)
			break;
	
		pai = (int *)malloc(n*sizeof(int));
		dpai = (int *)malloc(n*sizeof(long long int));
		nivel = (int *)malloc(n*sizeof(int));

		pai[0]=0;
		dpai[0]=0;
		nivel[0]=0;
		
		for(int i = 1;i<n;i++){
			scanf("%d %d",&ai,&li);
			pai[i]=ai;
			dpai[i]=li;
			nivel[i]= nivel[ai]+1;
		}
		
		scanf("%d",&q);
		
		for(int i=0;i<q;i++){
			scanf("%d %d",&s,&t);
			if(i==q-1){
				printf("%lld",lca(s,t,pai,dpai,nivel));
			}
			else
				printf("%lld ",lca(s,t,pai,dpai,nivel));
		}
		printf("\n");
		
	}	
	return 0;
}
