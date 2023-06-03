#include<stdio.h>
int n,x[20],m,G[20][20];


/*
0 1 1 0 1
1 0 1 0 1
1 1 0 1 0
0 0 1 0 1
1 1 0 1 0
*/


void next_value(int k){
	
	int i,j;
	while(1){
		x[k]=((x[k]+1)%(n));
		if(x[k]==0){
			return;
		}
		for(j=1;j<=n;j++){
			if((G[k][j]!=0) && (x[k]==x[j])){
				break;
			}
		}
		if(j==n+1){
			return;

		}
	}
}

void m_coloring(int k){
	
	next_value(k);
	if(x[k]==0){
		return;
	}
	if(k==n){
		return;
	}
	else{
		m_coloring(k+1);
	}
}


int main(){

	int i,j;	
	printf("\nEnter the no. of vertices : ");
	scanf("%d",&n);
	printf("\nEnter the graph :\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&G[i][j]);
		}
	}
	for(i=1;i<=n;i++){
		x[i]=0;
	}

	m_coloring(1);

	for(i=1;i<=n;i++){
		printf("\nVertex-%d : Color-%d",i,x[i]);
	}
}
