#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <set>
using namespace std;
typedef queue<int> que;
typedef long long LL;
struct cmp
{
	bool operator() (const int a, const int b) const {
		//A的优先级比B小时返回TRUE
		return a % 10 > b % 10;
	}
};
const int coeff[3] = { 2,3,5 };
int main() {
	
	priority_queue<LL, vector<LL>, greater<LL>> pq;
	set<LL> s;
	pq.push(1);
	s.insert(1);
	for (auto i = 1;; i++)
	{
		auto x = pq.top(); pq.pop();
		if (i==1500)
		{
			cout << x << endl;
			break;
		}
		for (auto j = 0; j < 3; j++)
		{
			auto x2 = x * coeff[j];
			if (!s.count(x2)) {
				s.insert(x2);
				pq.push(x2);
			}
		}
	}
	return 0;
}