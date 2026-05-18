#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

// a. ham nhap mang
void nhapmang(int a[], int n){
    for(int i=0; i<n; i++){
        cout << "Nhap phan tu thu " << i+1 << ": ";
        cin >> a[i];
    }
}

// ham xuat mang
void xuatmang(int a[], int n){
    cout << "\nCac phan tu trong mang: ";
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
}

// ham kiem tra so chinh phuong
bool kiemtrasochinhphuong(int n){
    if(n < 0) return false;
    int sqrt_n = sqrt(n);
    return sqrt_n * sqrt_n == n;
}

// b in ra cac so chinh phuong trong mang
void inchinhphuong(int a[], int n){
    cout << "\nCac so chinh phuong trong mang: ";
    for(int i=0; i<n; i++){
        if(kiemtrasochinhphuong(a[i])){
            cout << a[i] << " ";
        }
    }
}

//c. tim vi cuoi cung cua so x trong mang
int timvicuoicung(int a[], int n, int x){
    for(int i=n-1; i>=0; i--){
        if(a[i] == x){
            return i; // tra ve vi tri
        }
    }
    return -1; // khong tim thay
}

// d. xoa tat ca cac so chinh phuong trong mang
void xoachinhphuong(int a[], int &n){
    int j = 0;
    for(int i=0; i<n; i++){
        if(!kiemtrasochinhphuong(a[i])){
            a[j++] = a[i]; 
        }
    }
    n = j; // cap nhat lai kich thuoc mang
}

// e. tim vi tri cua phan tu am lon nhat trong mang
int vitriamlonnhat(int a[], int n){
    int max_am = INT_MIN; // khoi tao max_am voi gia tri nho nhat co the
    int vitri = -1; // khoi tao vi tri voi gia tri -1 (khong tim thay)
    for(int i=0; i<n; i++){
        if(a[i] < 0 && a[i] > max_am){
            max_am = a[i]; // cap nhat gia tri am lon nhat
            vitri = i; // cap nhat vi tri
        }
    }
    return vitri; // tra ve vi tri cua phan tu am lon nhat  
}

// ham main
int main(){

    //a. nhap mang va xuat mang
    int n;
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    int a[100]; 
    nhapmang(a, n);
    xuatmang(a, n);

    // b. in ra cac so chinh phuong trong mang
    inchinhphuong(a, n);

    // c. tim vi cuoi cung cua so x trong mang
    int x;
    cout << "\nNhap so x can tim: ";
    cin >> x;
    int vitri = timvicuoicung(a, n, x);
    if(vitri != -1){
        cout << "Vi tri cuoi cung cua so " << x << " trong mang la: " << vitri + 1 << endl;
    } else {
        cout << "Khong tim thay so " << x << " trong mang." << endl;
    }

    // d. xoa tat ca cac so chinh phuong trong mang
    xoachinhphuong(a, n);
    cout << "\nMang sau khi xoa cac so chinh phuong: ";
    xuatmang(a, n);

    // e. tim vi tri cua phan tu am lon nhat trong mang
    int vitri_am_lon_nhat = vitriamlonnhat(a, n);
    if(vitri_am_lon_nhat != -1){
        cout << "\nVi tri cua phan tu am lon nhat trong mang la: " << vitri_am_lon_nhat + 1 << endl;
    } else {
        cout << "\nKhong tim thay phan tu am trong mang." << endl;
    }
    
    return 0;
}
    
