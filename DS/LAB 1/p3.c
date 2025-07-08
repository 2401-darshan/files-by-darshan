#include<stdio.h>
void main(){
	char c;
	
	printf("enter char:");
	scanf("%c",&c);
	
	if(c=='A'||c=='E'||c=='I'||c=='O'||c=='U'||c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
		printf("character is vowel");
	}
	else{
		printf("character is consonant");
	}
}
