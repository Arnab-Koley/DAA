#include<stdio.h>
int n,front=0,rear=0,g[20][20],visited[20],q[20];

/*
0 1 0 1 1 0 0
1 0 1 0 0 1 1
0 1 0 0 0 0 0
1 0 0 0 0 0 0
1 0 0 0 0 0 0
0 1 0 0 0 0 0
0 1 0 0 0 0 0
*/



void dfs(int v){
	int i,j;
	printf("%d ",v);
	visited[v]=1;
	for(i=1;i<=n;i++){
		if((!visited[i]) && g[v][i]==1)
		dfs(i);
	}
}

void bfs(int v){
	int i;
	for(i=1;i<=n;i++){
		if(!visited[i] && g[v][i]==1){
			q[++rear]=i;
			visited[i]=1;
			printf("%d ",i);
		}
	}
	if(front<=rear){
		bfs(q[front++]);
	}
}

int main(){
	int i,j,s;
	printf("\nEnter the no of vertex : ");
	scanf("%d",&n);
	printf("\nEnter the graph :\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&g[i][j]);
		}
	}
	for(i=1;i<=n;i++){
		visited[i]=0;
	}
	printf("\nEnter the source vertex : ");
	scanf("%d",&s);
	printf("\nDFS : ");
	dfs(s);

	for(i=1;i<=n;i++){
		visited[i]=0;
		q[i]=0;
	}
	printf("\nBFS : %d ",s);
	visited[s]=1;
	bfs(s);
	return 0;
}