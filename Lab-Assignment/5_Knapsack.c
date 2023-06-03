#include<stdio.h>
int n,i;
float m,p[100],w[100],r[100],x[100];

void Fractional_knapsack(){
	
	float u,sum=0.0;

	for(i=0;i<n;i++){
		x[i]=0.0;
	}
	u=m;
	for(i=0;i<n;i++){
		if(w[i]>u){
			break;
		}
		x[i]=1.0;
		u=u-w[i];
	}
	if(i<=n){
		x[i]=u/w[i];
	}
	for(i=0;i<n;i++){
		sum=sum+(p[i]*x[i]);
	}
	printf("Solution vector : ");
	for(i=0;i<n;i++){
		printf("%f ",x[i]);
	}
	printf("\ntotal profit : %f",sum);
}

void main(){

	int j;
	float t;

	printf("\nEnter the number of items : ");
	scanf("%d",&n);
	printf("Enter the capasity of the knapsack : ");
	scanf("%f",&m);
	printf("Enter the weight & profit of %d items :\n",n);
	for(i=0;i<n;i++){
		scanf("%f%f",&w[i],&p[i]);
	}
	for(i=0;i<n;i++){
		r[i]=(p[i]/w[i]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(r[j]<r[j+1]){

				t=r[j];
				r[j]=r[j+1];
				r[j+1]=t;

				t=w[j];
				w[j]=w[j+1];
				w[j+1]=t;

				t=p[j];
				p[j]=p[j+1];
				p[j+1]=t;
			}
		}
	}

	Fractional_knapsack();

}