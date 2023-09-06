#include"stdio.h"


int getValue(int n){
	if(n==0)
		return 0;
	return n * n * n + getValue(n-1);	
}


int main(){
	int n;
	printf("\nNhap n: ");
	scanf("%d",&n);
	
	int sum =getValue(n); 
	printf("Tong luy thua bac ba  tu 1 den %d = %d\n",n,sum);
	
	return 0;
}
