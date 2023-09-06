
#include"stdio.h"
#include"string.h"
#include"stdlib.h"

// Cau truc Date
struct DATE{
	int ngay;
	int thang;
	int nam;
};

// Ham Nhap Date
void nhapDATE(DATE *x){
	scanf("%d%*c%d%*c%d",&x->ngay,&x->thang,&x->nam);
}

// Ham xuat Date
void xuatDATE(DATE *x){
	printf("%02d/%02d/%04d",x->ngay,x->thang,x->nam);
}

// Cau truc SV
struct SinhVien{
	char maSV[20];
	char hoTen[30];
	float diemThi;
	DATE ngaySinh;
};

// Ham nhap 1 SV
void nhap1SV(SinhVien *x){
	printf("Nhap Ma SV: ");
	scanf("%s",&x->maSV);
	printf("Nhap Ten SV: ");
	fflush(stdin);
	gets(x->hoTen);
//	fgets(x->hoTen,sizeof(x->hoTen),stdin);
	printf("Nhap Diem Thi: ");
	scanf("%f",&x->diemThi);
	printf("Nhap Ngay Sinh: ");
	fflush(stdin);
	nhapDATE(&x->ngaySinh);
}

// Ham xuat 1 SV
void xuat1SV(SinhVien *x){
	printf("\n| %-17s | %-20s |    %0.1f    |  ",x->maSV,x->hoTen,x->diemThi);
	xuatDATE(&x->ngaySinh);
}

// Ham nhap so luong
int nhapN(){
	int n;
	do{
		printf("NHAP SO LUONG SINH VIEN: ");
		scanf("%d",&n);
	}while(n<=0);
	return n;
}

// Ham nhap DSSV
void nhapDSSV(SinhVien *x ,int n){
	for(int i=0; i<n; i++){
		printf("\tNHAP SINH VIEN THU %d:\n",i+1);
		nhap1SV(x+i);
	}
}

// Ham xuat DSSV
void xuatDSSV(SinhVien *x,int n){
	for(int i=0; i<n; i++){
		xuat1SV(x+i);
	}
}

// Ham tim sinh vien X

void timSVTheoTen(SinhVien *x,int n,const char *tenCanTim){
	printf("\nSINH VIEN CO TEN LA %s:  ",tenCanTim);
	for(int i=0; i<n; i++){
		if(stricmp(x[i].hoTen,tenCanTim) ==0 )
			xuat1SV(x+i);
	}
}

// Ham xuat SV co diem thi >= 5
void xuatSVDiemTren5(SinhVien *x,int n){
	printf("\nCAC SINH VIEN CO DIEM  >= 5:");
	for(int i=0; i<n; i++){
	if(x[i].diemThi >= 5)
		xuat1SV(x+i);
    }
}

// Ham dem so luong SV co diem thi > 8
int countSVTren8(SinhVien *x,int n){
	int count = 0;
	for(int i=0; i<n; i++){
		if(x[i].diemThi > 8){
			count ++;
		}
	}
	return count;
}

// Ham tim SV co diem cao nhat 
float diemMax(SinhVien *x,int n){
	int max = x[0].diemThi;
	for(int i=0; i<n; i++){
		if(x[i].diemThi>max){
			max = x[i].diemThi;
		}
	}
	return max;
}
void timSVDiemMax(SinhVien *x,int n,float maxDiem){
	printf("\nSINH VIEN CO DIEM CAO NHAT LA: ");
	for(int i=0; i<n; i++){
		if(x[i].diemThi==maxDiem){
			xuat1SV(x+i);
		}
	}
}

// Ham dem so luong sinh vien co diem thi cao nhat 
int countSVMax(SinhVien *x,int n){
	int count =0;
	int max = diemMax(x,n);
	for(int i=0; i<n; i++){
		if(x[i].diemThi==max){
			count++;
		}
	}
	return count;
}

// Ham sap xep SV tang theo diem thi
void SortTangTheoDiem(SinhVien *x,int n){
	for(int i=0; i<n-1; i++){
		for(int j= i+1; j<n; j++){
			if(x[i].diemThi>x[j].diemThi){
				SinhVien temp;
				temp = x[i];
				x[i] = x[j];
				x[j] = temp;
			}
		}
	}
}

// Ham sap xep SV tang theo ma SV
void SortTangTheoMa(SinhVien *x,int n){
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(x[i].maSV>x[i].maSV){
				SinhVien temp;
				temp = x[i];
				x[i] = x[j];
				x[j] = temp;
			}
		}
	}
}
int main(){
//	int n;
//	DATE *x = (DATE*)malloc(n*sizeof(DATE));
//	
//	nhapDATE(x);
//	xuatDATE(x);
//	
	int n = nhapN();
	SinhVien *x = (SinhVien*)malloc(n*sizeof(SinhVien));
	//nhap1SV(x);
	//printf("\n\n\nTHONG TIN SINH VIEN DA NHAP :\n");
	//xuat1SV(x);
	nhapDSSV(x,n);
	
	printf("\n\n\tDANH SACH SINH VIEN DA NHAP: \n");
	xuatDSSV(x,n);
	
	
	char tenMuonTim[30];
	printf("\n\n\tNHAP TEN SINH VIEN MUON TIM: ");
	fflush(stdin);
	gets(tenMuonTim);
	timSVTheoTen(x,n,tenMuonTim);
	
	xuatSVDiemTren5(x,n);
	
	printf("\nCO %d SINH VIEN CO DIEM THI  > 8 ",countSVTren8(x,n));
	
	float maxDiem = diemMax(x,n);
	timSVDiemMax(x,n,maxDiem); 
	
	printf("\nCO %d SINH VIEN CO DIEM THI CAO NHAT  ",countSVMax(x,n));
	
	SortTangTheoDiem(x,n);
	printf("\nDANH SACH SINH VIEN SAU KHI SORT TANG THEO DIEM:");
	xuatDSSV(x,n);
	
	SortTangTheoMa(x,n);
	printf("\nDANH SACH SINH VIEN SAU KHI SORT TANG THEO MA SV:");
	xuatDSSV(x,n);
	//free(x);
	free(x);
	return 0;
}
