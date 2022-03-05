#include<iostream>
using namespace std;
void nhapmang(int A[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "Nhap phan tu A[" << i << "]:";
		cin >> A[i];
	}
}
void xuatmang(int A[], int n) {
	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}

}
bool ktsnt(int n) {
	if (n < 2) return false;
	int d = 0;
	for (int i = 2; i < sqrt(n); i++) {
		if (n % i == 0) d=1;
	}
	if (d == 0) return true;
    return false;
}
void snt(int A[], int n) {
	for (int i = 0; i < n; i++) {
		if (ktsnt(A[i]) == true)  cout << A[i]<<" ";
	}
}
void mangdoixung(int A[], int n) {
	int d = 0;
	for (int i = 0; i < n / 2; i++) {
		if (A[i] == A[n - i]) d += 1;
	}
	if (d == n / 2) cout << "Day la mang doi xung." << endl;
	else cout << "Day khong phai mang doi xung." << endl;	
}
int xoaphantuk(int A[], int n) {
	int k;
	cout << "Nhap vi tri can xoa: "; cin >> k;
	if (k < 0 || k >= n) {
		xuatmang(A, n);
		return 0;
	}
	else {
		for (int i = 0; i < n; i++)
			A[k] = A[k + 1];
		n = n - 1;
		xuatmang(A, n);
		return 1;
	}
}
void max(int A[], int n) {
	int m = A[0];
	int vt;
	for (int i = 1; i < n; i++) {
		if (m < A[i]) { m = A[i]; vt = i; }
	}
	cout << vt << endl;	
}
int VTamdautien(int a[], int n)
{
	{
		for (int i = 0; i < n; i++)
			if (a[i] < 0)
				return i;
	}
	return -1;
}

int VtamLonNhat(int a[], int n)
{
	int i;
	int vitriammax = VTamdautien(a, n);
	if (vitriammax != -1)
	{
		for (i = vitriammax; i < n; i++)
			if (a[i]<0 && a[i]>a[vitriammax])
				vitriammax = i;
		cout << vitriammax << endl;
	}
	return -1;
}
int main() {
	int n;
	int A[100];
	cout << "Nhap n:";
	cin >> n;
	nhapmang(A, n);
	cout << "Cac phan tu trong mang la:" << endl; xuatmang(A, n);cout << endl;
	cout << "Cac so nguyen to trong mang la: " << endl;
	snt(A, n); cout << endl;
	mangdoixung(A, n);
	xoaphantuk(A, n); 
	cout << "\nPhan tu lon nhat trong mang co chi so la: ";
	max(A, n);
	cout << "Phan tu am lon nhat trong mang co chi so la:";
	VtamLonNhat(A, n);
	return 0;
}
