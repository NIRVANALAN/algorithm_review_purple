#include "com.h"
using namespace std;

bool isValid(string s)
{
    vector<char> couple = {'{', '}', '(', ')', '[', ']'};
    auto flag = false;
    if (!s.size())
        return true;
    if (s.size() % 2 != 0)
        return false;
    stack<char> sk;
    for (auto i = 0; i < s.size();i++)
    {
        if (sk.size())
        {
            auto loc1 = find(ALL(couple), s[i]) - couple.begin();
            auto loc2 = find(ALL(couple), sk.top()) - couple.begin();
            if ((loc1 - loc2) == 1 && couple[loc1] % 2 == 1) //pair
            {
                cout<<sk.top()<<endl;
                sk.pop();
                // flag = true;
                // i++;
                continue;
            }
            else // not pair but not null
            {
                sk.push(s[i]);
                // i++;
                continue;
            }
        }
        sk.push(s[i]);
    }
    // cout << (sk.top()) << endl;
    if (!sk.size())
        return true;
    // cout<<sk.top()<<endl;
    return false;
}
int main()
{
    cout << isValid("({()}[][][][])") << endl; // important
    return 0;
}