#include <iostream>
#include <vector>
#include <string>
#include <map>
using std::vector;
using std::string;
using std::map;
/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
*/
class Solution {
public:
    Solution(){
        digit2Alpha = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
    }

    vector<string> letterCombinations(string digits) {
        this->digits = digits;
        if(digits.size()>0)
            traceback(0, "");
        return result;
    }

    void traceback(int i, string curStr){
        if(curStr.size()==digits.size()){
            result.push_back(curStr);
            return;
        }
        for(auto e: digit2Alpha[digits[i]]){
            traceback(i+1, curStr+e);
        }
    }

private:
    map<char,string> digit2Alpha;
    string digits;
    vector<string> result;
};
/*
Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
*/
int main(){
    Solution s;
    string digits = "23";
    vector<string> result = s.letterCombinations(digits);
    for(auto e:result){
        std::cout<< e <<std::ends;
    }
    std::cout<<std::endl;
    return 0;
}