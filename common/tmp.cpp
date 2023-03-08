#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
using namespace std;
/*
1.0 1.0
5.5 1.0
6.0 3.5
*/ 
int area(map<double,double>& m){
    int ans = 0;
    int min = m.begin()->first < 0? m.begin()->first-1: m.begin()->first;
    int max = m.rbegin()->first;
    int curLine = min;
    vector<pair<double,double>> vec;
    for(auto e: m){
        vec.push_back(e);
    }
    while(curLine < max){
        double y1,y2;
        if(curLine < vec[1].first){
            y1 = (vec[1].second-vec[0].second)/(vec[1].first-vec[0].first)*(curLine-vec[0].first)+vec[0].second;
            y2 = (vec[2].second-vec[0].second)/(vec[2].first-vec[0].first)*(curLine-vec[0].first)+vec[0].second;
        }else{
            y1 = (vec[2].second-vec[1].second)/(vec[2].first-vec[1].first)*(curLine-vec[1].first)+vec[1].second;
            y2 = (vec[2].second-vec[0].second)/(vec[2].first-vec[0].first)*(curLine-vec[0].first)+vec[0].second;
        }
        ans += (int)abs(y1-y2)+1;
        curLine++;
    }
    return ans;
}
int main(){
    int n;
    map<double,double> m;
    for(int i = 0; i < 3; i++){
        double x;
        double y;
        cin >> x;
        cin >> y;
        m.insert({x,y});
    }
    cout<< "输入完毕" <<endl;
    cout<< area(m) <<endl;

// =============================

    // string str;
    // getline(cin,str);
    // stringstream ss(str);

    // vector<double> nums;
    // char del = ',';// 分割符号为 ,
    // string tmp;
    // while (getline(ss, tmp, del)) {
    //     nums.push_back(stod(tmp));
    // }
    // // 输出 1 2 3 4 5 
    // for(auto v : nums){
    //     cout<<v<<" ";
    // }
    return 0;
}