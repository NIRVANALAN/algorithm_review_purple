#include<algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
#define ALL(x) x.begin(),x.end()

using namespace std;


vector<int> fill_rand_int(int cnt) {
	vector<int> v;
	for (auto i = 0; i < cnt; i++)
	{
		v.push_back(rand());
	}
	return v;
}

void test_sort(vector<int>& v) {
	sort(ALL(v));
	for (auto i = 0; i < v.size()-1; i++)
	{
		_ASSERT(v[i] <= v[i + 1]);
	}
}

int main() {
	srand(time(nullptr));
	auto v = fill_rand_int(100);
	test_sort(v);
	return 0;
}