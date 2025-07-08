#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
void main(){
	int n,i,j;
	printf("enter how many words you want to enter:");
	scanf("%d",&n);
	
	char arr[n][100];
	for(i=0;i<n;i++){
		printf("enter words:");
		scanf("%s",arr[i]);
	}
	printf("\n");
	int random=rand()%n;
	char ana[20];
	printf("selected word is: %s",arr[random]);
	printf("\n");
	
	printf("enter anagram of this word:");
	scanf("%s",ana);
	
	int length=strlen(arr[random]);
//	char copy1[n][100]=
	for(i=0;i<length;i++){
		for(j=i+1;j<length;j++){
			if(arr[random][i]>arr[random][j]){
				char temp;
				temp=arr[random][i];
				arr[random][i]=arr[random][j];
				arr[random][j]=temp;
			}
		}
	}
//	printf("%s",arr[random]);
	int length1=strlen(ana);
	for(i=0;i<length;i++){
		for(j=i+1;j<length;j++){
			if(ana[i]>ana[j]){
				char temp;
				temp=ana[i];
				ana[i]=ana[j];
				ana[j]=temp;
			}
		}
	}
	if(strcmp(arr[random],ana)==0){
		printf("entered word is anagram");
	}
	else{
		printf("entered word is not anagram");
	}
}

