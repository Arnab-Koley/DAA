#include<stdio.h>

int arr[100],n;

void merge(int low, int mid, int high){
    int i=low,j=mid+1,k=low,b[100];
    while((i<=mid) && (j<=high)){
        if(arr[i]<arr[j]){
            b[k++]=arr[i++];
        }
        else{
            b[k++]=arr[j++];
        }
    }
    while(i<=mid){
        b[k++]=arr[i++];
    }
    while(j<=high){
        b[k++]=arr[j++];
    }
    for(k=low;k<=high;k++){
        arr[k]=b[k];
    }
}

void merge_sort(int low, int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        merge_sort(low,mid);
        merge_sort(mid+1,high);
        merge(low,mid,high);
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
	
    printf("\nThe array before merge sorting : ");
    for(i=0;i<n;i++){
	    printf("%d ",arr[i]);}

    merge_sort(0,n-1);

    printf("\nThe array after merge sorting : ");
    for(i=0;i<n;i++){
	    printf("%d ",arr[i]);}

	
return 0;
}