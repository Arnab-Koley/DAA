#include<stdio.h>
#define inf 999

int n,s,g[20][20],status[20],dist[20],pre[20];

/*
0 6 0 7 0
0 0 5 8 -4
0 -2 0 0 0
0 0 -3 0 9
2 0 7 0 0
*/


int bellmanford(){

	int i,c,u,v;

	for(i=1;i<=n;i++){
		status[i]=0;
		dist[i]=inf;
		pre[i]=0;
	}
	dist[s]=0;
	for(c=1;c<n;c++){
		for(u=1;u<=n;u++){
			for(v=1;v<=n;v++){
				if((dist[v]>(dist[u]+g[u][v])) && status[v]!=1 && g[u][v]!=inf){
					dist[v]=dist[u]+g[u][v];
					pre[v]=u;
				}
			}
		}
	}
	for(u=1;u<=n;u++){
		for(v=1;v<=n;v++){
			if((dist[v]>(dist[u]+g[u][v])) && status[v]!=1 && g[u][v]!=inf)
				return 0;
		}
	}
	return 1;
}


void path( int target){
    if(pre[target]==0){	
		printf("%d",target);
	}
	else{
		path(pre[target]);			
		printf("-->%d",target);
    }
}


void main(){

	int i,j;

	printf("\nEnter the no of verties : ");
	scanf("%d",&n);
	printf("\nEnter the graph :\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&g[i][j]);
			if(g[i][j]==0){
				g[i][j]=inf;
			}			
		}
	}
	printf("\nEnter the source vertex : ");
	scanf("%d",&s);

	if(bellmanford()){
		for(i=1;i<=n;i++){
        	printf("\nV%d to V%d : \n\tShortest Path : ",s,i);
        	if(i==1){
				printf("%d-->",s);
			}
       		path(i);
	    	printf("\n\tCost=%d",dist[i]);
    	}
	}
	else{
		printf("\nNegative Edge cycle present");
	}	
}

