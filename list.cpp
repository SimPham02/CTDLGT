#include <iostream>
using namespace std;

struct nhanvien{
	int manv;
	string tennv;
	int namct;
	float luong;
};

struct node{
	nhanvien data;
	node *next;
};

struct list{
	node *phead;
	node *ptail;
};

void khoitao(list &ds){
	ds.phead = ds.ptail = NULL;
}

bool ktrong(list ds){
	if (ds.phead==NULL)
		return true;
	return false;
}

node* taonut(nhanvien x){
	node *p = new node;
	if (p==NULL){
		cout << "khong du bo nho de cap phat";
		return NULL;
	}
	p->data = x;
	p->next = NULL;
	return p;
}

void chencuoi(list &ds,node *p){
	if (ktrong(ds)==true){
		ds.phead = ds.ptail = p;
	}
	else{
		ds.ptail->next = p;
		ds.ptail = p;
	}
}

void nhapdulieu(nhanvien &s){
	cout << "\n nhap ma nhan vien: ";
	cin >> s.manv;
	cout << "nhap ten nhan vien: ";
	fflush(stdin); getline(cin, s.tennv);
	cout << "nhap nam con tac: ";
	cin >> s.namct;
	cout << "nhap luong: ";
	cin >> s.luong;
}

void duyetds(list &ds){
	for(node *p = ds.phead; p!=NULL; p = p->next){
		cout << p->data.manv << "," << p->data.tennv << "," << p->data.namct << "," << p->data.luong <<"\n" ;
	}
}

int main(){
	list ds;
	khoitao(ds);
	int n;
	nhanvien x;
	cout << "nhap so nhan vien :";
	cin >> n;
	for (int i=1; i<=n; i++){
		nhapdulieu(x);
		node *p = taonut(x);
		if (p!=NULL)
			chencuoi(ds, p);
	}
	cout << "\ndanh sach da tao :\n";
	duyetds(ds);
}
