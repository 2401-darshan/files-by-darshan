#include<stdio.h>
void main(){
	 int sec,hh,mm;
	 printf("enter sec:");
	 scanf("%d",&sec);
	 hh=sec/3600;
	 sec=sec%3600;
	 mm=sec/60;
	 sec=sec%60;
	 
	 printf("%d::%d::%d",hh,mm,sec);
	 
	 
}
