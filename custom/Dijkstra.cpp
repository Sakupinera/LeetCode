#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <memory>
#include <unordered_map>
#include <unordered_set>
using namespace std;
struct Edge;
struct Node{
    string value;
    int in;
    int out;
    vector<shared_ptr<Node>> nexts;
    vector<shared_ptr<Edge>> edges;

    Node(string value){
        this->value = value;
        in = 0;
        out = 0;
    }
};
struct Edge{
    int weight;
    shared_ptr<Node> from;
    shared_ptr<Node> to;

    Edge(int weight, shared_ptr<Node> form, shared_ptr<Node> to){
        this->weight = weight;
        this->from = from;
        this->to = to;
    }
};
struct Graph{
    unordered_map<string, shared_ptr<Node>> nodes;
    unordered_set<shared_ptr<Edge>> edges;
};
class Solution{
public:
    unordered_map<shared_ptr<Node>,int> Dijkstra(shared_ptr<Node> head){
        unordered_map<shared_ptr<Node>,int> distanceMap;
        distanceMap.insert({head,0});
        unordered_set<shared_ptr<Node>> selectedNodes;
        shared_ptr<Node> minNode = getMinDistanceAndUnselectedNode(distanceMap, selectedNodes);
        while(minNode != nullptr){
            int distance = distanceMap[minNode];
            for(auto edge : minNode->edges){
                auto toNode = edge->to;
                if(distanceMap.count(toNode)==0){
                    distanceMap.insert({toNode,distance+edge->weight});
                }else{
                    distanceMap[toNode] = min(distanceMap[toNode],distance+edge->weight);
                }
            }
            selectedNodes.insert(minNode);
            minNode = getMinDistanceAndUnselectedNode(distanceMap, selectedNodes);
        }
        return distanceMap;
    }

    shared_ptr<Node> getMinDistanceAndUnselectedNode(unordered_map<shared_ptr<Node>,int> &distanceMap,unordered_set<shared_ptr<Node>> &selectedNodes){
        shared_ptr<Node> minNode = nullptr;
        int minDistance = INT_MAX;
        for(auto p : distanceMap){
            shared_ptr<Node> node = p.first;
            int distance = p.second;
            if(selectedNodes.count(node)==0&&distance<minDistance){
                minNode = node;
                minDistance = distance;
            }
        }
        return minNode;
    }
};
int main(){
    clock_t begin, end;
    begin = clock();

    Solution s;
    shared_ptr<Node> a(new Node("A")),b(new Node("B")),c(new Node("C")),d(new Node("D"));
    shared_ptr<Edge> e_ab(new Edge(3,a,b)),e_bc(new Edge(2,b,c)),e_cd(new Edge(4,c,d)),e_da(new Edge(10,d,a)),e_ca(new Edge(7,c,a));
    shared_ptr<Edge> e_ba(new Edge(3,b,a)),e_cb(new Edge(2,c,b)),e_dc(new Edge(4,d,c)),e_ad(new Edge(10,a,d)),e_ac(new Edge(7,a,c));
    
    a->nexts.push_back(b);
    a->nexts.push_back(c);
    a->nexts.push_back(d);
    a->edges.push_back(e_ab);
    a->edges.push_back(e_ac);
    a->edges.push_back(e_ad);
    b->nexts.push_back(a);
    b->nexts.push_back(c);
    b->edges.push_back(e_ba);
    b->edges.push_back(e_bc);
    c->nexts.push_back(a);
    c->nexts.push_back(b);
    c->nexts.push_back(d);
    c->edges.push_back(e_ca);
    c->edges.push_back(e_cb);
    c->edges.push_back(e_cd);
    d->nexts.push_back(a);
    d->nexts.push_back(c);
    d->edges.push_back(e_da);
    d->edges.push_back(e_dc);
    unordered_map<shared_ptr<Node>,int> ans = s.Dijkstra(a);
    std::cout<< ans[a] << std::endl;
    std::cout<< ans[b] << std::endl;
    std::cout<< ans[c] << std::endl;
    std::cout<< ans[d] << std::endl;
    // unordered_map<string, shared_ptr<Node>> nodes;
    // nodes.insert({a->value,a});
    // nodes.insert({b->value,b});
    // nodes.insert({c->value,c});
    // nodes.insert({d->value,d});
    // unordered_set<shared_ptr<Edge>> edges;
    // edges.insert(e_ab);
    // edges.insert(e_ba);
    // edges.insert(e_bc);
    // edges.insert(e_cb);
    // edges.insert(e_cd);
    // edges.insert(e_dc);
    // edges.insert(e_da);
    // edges.insert(e_ad);
    // edges.insert(e_ca);
    // edges.insert(e_ac);
    // Graph g = {nodes,edges};
    end = clock();
    std::cout << "Took " << (double)(end - begin) / CLOCKS_PER_SEC << " seconds." << std::endl;
    return 0;
}