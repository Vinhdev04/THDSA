#include"stdio.h" 
#include"math.h"

struct PhanSo{
	int tu;
	int mau; // mau !=0
};

void nhap(PhanSo *ps){
	printf("\nNhap tu: ");
	scanf("%d",&ps->tu);
	do{
		printf("\nNhap mau: ");
		scanf("%d",&ps->mau);
	}while(ps->mau==0);
}

void rutGonPhanSo(PhanSo *ps){
		int a = ps->tu;
		int b = ps->mau;
		
		
		a = abs(a);
		b = abs(b);
		int USCLN = 1;
		if(a==0 || b==0){
			USCLN = (a+b);
		}else{
			while(a!=b){
				if(a>b){
					a = a-b;
				}else{
					b = b-a;
				}
			}
			USCLN = a;
		}
		ps->tu /= USCLN;
		ps->mau /= USCLN;
			
}

void xuat(PhanSo ps){
	if(ps.mau<0){
		ps.tu *= -1;
		ps.mau *= -1;
	}
	rutGonPhanSo(&ps);
	if(ps.mau==1){
		printf("%d",ps.tu);
	}else{
		printf("%d/%d",ps.tu,ps.mau);
	}
	
}



PhanSo congPhanSo(PhanSo &ps1, PhanSo &ps2){
	PhanSo ketQua;
	ketQua.tu = ps1.tu*ps2.mau + ps2.tu*ps1.mau;
	ketQua.mau = ps1.mau*ps2.mau;
	return ketQua;
}

PhanSo truPhanSo(PhanSo &ps1, PhanSo &ps2){
	PhanSo ketQua;
	ketQua.tu = ps1.tu*ps2.mau - ps1.tu*ps2.mau;
	ketQua.mau = ps1.tu*ps2.mau;
	return ketQua;
}

PhanSo nhanPhanSo(PhanSo &ps1, PhanSo &ps2){
	PhanSo ketQua;
	ketQua.tu = ps1.tu*ps2.tu;
	ketQua.mau = ps1.mau*ps2.mau;
	return ketQua;
}

PhanSo chiaPhanSo(PhanSo &ps1,PhanSo &ps2){
	PhanSo ketQua;
	ketQua.tu = ps1.tu*ps2.mau;
	ketQua.mau = ps1.mau*ps2.tu;
	return ketQua;
}

PhanSo timPhanSoMax(PhanSo a[],int n){
	PhanSo max = a[0];
	for(int i=0; i<n; i++){
		if(a[i].tu*max.mau>max.tu*a[i].mau){
			max = a[i]; 
		} 
	} 
	return max; 
} 

int demPhanSoMax(PhanSo a[],int n){
	PhanSo max = timPhanSoMax(a,n);
	int count =0;
	for(int i=0; i<n; i++){
		if(a[i].tu*max.mau == max.tu*a[i].mau){
			count++;
		}
	}
	return count;
} 

void SortPhanSo(PhanSo a[],int n){
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(a[i].tu*a[j].mau > a[j].tu*a[i].mau){
				PhanSo temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
} 

int main(){
	

	
//	PhanSo ps1,ps2;
//	printf("\nPhan so 1: ");
//	nhap(&ps1);
//	printf("\nPhan so 2: ");
//	nhap(&ps2);
//	printf("\nPhan so vua nhap: ");
//	xuat(ps1);
//	printf("\t");
//	xuat(ps2);
//	
//	printf("\nCong hai phan so: ");
//	xuat(ps1); printf(" + ");xuat(ps2);printf(" = ");xuat(congPhanSo(ps1,ps2));
//	
//	printf("\nTru hai phan so: ");
//	xuat(ps1);printf(" - ");xuat(ps2);printf(" = ");xuat(truPhanSo(ps1,ps2));
//	
//	printf("\nNhan hai phan so: ");
//	xuat(ps1);printf(" x ");xuat(ps2);printf(" = ");xuat(nhanPhanSo(ps1,ps2));
//	
//	printf("\nChia hai phan so: ");
//	xuat(ps1);printf(" / ");xuat(ps2);printf(" = ");xuat(chiaPhanSo(ps1,ps2));
	
		int n; 
	printf("NHAP SO LUONG PHAN SO: ");
	scanf("%d",&n); 
	
	PhanSo a[100]; 
	for(int i=0; i<n; i++){
		printf("\n\n\tNHAP PHAN SO THU %d: ",i+1);
		nhap(&a[i]); 
	} 
	
	printf("\n\n\tCAC PHAN SO VUA NHAP: \n");
	for(int i=0; i<n; i++){
		xuat(a[i]);
		printf("\t"); 
	} 
	
	printf("\n\n\tTONG CAC PHAN SO: ");
	PhanSo tong = a[0];
	for(int i=1; i<n; i++){
		tong = congPhanSo(tong,a[i]);
	}
	xuat(tong);
	
	printf("\n\n\tPAHN SO LON NHAT: ");
	PhanSo max = timPhanSoMax(a,n);
	xuat(max); 
	
	int countMax = demPhanSoMax(a,n);
	printf("\n\n\tSO LUONG PHAN SO LON NHAT: %d",countMax);
	
	
	printf("\n\n\tDAY PHAN SO SAU KHI SORT: \n");
	timPhanSoMax(a,n);
	for(int i=0; i<n; i++){
		xuat(a[i]);	
		printf("\t");
	}
	
	return 0;
}
