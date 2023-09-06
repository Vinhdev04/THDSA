#include"stdio.h"

int giaiThua(int n){
	if(n==0)
		return 1;
	return n*giaiThua(n-1);	
}


int main(){
	long long int n;
	printf("\nNhap so luong phan tu: ");
	scanf("%d",&n);
	printf("%d! = %lld",n,giaiThua(n));
	
	return 0;
}
	
