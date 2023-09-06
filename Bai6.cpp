#include"stdio.h"


//int  getSum(int n){ 
//	int tong = 0;
//	for(int i=0; i<=n; i++){
//		int value = (i%2==0) ? i : -i ;
//		tong += value; 
//	} 
//	return tong; 
//} 

int getSum(int n){
	if(n==1){
		return -1; 
	}else{
	
		int value = (n%2==0) ? n : -n;
		return value + getSum(n-1);	
	}	
} 

int main(){
	int n;
	printf("\nNhap n: ");
	scanf("%d",&n);
//	int tong = getSum(n);
//	printf("\nTong cau bieu thuc = %d ",tong); 
	int value = getSum(n);
	printf("\nTong cau bieu thuc = %d ",value); 
	return 0; 
} 
