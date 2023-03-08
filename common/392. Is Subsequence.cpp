#include <iostream>
#include <vector>
#include <string>
using std::string;
using std::vector;
/*
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
*/
class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int i = 0, j = 0;
        if (s == "")
            return true;
        while (j != t.size())
        {
            if (s.at(i) == t.at(j))
            {
                i++;
                if (i == s.size())
                    break;
            }
            j++;
        }
        return i == s.size();
    }
};
/*
Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false
*/
int main()
{
    Solution solution;
    string s = "abc";
    string t = "ahbgdc";
    std::cout << std::boolalpha << solution.isSubsequence(s, t) << std::endl;
    return 0;
}