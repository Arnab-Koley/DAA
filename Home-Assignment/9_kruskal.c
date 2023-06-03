#include<stdio.h>
#define INF 999
int G[20][20],n,parent[20],min,cost;

/*
0 8 1 5 0 0
8 0 5 0 3 0
1 5 0 5 6 4
5 0 5 0 0 2
0 3 6 0 0 6
0 0 4 2 6 0
*/

int find(int i){
	while(parent[i] != i){
        i=parent[i];
    }  
    return i;
}

void myunion(int i, int j){
	int a=find(i);
	int b=find(j);
	parent[a]=b;
}


void kruskal(){
	int i,j,edge;
	cost=0;
	edge=1;
	while(edge<n){
		int min = 999, a = -1, b = -1;
		for(i=1;i<=n;i++){
			for(j=1;j<n+1;j++){
				if(find(i) != find(j) && G[i][j] < min){
					min=G[i][j];
					a=i;
					b=j;
				}
			}
		}
		myunion(a, b);
        printf("\nedge : %d  ( V%d - V%d ) | cost = %d",edge,a,b,min);
		cost += min;
		edge++;
	}
	printf("\n\nMinimum cost= %d",cost);
}


int main(){

	int i,j;

	printf("\nEnter the no. of vertex : ");
	scanf("%d",&n);
	printf("\nEnter the graph :\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&G[i][j]);
			if(G[i][j]==0){
                G[i][j]=INF;
            }	
		}
	}

	printf("\n\nThe cost matrix :\n\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%d\t",G[i][j]);
		}
		printf("\n");
	}

	printf("\n\nMinimum Spanning Tree :\n");

	for(i=1;i<=n;i++){
        parent[i] = i;
    }

	kruskal();
}

