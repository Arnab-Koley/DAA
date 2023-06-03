#include<stdio.h>

int n,x[20],g[20][20],c=0,s=0;


/*

0 1 1 0 0 0 1 0
1 0 1 0 0 0 0 1
1 1 0 1 0 1 0 0
0 0 1 0 1 0 0 0
0 0 0 1 0 1 0 0
0 0 1 0 1 0 1 0
1 0 0 0 0 1 0 1
0 1 0 0 0 0 1 0

*/

void nextvalue(int k){
	int j=0;
	while(1){
		x[k]=(x[k]+1)%(n+1);
		if(x[k]==0){
			return;
		}
		if(g[x[k-1]][x[k]]==1){
			for(j=1;j<=k-1;j++){
				if(x[j]==x[k]){
					break;
				}						
			}
			if(j==k){
				if(k<n || ((k==n) && g[x[n]][x[1]]==1)){
					return;
				}
			}		
		}
	}
}


void hamilton(int k){ 

	x[1]=1;	
	int i;
	while(1){
 		nextvalue(k); 
 		if(x[k] == 0){
			return;
		}
 		if(k==n){
 			c=1;
 			s++;
			printf("\nCycle-%d : ",s);
 			for(i=1;i<=n;i++){
				printf("V%d --> ",x[i]); 	
			}	
			printf("V1");
	    }
 		else{
			hamilton(k+1); 
		}
 	}			
}


void main(){

	int i,j;
	printf("\nEnter the no. of vertices : ");
	scanf("%d",&n);
	printf("\nEnter the graph :\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&g[i][j]);
		}
		x[i]=0;
	}
	hamilton(2);
	if(c==0){
		printf("\nNo hamiltonian cycle present\n");
	}
	else{
		printf("\n\nTotal no. of hamiltonian cycle = %d",s);
	}		
}
