#include <iostream>
#include <set>
#include <stack>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>
#include "source.h"
using namespace std;

#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x,x.begin())
typedef set<int> Set;
map<Set, int> IDcache;
vector<Set> Setcache;

int ID(Set x) {
	{
		if (IDcache.count(x))
			return IDcache[x];
	}
	Setcache.push_back(x);
	return IDcache[x] = Setcache.size() - 1;
}

int main() {
	stack<int> s;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string op;
		cin >> op;
		if (op[0] == 'P')
			s.push(ID(Set()));
		else if (op[0] == 'D')
			s.push(s.top());
		else {
			Set x1 = Setcache[s.top()]; s.pop();
			Set x2 = Setcache[s.top()]; s.pop();
			Set x;
			if (op[0] == 'U') {
				set_union(ALL(x1), ALL(x2), INS(x));
			}
			if (op[0] == 'I')
			{
				set_intersection(ALL(x1), ALL(x2), INS(x));
			}
			if (op[0] == 'A') {
				x = x2;
				x2.insert(ID(x1));
			}
			s.push(ID(x));
		}
		cout << Setcache[s.top()].size() << endl;
	}
	return 0;
}
