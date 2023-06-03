#include<stdio.h>
#include<math.h>

int n,c=0,x[20];


// void print_details(){
// 	int i,j;
// 	printf("\nSolution : %d\n\n",c+1);
// 	for(i=1;i<=n;i++){
// 		for(j=1;j<=n;j++){
// 			if(x[j]==i){
// 				printf("Q%d ",x[j]);
// 			}
// 			else{
// 				printf("-- ");
// 			}
// 		}
// 		printf("\n");
// 	}
// 	printf("\n");
// 	c++;
// }

void print_details(){
	
	int i,j,k;
	printf("\nSolution : %d\n\n",c+1);
	
	for(i=1;i<=n;i++){
		for(k=1;k<=(n);k++){
			printf("|----");
		}
		printf("|\n");
		for(j=1;j<=n;j++){
			if(x[j]==i){
				printf("| Q%d ",x[j]);
			}
			else{
				printf("|    ");
			}
		}
		printf("|\n");
		
	}
	c++;
	for(k=1;k<=(n);k++){
			printf("|----");
		}
		printf("|\n");
}



int place(int k,int i){
	int j;
	for(j=1;j<k;j++){
		if((x[j]==i) || (fabs(x[j]-i)==fabs(j-k))){
			return 0;
		}
	}
	return 1;
}


void n_queens(int k){
	int i,j;
	for(i=1;i<=n;i++){
		if(place(k,i)){
			x[k]=i;
			if(k==n){
				print_details();
			}
			else{
				n_queens(k+1);
			}
		}
	}
}



int main(){

	int k,i,j;
	 printf("\nEnter the no.of queen : ");
	 scanf("%d",&n);
	 for(i=1;i<=n;i++)
	 x[i]=0;
	 n_queens(1);
	 printf("Total no of solution : %d\n",c);

return 0;
}