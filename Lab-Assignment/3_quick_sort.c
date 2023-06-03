#include<stdio.h>

int arr[100],n;

int partition(int low, int high){
    int i=low,j=high,p=low,t;
    while(i<j){
        while(arr[p]>=arr[i]){
            i++;
        }
        while(arr[p]<arr[j]){
            --j;
        }
        if(i<j){
            t=arr[i];
            arr[i]=arr[j];
            arr[j]=t;
        }
    }
    t=arr[p];
    arr[p]=arr[j];
    arr[j]=t;
    return j;

}


void quick_sort(int low, int high){
    int j;
    if(low<high){
        j=partition(low,high);
        quick_sort(low,j-1);
        quick_sort(j+1,high);
	}
}

int main(){

	int i,ch;
	printf("\nEnter the size of the array : ");
	scanf("%d",&n);
	printf("\nEnter the %d elements of the array : ",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);		
	}

    printf("\nThe array before quick sorting : ");
    for(i=0;i<n;i++){
	    printf("%d ",arr[i]);}
	
    quick_sort(0,n-1);
                
    printf("\nThe array after quick sorting : ");
    for(i=0;i<n;i++){
	    printf("%d ",arr[i]);}
				
return 0;
}