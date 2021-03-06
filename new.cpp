#include "com.h"
using namespace std;

bool isValid(string s)
{
	vector<char> couple = {'{', '}', '(', ')', '[', ']'};
	if (!s.size())
		return true;
	if (s.size() % 2 != 0)
		return false;
	stack<char> sk;
	for (auto i = 0; i < s.size(); i++)
	{
		auto loc1 = find(ALL(couple), s[i]) - couple.begin();
		auto loc2 = find(ALL(couple), sk.top()) - couple.begin();
		if ((loc1 - loc2) == 1 && couple[loc1] % 2)
			sk.pop();
		// if(sk.size()&&find(ALL(couple,)))
	}
	if (!sk.size())
		return true;
	return false;
}
int main()
{
	cout<<isValid("{}");
	return 0;
}