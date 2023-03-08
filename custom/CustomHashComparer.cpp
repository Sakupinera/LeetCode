#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
using std::string;
using std::map;
class Data{
public:
    int val;
public:
    Data(int val){
        this->val = val;
    }
};
size_t hasher(const Data &data){
    return std::hash<int>()(data.val);
}
bool eqOp(const Data &lhs, const Data &rhs){
    return lhs.val == rhs.val;
}
int main(){
    std::unordered_map<Data, string, decltype(hasher)*, decltype(eqOp)*> m(42,hasher,eqOp);
    m.insert({Data(0),"A"});
    m.insert({Data(1),"B"});
    m.insert({Data(2),"C"});
    for(int i=0;i<m.size();i++){
        std::cout<<m[i]<<std::endl;
    }
    return 0;
}
