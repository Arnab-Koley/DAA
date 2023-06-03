#include<stdio.h>

int bin(int *a, int x, int low, int high){

	int mid;
	if(low>high){
	    return -1;
	}

	else{

		mid=(low+high)/2;

		if(x==a[mid]){
			return mid;
		}

		else if(x>a[mid]){
			return bin(a,x,mid+1,high);
		}

		else{
			return bin(a,x,low,mid-1);
		}
	}
}


int main(){

	int arr[20],i,n,s,j;

	printf("\nEnter size of array : ");
	scanf("%d",&n);
	printf("Enter %d elements(sorted) : ",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("\nEnter the element to search : ");
	scanf("%d",&s);
	j=bin(arr,s,0,n-1);
	printf("%d is found at position %d\n",s,j+1);

	return 0;
}