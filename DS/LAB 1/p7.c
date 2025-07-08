#include<stdio.h>
void main(){
	 int year,day,week;
	 printf("enter days:");
	 scanf("%d",&day);
	 
	 
	 
	 year=day/365;
	 day=day%365;
	 week=day/7;
	 day=day%7;
	 
	 printf("%d year::%d weak::%d day",year,week,day);
	 
	 
}
