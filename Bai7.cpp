#include"stdio.h"

float  getSum(int n){
	if(n==1){
		return 1.0/2;
	}else{
		double phanSo  = (double)n/(n+1);
		return phanSo + getSum(n-1); 
	}	 
} 

int main(){
	int n;
	printf("\nNhap n = ");
	scanf("%d",&n);
	
	double tong =  getSum(n);
	printf("\nTong  = %f",tong); 
	return 0; 
} 
