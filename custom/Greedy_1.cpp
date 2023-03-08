#include <iostream>
#include <vector>
#include <queue>
using std::vector;
struct Node{
    int cost;
    int profit;
};
struct fund_greater{
    bool operator()(Node &a, Node &b){
        return a.cost > b.cost;
    }
};
struct profit_less{
    bool operator()(Node &a, Node &b){
        return a.profit < b.profit;
    }
};
class Solution{
public:
    int Func(vector<Node> &vec, int w){
        std::priority_queue<Node,vector<Node>,fund_greater> minCostQ;
        std::priority_queue<Node,vector<Node>,profit_less> maxProfitQ;
        for(auto e: vec){
            minCostQ.push(e);
        }
        for(int i=0;i<vec.size();i++){
            while(!minCostQ.empty() && minCostQ.top().cost <= w){
                maxProfitQ.push(minCostQ.top());
                minCostQ.pop();
            }
            if(!maxProfitQ.empty()){
                w+=maxProfitQ.top().profit;
                maxProfitQ.pop();
            }else{
                return w;
            }
        }
        return w;
    }
};
int main(){
    Node a{3,1},b{1,2},c{4,3},d{9,7},e{9,4};
    vector<Node> vec{a,b,c,d,e};
    Solution s;
    int w = 1;  //  初始资金
    std::cout<< s.Func(vec, w) <<std::endl; // 7
    return 0;
}