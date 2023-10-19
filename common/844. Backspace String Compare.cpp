#include <iostream>
#include <string>
using namespace std;
/*
Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.
*/
class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        return backspace(s) == backspace(t);
    }

private:
    string backspace(const string &s)
    {
        string stack;
        for (const char c : s)
            if (c != '#')
                stack.push_back(c);
            else if (!stack.empty())
                stack.pop_back();
        return stack;
    }
};
/*
Example 1:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".
Example 2:

Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".
Example 3:

Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".
*/
int main()
{
    return 0;
}