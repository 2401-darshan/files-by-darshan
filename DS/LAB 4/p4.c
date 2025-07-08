#include<stdio.h>
void main(){
	int n,i, pos,number;
	printf("enter array size:");
	scanf("%d",&n);
	
	int arr[n+1];
	
	for(i=0;i<n;i++){
		printf("enter array elements arr[%d] : ",i);
		scanf("%d",&arr[i]);
	}
	printf("enter number to delete element:");
	scanf("%d",&pos);
	
	for(i=0;i<n;i++)
	{
		if(arr[i]==pos){
			arr[n+1]=arr[i];	
		}
		if(arr[i]>pos){
				arr[i-1]=arr[i];
		}	
	}
	n--;
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}	
}