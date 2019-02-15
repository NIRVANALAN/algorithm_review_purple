#include <iostream>
#include <vector>
#include <string>
#include <deque>
using namespace std;
bool check(string s){
	deque<char> q;
	for(auto i=0;i<s.size();i++)
		q.push_front(s[i]);
	if(q.size()==1) return true;
	while(q.front()==q.back()){
		q.pop_front();
		q.pop_back();
		if(q.size()==1||q.size()==0)
			return true;
	}
	return false;
	
}
string longestPalindrome(string s) {
	if (s.size()<=1) return s;
	string ret = "";
	for(auto i=0;i<s.size()-1;i++)
		for(auto j=s.size()-1;j>i;j--)
			if(s[i]==s[j]&&(j-i+1)>ret.size()&&check(s.substr(i,j-i+1)))
				if(s.substr(i,j-i+1).size()>ret.size())
					ret = s.substr(i,j-i+1);
				if(!ret.size()&&s.size()>0)
					ret = s.substr(0,1);
				return ret;
}
int main(){
	
	// cout<<check("bb");
	// cout<<longestPalindrome("abacab")<<endl;
	cout<<longestPalindrome("abc")<<endl;
	// string s("aba");
	// cout<<s.substr(0,2);
	return 0;
}