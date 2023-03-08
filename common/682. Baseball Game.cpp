#include <iostream>
#include <vector>
#include <string>
#include <stack>
using std::vector;
using std::string;
using std::stack;
/*
You are keeping score for a baseball game with strange rules. The game consists of several rounds, where the scores of past rounds may affect future rounds' scores.

At the beginning of the game, you start with an empty record. You are given a list of strings ops, where ops[i] is the ith operation you must apply to the record and is one of the following:

An integer x - Record a new score of x.
"+" - Record a new score that is the sum of the previous two scores. It is guaranteed there will always be two previous scores.
"D" - Record a new score that is double the previous score. It is guaranteed there will always be a previous score.
"C" - Invalidate the previous score, removing it from the record. It is guaranteed there will always be a previous score.
Return the sum of all the scores on the record.
*/
class Solution {
public:
    int calPoints(vector<string>& ops) {
        int result = 0;
        stack<int> s;
        for(auto str: ops){
            int value = 0;
            int a=0, b=0;
            switch(str[0]){
                case 'C':
                    s.pop();
                    break;
                case 'D':
                    value = s.top();
                    value *= 2;
                    s.push(value);
                    break;
                case '+':
                    a = s.top();
                    s.pop();
                    b = s.top();
                    s.pop();
                    s.push(b);
                    s.push(a);
                    s.push(a+b);
                    break;
                default:
                    s.push(std::atoi(&str[0]));
                    break;
            }
        }
        while(!s.empty()){
            result += s.top();
            s.pop();
        }
        return result;
    }
};
/*
Example 1:

Input: ops = ["5","2","C","D","+"]
Output: 30
Explanation:
"5" - Add 5 to the record, record is now [5].
"2" - Add 2 to the record, record is now [5, 2].
"C" - Invalidate and remove the previous score, record is now [5].
"D" - Add 2 * 5 = 10 to the record, record is now [5, 10].
"+" - Add 5 + 10 = 15 to the record, record is now [5, 10, 15].
The total sum is 5 + 10 + 15 = 30.
Example 2:

Input: ops = ["5","-2","4","C","D","9","+","+"]
Output: 27
Explanation:
"5" - Add 5 to the record, record is now [5].
"-2" - Add -2 to the record, record is now [5, -2].
"4" - Add 4 to the record, record is now [5, -2, 4].
"C" - Invalidate and remove the previous score, record is now [5, -2].
"D" - Add 2 * -2 = -4 to the record, record is now [5, -2, -4].
"9" - Add 9 to the record, record is now [5, -2, -4, 9].
"+" - Add -4 + 9 = 5 to the record, record is now [5, -2, -4, 9, 5].
"+" - Add 9 + 5 = 14 to the record, record is now [5, -2, -4, 9, 5, 14].
The total sum is 5 + -2 + -4 + 9 + 5 + 14 = 27.
Example 3:

Input: ops = ["1"]
Output: 1
*/
int main(){
    Solution s;
    vector<string> vec = {"5","2","C","D","+"};
    std::cout<< s.calPoints(vec) <<std::endl;

    return 0;
}