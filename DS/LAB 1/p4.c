#include<stdio.h>
void main(){
	int a,b,c;
	
	printf("enter 3 numbers:");
	scanf("%d %d %d",&a,&b,&c);
	
	if(a>b){
		if(a>c){
			printf("%d is greatest",a);
		}
	}
	else if(b>c){
		if(b>a){
			printf("%d is greatest",b);
		}
	}
	else{
		printf("%d is greatest",c);
	}
}
