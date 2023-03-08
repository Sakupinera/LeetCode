#include <iostream>
#include <queue>
using std::queue;
/*
Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

Implement the MyStack class:

void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.
*/
// class MyStack {
// public:
//     MyStack() {}
//     void push(int x) {
//         q2.push(x);
//         while (q2.size() > 1) {
//             q1.push(q2.front()); q2.pop();
//         }
//     }
//     int pop() {
//         int x = top(); q2.pop();
//         return x;
//     }
//     int top() {
//         if (q2.empty()) {
//             for (int i = 0; i < (int)q1.size() - 1; ++i) {
//                 q1.push(q1.front()); q1.pop();
//             }
//             q2.push(q1.front()); q1.pop();
//         }
//         return q2.front();
//     }
//     bool empty() {
//         return q1.empty() && q2.empty();
//     }
// private:
//     queue<int> q1, q2;
// };
class MyStack {
public:
    MyStack() {}
    void push(int x) {
        q.push(x);
        for (int i = 0; i < (int)q.size() - 1; ++i) {
            q.push(q.front()); q.pop();
        }
    }
    int pop() {
        int x = q.front(); q.pop();
        return x;
    }
    int top() {
        return q.front();
    }
    bool empty() {
        return q.empty();
    }
private:
    queue<int> q;
};
int main(){
    int x = 5;
    MyStack* obj = new MyStack();
    obj->push(x);
    int param_2 = obj->pop();
    int param_3 = obj->top();
    bool param_4 = obj->empty();
    return 0;
}