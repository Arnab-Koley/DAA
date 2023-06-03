#include<stdio.h>
#define inf 9999

int mincost=0,visited[20],g[20][20],n,s;

/*
0 5 0 6 0 4 0 7
5 0 2 4 3 0 0 0
0 2 0 1 0 0 0 0
6 4 1 0 7 0 0 0
0 3 0 7 0 0 6 4
4 0 0 0 0 0 3 0
0 0 0 0 6 3 0 2
7 0 0 0 4 0 2 0

*/

void tsp(int i){

	int j,min=inf,pos;

	printf("(City-%d) --> ",i);
	visited[i]=1;
	for(j=1;j<=n;j++){
		if(g[i][j]<min && !visited[j]){
			min=g[i][j];
			pos=j;
		}
	}
	if(min != inf){
		mincost += min;
		tsp(pos);
	}
	else if(g[i][s]!=inf){
		printf("(City-%d)",s);
		mincost += g[i][s];
	}
}


void main(){

	int i,j;
	printf("\nEnter the number of cities : ");
	scanf("%d",&n);
	printf("\nEnter the Graph:\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&g[i][j]);
			if(g[i][j]==0){
				g[i][j]=inf;
			}		
		}
		visited[i]=0;
	}
	printf("\nEnter the starting city : ");
	scanf("%d",&s);
	printf("\nTravelling salesman's path :\n");
	tsp(s);
	printf("\n\nMinimum distance = %d",mincost);
}


