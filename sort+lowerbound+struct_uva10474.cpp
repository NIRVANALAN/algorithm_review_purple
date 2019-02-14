#include <algorithm>
#include <vector>
#include <iostream>
#define ALL(x) x.begin(),x.end()
#define MAX_N 10000+5
using namespace std;

//struct ListNode {
//	int val;
//	ListNode* next;
//	ListNode(int x) : val(x), next(NULL) {}
//	
//};
struct marble {
	int no;
	int pos;
	marble() {}
	marble(int x, int y) : no(x),pos(y) {}
	bool operator < (const marble& m) const {
		return m.no > no; //asending
	}
	//bool operator < (const marble& m) const {
	//	return 
	//}
}marbles[MAX_N];
int queries[MAX_N];
int main() {
	int n,q;
	//int marbles[MAX_N];
	while (scanf_s("%d%d", &n, &q) && n != 0 && q != 0) {
		for (auto i = 0; i < n; i++)
		{
			cin >> marbles[i].no;
			marbles[i].pos = i+1;
		}
		for (auto i = 0; i < q; i++)
			cin >> queries[i];
		//sort(marbles,marbles+n);
		for (auto i = 0; i < q; i++)
		{
			int x = lower_bound(marbles,marbles+n, marble(queries[i],0))-marbles;
			if (marbles[x].no==queries[i])
				cout << "found "<<queries[i]<<" at "<<marbles[x].pos<<endl;
			else 
				cout << "not found"<<endl;
		}
	}
}

//vector<int> v({ 1,2,0,3,3,5,6,6,6,7 });
//sort(ALL(v));
//auto m = unique(ALL(v));
//auto m2 = m - v.begin();
//return 0;