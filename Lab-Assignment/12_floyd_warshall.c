#include<stdio.h>
#define INF 9999

int n,G[10][10],D[10][10],P[10][10];

/*

0 8 0 1
0 0 1 0
4 0 0 0
0 2 9 0

*/


void print_matrix(){

	int i,j;
	printf("\nD matrix :\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
		    printf("%d\t",D[i][j]);	
        }
        printf("\n");
    }

    printf("\nP matrix :\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
		    printf("%d\t",P[i][j]);	
        } 
        printf("\n");
    }

}


void floyd(){
	int i,j,k;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){	
			D[i][j]=G[i][j];
			P[i][j]=0;
		}
	}
	for(k=1;k<=n;k++){		
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(D[i][j]>(D[i][k]+D[k][j])){
					D[i][j]=(D[i][k]+D[k][j]);
					P[i][j]=k;
				}
			}
		}
	}
}


int path(int i,int j){

	if(P[i][j]==0){		
	    return 0;
    }
	else{	
	    printf("-->%d",P[i][j]);
	    path(P[i][j],j);
    }
}



int main(){

	int i,j,s,t;

	printf("\nEnter the no. of  vertex : ");
	scanf("%d",&n);

	printf("\nEnter the cost matrix elements : \n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&G[i][j]);
			if(G[i][j]==0 && i!=j){
				G[i][j]=INF;
			}
		}
	}

	printf("\nThe cost matrix is :\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%d\t",G[i][j]);
		}
		printf("\n");
	}
	
	floyd();
	print_matrix();

	for(s=1;s<=n;s++){	
		printf("\nFrom V%d",s);	
		for(t=1;t<=n;t++){
			printf("\n\tto V%d :\n\t\tPath = ",t);
			printf("%d",s);
			path(s,t);
			printf("-->%d",t);
			printf("\n\t\tCost=%d",D[s][t]);			
		}		
	}

    return 0;
}