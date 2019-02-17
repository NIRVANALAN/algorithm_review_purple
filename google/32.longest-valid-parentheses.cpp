/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 *
 * https://leetcode-cn.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (24.97%)
 * Total Accepted:    6.1K
 * Total Submissions: 24.5K
 * Testcase Example:  '"(()"'
 *
 * 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
 * 
 * 示例 1:
 * 
 * 输入: "(()"
 * 输出: 2
 * 解释: 最长有效括号子串为 "()"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ")()())"
 * 输出: 4
 * 解释: 最长有效括号子串为 "()()"
 * 
 * 
 */
#include "com.h"
using namespace std;
class Solution
{
  public:
    int longestValidParentheses(string s)
    {
#define max_n 500
        int dp[max_n], lv = 0, cv = 0, lflag = 0, clflag = 0, crflag = 0;
        struct parenth
        {
            int index;
            char p;
            parenth(int i, char p) : index(i), p(p) {}
        };
        stack<parenth> sk;

        memset(dp, 0, max_n);
        if (!s.size())
            return 0;
        sk.push(parenth(0, s[0]));
        for (auto i = 1; i < s.size(); i++)
        {
            if (sk.size() && sk.top().p == '(' && s[i] == ')')
            {
                crflag = sk.top().index;
                crflag = clflag < crflag ? clflag : crflag;
                if (crflag - clflag == 1 || crflag - clflag == 2) // pair with previous

                    sk.pop();
                cv += 2;
                if (clflag - lflag == 1 || clflag - lflag == 2) // pair with previous
                    dp[i] = cv + dp[i - 1];
                else if (cv > lv)
                    dp[i] = cv;
                else
                    dp[i] = dp[i - 1];
            }
            else
            {
                sk.push(parenth(i, s[i]));
                clflag = clflag < i ? clflag : i;
                cv = 0;
                dp[i] = dp[i - 1];
            }
        }
        return dp[s.size() - 1];
    }
};
