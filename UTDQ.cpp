#include<iostream>
#include<stdlib.h>
#include<iomanip>
#define MAX 100
using namespace std;

int u,o;
void UTDQ(int a[MAX][5], int b[MAX][5], int &m);

int main(){
	int m;
	int a[MAX][5] = {0};
	int b[MAX][5] = {0};
	UTDQ(a,b,m);
}

int count(int a){//Xac dinh so ky tu bang de quy
	if(a == 0) return 0;
	if(a > 0) return 1 + count(a / 10);
}
void sort(int b[MAX][5], int &m){//Su dung thuat toan Interchange Sort
	int bt = 0;
	for(int i = 1; i < m - 1; i++){//i bat dau tu 1 vi tien trinh dau tien giu mac dinh ko sap xep
		bt += b[i - 1][2];//Tinh thoi gian tien trinh da chay
		for(int j = i + 1; j < m; j++){
			if (b[i][3] > b[j][3] && bt > b[j][1]){//So sanh do uu tien cua tien trinh va xem tien trinh can chuyen da vao hang cho hay chua
				for(int k = 0; k < 4; k++){
					b[m][k] = b[i][k];
					b[i][k] = b[j][k];
					b[j][k] = b[m][k];
				}
			}
		}
	}
}

void input(int a[MAX][5], int b[MAX][5], int &m){
	do{
		system("cls");
		cout << "Nhap vao so luong tien trinh: ";
		cin >> m;
	} while (m <= 0);//Khi nguoi dung nhap 0 hoac nho hon 0 thi se bat nguoi dung nhap lai
	for(int i = 0; i < m; i++){
		a[i][0] = i + 1;
		b[i][0] = a[i][0];//nhap vao so thu tu tien trinh
		cout << "Nhap vao thoi diem vao va thoi gian xu ly cua tien trinh cua P" << a[i][0] << endl;
		cout << "Nhap thoi diem vao cua tien trinh P" << a[i][0] << ": ";
		cin >> a[i][1];
		b[i][1] = a[i][1];
		cout << "Nhap vao thoi gian xu ly cua tien trinh P" << a[i][0] << ": ";
		cin >> a[i][2];
		b[i][2] = a[i][2];
		cout << "Nhap vao do uu tien cua tien trinh P" << a[i][0] << ": ";
		cin >> a[i][3];
		b[i][3] = a[i][3];
	} 
}
void output(int a[MAX][5], int m){
	cout << endl << "--------------------CHIEN LUOC UU TIEN DOC QUYEN-------------------" << endl;
	cout << endl << right << setw(15) << "  Tien trinh  |";
	cout << right << setw(18) << "  Thoi diem vao  |";
	cout << right << setw(20) << "  Thoi gian xu ly  |";
	cout << right << setw(11) << "  Do uu tien" << endl;
	for(int i = 0; i < m; i++){
		cout << "--------------|-----------------|-------------------|--------------" << endl;
		cout << right << setw(7) << "P" << a[i][0] << right << setw(7) << "|" << right << setw(9) << a[i][1];
		cout << right << setw(9) << "|" << right << setw(10) << a[i][2] << right << setw(10) << "|" << right << setw(8) << a[i][3] << endl;
	}
}
void veHang(int b) {//Ke bang dieu phoi hoat dong
	cout << endl << "-------------|----";
	for (int i = 0; i < 5 * b + (b - 10); i++) {
		cout << "-";
	}
	cout << endl;
}
void DPHD(int a[MAX][5], int c[MAX][5], int &m){
	cout << endl << "Dieu phoi hoat dong cua tien trinh" << endl;
	int b = 0;
	for(int i = 0; i < m; i++){//Tinh tong thoi gian toan tien trinh
		b += a[i][2];
	}
	u = count(c[m - 1][1]);//Xac dinh so ky tu lon nhat cua thoi gian vao
	cout << "  Thoi gian  | ";
	if(b < 10){//Viet gia tri thoi gian cua dong "Thoi gian"
		for (int i = 0; i <= b; i++){//Viet gia tri cua thoi gian voi tong thoi gian nho hon 10
			cout << left << setw(5) << i;
		}
	} else {//Viet gia tri cua thoi gian voi tong thoi gian lon hon 10
		for (int i = 0; i <= 9; i++){
			cout << left << setw(5) << i;
		}
		for (int i = 10; i <= b; i++){
			cout << left << setw(6) << i;
		}
	}
	veHang(b);
	cout << " Su dung CPU |   ";
	int dem = 0;
	for (int i = 0; i < m - 1; i++){//Thuc hien trinh bay cho tien trinh tu 1 den m - 1
		for(int j = 0; j < a[i][2] - 1; j++){
			if(dem < 9) {
				cout << "P" << left << setw(4) << a[i][0];//trinh bay tu vi tri 0->9
			} else {
				cout << "P" << left << setw(5) << a[i][0];//trinh bay vi tri tu 10 tro len
			}
			dem++;
		}
		if(dem < 9) {//137->143 viet thu tu gia tri cuoi cung cua tien trinh
			cout << "P" << left << setw(2) << a[i][0];
		} else {
			cout << "P" << left << setw(3) << a[i][0];
		}
		cout << "|" << setw(1) << "";
		dem++;
		c[a[i][0] - 1][4] = dem;//tra ve thoi gian hoan thanh cua tien trinh
	}
	for(int i = 0; i < a[m - 1][2]; i++){//Thuc hien trinh bay cho tien trinh cuoi cung
		if(dem < 9) {
			cout << "P" << left << setw(4) << a[m - 1][0];//trinh bay tu vi tri 0->9
		} else {
			cout << "P" << left << setw(5) << a[m - 1][0];//trinh bay vi tri tu 10 tro len
		}
		dem++;
	}
	c[a[m - 1][0] - 1][4] = dem;//tra ve thoi gian hoan thanh cua tien trinh
	o = count(dem);// Xac dinh so ky tu lon nhat cua thoi gian hoan thanh
	veHang(b);
	cout << "   Hang cho  | ";
	dem = 0;
	int i = 0;
	while (i < m && dem < b){//dem<b de thoi gian hang cho khong vuot qua tong thoi gian
		int bt = 0;
		if (dem > 9) {
			bt = 1;
		}
		if (c[i][1] == dem) {
			cout << "P" << left << setw(4 + bt) << c[i][0];
			i++;
		} else {
			cout << setw(5 + bt) << "";
		}
		dem++; //vi tri cho lan tiep theo cua hang cho
	}
	cout << endl;
}

void TGLLHT(int c[MAX][5], int &m){
	cout << endl << "Thoi gian luu lai he thong cua tien trinh"<< endl;
	for(int i = 0; i < m; i++){
		cout << "P" << c[i][0] << " = " << right << setw(o) << c[i][4] << " - " << right << setw(u) << c[i][1] << " = " << c[i][4] - c[i][1] << endl;
	}
}

void TGC(int c[MAX][5], int &m){
	cout << endl << "Thoi gian cho trong he thong cua tung tien trinh" << endl;
	float tong = 0;
	int max = 0;
	for(int i = 0; i < m; i++){//Xac dinh gia tri lon nhat cua TGBD SD CPU
		c[i][4] -= c[i][2];
		if(max < c[i][4]){
			max = c[i][4];
		}
	}
	o = count(max);//Xac dinh so ky tu cua gia tri lon nhat cua TGBD SD CPU
	for(int i = 0; i < m; i++){
		cout << "P" << c[i][0] << " = ";
		if(c[i][4] == 0){//hien thi khi thoi gian cho cua tien trinh bang 0
			cout << 0 << endl;
		} else {//Hien thi thoi gian cua tien trinh khi thoi gian khac 0
			cout << right << setw(o) << c[i][4] << " - " << right << setw(u) << c[i][1] << " = ";
			c[i][4] -= c[i][1];
			cout << c[i][4] << endl;
			tong += c[i][4];
		}
	}
	cout << "Thoi gian cho trung binh = (" << c[0][4];
	for(int i = 1; i < m; i++){
		cout << " + " << c[i][4];
	}
	cout << ") : " << m << " = " << tong << " : " << m << " = " << tong / m << endl;
}
void UTDQ(int a[MAX][5], int b[MAX][5], int &m){
	input(a,b,m);//Nhap vao thong tin lan luot cac tien trinh
	system("cls");//xoa man hinh
	output(a,m);//Xuat ra man hinh theo dang bang
	sort(b,m);//sap xep lai theo thu tu uu tien cua tien trinh
	DPHD(b,a,m);
	TGLLHT(a,m);
	TGC(a,m);
	system("pause");//tam dung man hinh de xem truoc khi thoat
}
//Source code https://github.com/Famiesta/UTDQ