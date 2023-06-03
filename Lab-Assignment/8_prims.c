#include<stdio.h>
#define inf 9999

/*
0 8 1 5 0 0
8 0 5 0 3 0
1 5 0 5 6 4
5 0 5 0 0 2
0 3 6 0 0 6
0 0 4 2 6 0

*/

int g[100][100],v[100],n,i,j,k,s;

int prims(){
	int min,v1,v2,mincost=0;
	
	for(i=1;i<=n;i++){
		v[i]=0;
	}
	v[s]=1;
	for(k=1;k<n;k++){
		min=inf;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(g[i][j]!=inf && v[i]==1 && v[j]==0){
					if(g[i][j]<min){
						min=g[i][j];
						v1=i;
						v2=j;
					}
				}
			}
		}
		printf("\nedge=%d(%d->%d)\n",k,v1,v2);
		v[v1]=1;
		v[v2]=1;
		mincost+=min;
	}
	return mincost;
	
}

int main(){
	int mincost;
	printf("Enter the no of vertices : ");
	scanf("%d",&n);
	printf("Enter the graph :\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&g[i][j]);
			if(g[i][j]==0){
				g[i][j]=inf;
			}
		}
	}
	printf("Enter the source vertex : ");
	scanf("%d",&s);
	mincost=prims();
	printf("\nMinimum cost =%d",mincost);

return 0;
}