#include<iostream>
#include<algorithm>
#include <string>
using namespace std;
//#define max_file 100
const int maxn = 100 + 5;
const int maxcol = 60;
string filenames[maxn];

void print(string s, int M) {
	cout.setf(ios::left);
	cout.width(M);
	cout << s;
}
int main() {
	int n;
	while (cin >> n) {
		auto M = 0;
		for (auto i = 0; i < n; i++)
		{
			cin >> filenames[i];
			M = max(M, (int)filenames[i].length());
		}
		int cols = (maxcol - M) / (M + 2) + 1;
		int rows = (n - 1) / cols + 1; // n-1
		sort(filenames, filenames + n);
		for (auto t = 0; t < maxcol; t++)
		{
			cout << "-";
		}
		cout << endl;
		for (auto j = 0; j < rows; j++)
		{
			for (auto k = 0; k < cols; k++)
			{
				if (j!=cols-1)
					print(filenames[k * rows + j], M+2);
				else
					print(filenames[k * rows + j], M);
			}
			cout << endl;
		}
	}
	return 0;
}
/*
19
Mr._French
Jody
Buffy
Sissy
Keith
Danny
Lori
Chris
Shirley
Marsha
Jan
Cindy
Carol
Mike
Greg
Peter
Bobby
Alice
Ruben*/