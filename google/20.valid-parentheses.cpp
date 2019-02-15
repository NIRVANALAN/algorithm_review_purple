#include "com.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (36.02%)
 * Total Accepted:    42.5K
 * Total Submissions: 118K
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 
 * 
 * 注意空字符串可被认为是有效字符串。
 * 
 * 示例 1:
 * 
 * 输入: "()"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "()[]{}"
 * 输出: true
 * 
 * 
 * 示例 3:
 * 
 * 输入: "(]"
 * 输出: false
 * 
 * 
 * 示例 4:
 * 
 * 输入: "([)]"
 * 输出: false
 * 
 * 
 * 示例 5:
 * 
 * 输入: "{[]}"
 * 输出: true
 * 
 */
class Solution
{
  public:
    bool isValid(string s)
    {
#define ALL(x) x.begin(), x.end()
        vector<char> couple = {'{', '}', '(', ')', '[', ']'};
        auto flag = false;
        if (!s.size())
            return true;
        if (s.size() % 2 != 0)
            return false;
        stack<char> sk;
        for (auto i = 0; i < s.size(); i++)
        {
            if (sk.size())
            {
                auto loc1 = find(ALL(couple), s[i]) - couple.begin();
                auto loc2 = find(ALL(couple), sk.top()) - couple.begin();
                if ((loc1 - loc2) == 1 && couple[loc1] % 2 == 1) //pair
                {
                    cout << sk.top() << endl;
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
};
