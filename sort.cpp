#include <iostream>
using namespace std;

struct SinhVien
{
	int masv;
	string tensv, lop;
	float tongket;
};

void NhapLieu(SinhVien &x)
{
	cout <<"\nNhap ma sinh vien:  "; cin >> x.masv;
	cout <<"Nhap ten sinh vien: "; fflush(stdin); getline(cin, x.tensv);
	cout <<"Nhap lop          : "; fflush(stdin); getline(cin, x.lop);
	cout <<"Nhap diem tong ket: "; cin >> x.tongket;
}

void XuatLieu(SinhVien &x)
{
	cout << x.masv << ",   " << x.tensv << ",     " << x.lop << ",    " << x.tongket <<endl;
}

void NhapMang(SinhVien a[], int n)
{
	for(int i=0; i<=n; i++)
		NhapLieu(a[i]);
}

void XuatMang(SinhVien a[], int n)
{
	for(int i=0; i<=n; i++)
		XuatLieu(a[i]);
}

void InsertionSort(SinhVien a[],int n)
{ 
	int pos; float x;
	for(int i=1 ; i<=n ; i++) 
	{
		x = a[i].tongket; pos = i-1;
		while((pos >= 0)&&(a[pos].tongket > x))
		{
			a[pos+1].tongket = a[pos].tongket;
			swap(a[pos],a[pos+1]);
			pos--;
		}
		a[pos+1].tongket = x;
	}
}

void Selecttionsort(SinhVien a[],int n )
{
	int min;
	for (int i=0; i<n ; i++)
	{
		min = i;
		for(int j = i+1; j <=n ; j++)
		{
			if (a[j].tongket < a[min].tongket)
				min = j;
		}
		swap(a[min], a[i]);
	}
}

void Bubblesort(SinhVien a[], int n)
{
	for(int i=0; i<n; i++)
		for(int j = n; j>i; j--)
			if(a[j].tongket < a[j-1].tongket)
				swap(a[j], a[j-1]);
}


int TimKiemNhiPhan(SinhVien a[], int n, float y)
{
	int left = 0, right = n, mid;
	do{
		mid = (left+right)/2;
		if (a[mid].tongket==y)
			return mid;
		else if (a[mid].tongket<y) left = mid + 1;
		else right = mid - 1;
	}while(left<=right);
	return -1;
}

int main()
{
	SinhVien x;
	SinhVien a[100];
	int n;
	cout << "Nhap so sinh vien: ";
	cin >> n;
	NhapMang(a, n-1);
	cout << "Xuat mang\n";
	XuatMang(a, n-1);
	cout << "\nMang sau khi xap la: " <<endl;
	Bubblesort(a, n-1);
	XuatMang(a, n-1);
	
	float y;
	cout << "Nhap diem tong ket can tim: "; cin >> y;
	int ketqua = TimKiemNhiPhan(a, n - 1, y);
	if (ketqua == -1)
		cout <<"Khong tim thay";
	else
	{
		cout << "Tim thay tai vi tri : ";
		int l = ketqua;
		while(l>=0 && a[l].tongket==y)
		{
			cout << l << " ";
			l--;
		}
		int r = ketqua + 1;
		while(r <= n-1 && a[r].tongket==y)
		{
			XuatLieu(a[r]); cout <<endl;
			r++;
		}
	}
}
