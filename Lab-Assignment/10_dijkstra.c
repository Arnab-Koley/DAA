#include<stdio.h>
#define INF 9999;

/*

0 10 0 0 5
0 0 1 0 2
0 0 0 4 0
7 0 6 0 0
0 3 9 2 0

*/

int n,s,G[50][50],status[50],dist[50],pre[50];
	
void dijk(){
	
	int i,j,k,v,c,u,min;
		
	for(i=1;i<=n;i++){
		status[i]=0;
		dist[i]=G[s][i];
		pre[i]=0;
	}
	
	dist[s]=0;
	status[s]=1;
	
	for(c=1;c<=n;c++){
		min=INF;
		for(i=1;i<=n;i++){
			if(dist[i]<min && status[i]!=1){
				min=dist[i];
				u=i;
				
			}		
		}
		status[u]=1;
		for(v=1;v<=n;v++){
			if((dist[v]>(dist[u]+G[u][v])) && status[v]!=1){
				dist[v]=dist[u]+G[u][v];
				pre[v]=u;
			}	
		}
	}
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


int main(){
	
	int i,j,target;
	
	printf("Enter the no of vertices : ");
	scanf("%d",&n);
	printf("Enter the graph :\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&G[i][j]);
			if(G[i][j]==0)
			G[i][j]=INF;
		}
	}
	
	printf("\n\nThe cost matrix is :\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%d\t",G[i][j]);
		}
		printf("\n");
	}
	
	printf("\nEnter the source vertex : ");	
	scanf("%d",&s);
	
	dijk();

    for(i=1;i<=n;i++){
        printf("\nV%d to V%d : \n\tShortest Path : ",s,i);
        printf("%d-->",s);
        path(i);
	    printf("\n\tCost=%d",dist[i]);

    }
	
	return 0;

}