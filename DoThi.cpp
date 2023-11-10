#include <iostream>
#include <fstream>

using namespace std;

#define MAX 100

char Vetex[] = {'A','B','C','D','E','F'};

int GetNumVetex(char c, int n){
	for (int i=0; i<n; i++)
		if (Vetex[i]==c)
			return i;
}

struct Graph{
	int n;
	int A[MAX][MAX];
};

void Nhap(Graph &G)
{
	int i, j, k, v, ts, x;
	char ch;
	ifstream fi("Dt.txt");
	if (fi.is_open()==true)
	{
		fi >> G.n;
		for (i=0; i<G.n; i++){
			for (j=0; j<G.n; j++)
				G.A[i][j] = x;
			G.A[i][i] = 0;
		}
		for (i=0; i<G.n; i++){
			fi >> k;
			for (j=1; j<=k; j++){
				fi >> ch;
				v = GetNumVetex(ch,G.n);
				fi >> ts;
				G.A[i][v] = ts;
			}	
		}
		fi.close();
	}
	else
	{
		cout << "Doc file khong thanh cong!";
	}
}

void Xuat(Graph G)
{
	cout << "So dinh = " << G.n << endl;
	for (int i=0; i<G.n; i++)
	{
		for (int j=0; j<G.n; j++)
			cout << G.A[i][j] << " ";
		cout << endl;
	}
}

int main()
{	
	Graph G;
	Nhap(G);
	Xuat(G);
}
