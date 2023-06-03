

#include<stdio.h>
int n;
int d[100],p[100],dmax,slot[100];
char id[100];
int job_sec(){
	int c=0,sump=0;
	int i,k;
	dmax=d[0];
	for(i=0;i<=n-1;i++){
		if(dmax<=d[i]){
			dmax=d[i];
		}
	}
	printf("\nmax deadline is-%d",dmax);
	for(i=0;i<=n-1;i++){
		slot[i]=-1;
		
	}
	for(i=0;i<=n-1;i++){
		k=d[i];
		while(k>0){
			if(slot[k]== -1){
				slot[k]=i;
				c++;
				sump+=p[i];
				break;
			}
			k--;
		}
		if(c==dmax)
		break;
	}
	return sump;
}
void print_details(){
	int i;
	printf("\nsorted id :\n");
	for(i=0;i<=n-1;i++)
	printf("%c ",id[i]);
	
	printf("\nsorted profit :\n");
	for(i=0;i<=n-1;i++)
	printf("%d ",p[i]);
	
	printf("\nsorted deadline :\n");
	for(i=0;i<=n-1;i++)
	printf("%d ",d[i]);
}
void sort()
{
	int i,j;
	int t;
	for(i=0;i<=n-1;i++)
	{
		for(j=0;j<=n-i-1;j++)
		{
			if(p[j]<p[j+1])
			{
				t=p[j];
				p[j]=p[j+1];
				p[j+1]=t;
				
				t=id[j];
				id[j]=id[j+1];
				id[j+1]=t;
				
				t=d[j];
				d[j]=d[j+1];
				d[j+1]=t;
			}
			
			
		}
		
	}
	
}

int main(){
	int i,j,k,max_p;
	printf("\nenter the no of jobs-");
	scanf("%d",&n);
	printf("\nenter the id:\n");
	for(i=0;i<=n-1;i++){
		scanf(" %c",&id[i]);
	}
	
	printf("\nenter the profit:\n");
	for(i=0;i<=n-1;i++){
		scanf("%d",&p[i]);
	}
	
	printf("\nenter the deadline:\n");
	for(i=0;i<=n-1;i++){
		scanf("%d",&d[i]);
	}
	sort();
	print_details();
	max_p=job_sec();
	printf("\nselected jobs in solution are :\n");
	for(i=0;i<=dmax;i++)
	{
		if(slot[i]!= -1){
			printf("%c ",id[slot[i]]);
		}
	}
	printf("\nmax profit : %d",max_p);
}