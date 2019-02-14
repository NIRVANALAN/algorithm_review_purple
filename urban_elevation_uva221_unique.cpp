#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
const int max_n = 100 + 5;
struct block
{
	int id;
	double x, y, width, height;
	bool operator < (const block& b)const {
		return x < b.x || (x == b.x) && y < b.y;
	}

}b[max_n]; // important

int n, k_base = 0;
double ignore;
double x[max_n * 2]; // trick
//map<int,block> v_blocks;

bool cover(int i, double mx) {
	return b[i].x <= mx && (b[i].x + b[i].width) >= mx;
}

bool visible(int i, double mx) {
	//if (!v_blocks.count(i))
	//	v_blocks[i] = b[i]; // add visibal blocks
	if (!cover(i, mx))
		return false;
	for (auto j = 0; j < n; j++)
	{
		if (b[j].y < b[i].y&& b[j].height >= b[i].height && cover(j, mx)) // block(s) in the south blocked the block
			return false;
		return true;
	}
};

int main() {
	while (scanf_s("%d",&n)==1&&n)
	{
		for (auto i = 0; i < n; i++)
		{
			cin >> b[i].x >> b[i].y >> b[i].width >> ignore >> b[i].height;
			x[i * 2] = b[i].x, x[i * 2 + 1] = b[i].x + b[i].width;
			b[i].id = i + 1;
		}
		sort(b, b + n);
		sort(x, x + n * 2);
		//sort x and eliminate redundant coords, return m coords
		auto m = unique(x, x + n * 2) - x; //返回的是容器末尾，如果想得到去重后的size,需要减去初始地址
		if (k_base++) cout << endl;
		cout << k_base << endl << b[0].id;
		for (auto i = 0; i < n; i++)
		{
			auto vis = false;
			for (auto j = 0; j < m-1; j++)
			{
				if (visible(i, (x[j] + x[j + 1]) / 2)) {
					vis = true; break;
				}
				if (vis) cout << b[i].id<<" ";

			}
			cout << endl;
		}
	}

	return 0;
}