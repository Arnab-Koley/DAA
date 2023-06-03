#include<stdio.h>

int arr[100],n,max,min;

void maxmin(int i, int j){

    int max1, min1, mid;

    if(i==j){
        max=min=arr[i];
    }
    else if(i==j-1){

        if(arr[i]>arr[j]){
            max=arr[i];
            min=arr[j];
        }
        else{
            max=arr[j];
            min=arr[i];
        }
    }
    else{

        mid=(i+j)/2;

        maxmin(i,mid);

        max1=max;
        min1=min;

        maxmin(mid+1,j);

        if(max1>max){
            max=max1;
        }
        if(min1<min){
            min=min1;
        }
    }
}

int main(){

    int i;

	printf("\nEnter the size of the array : ");
	scanf("%d",&n);
	printf("\nEnter the %d elements of the array : ",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);		
	}
    maxmin(0,n-1);

    printf("The maximum is : %d\nThe minimum is : %d",max,min);

	return 0;
}