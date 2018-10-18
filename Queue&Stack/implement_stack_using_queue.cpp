//
// Created by chenzhiji on 18-10-18.
//
#include "iostream"
#include "queue"

using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        queue1.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        queue<int> queue2;
        int size = queue1.size();
        for(int i = 0; i < size - 1;i++){
            queue2.push(queue1.front());
            // cout << queue1.size();
            queue1.pop();
        }
        int a = queue1.front();
        queue1.pop();
        while(!queue2.empty()){
            queue1.push(queue2.front());
            queue2.pop();
        }
        return a;

    }

    /** Get the top element. */
    int top() {
        queue<int> queue2;
        int size = queue1.size();
        for(int i = 0; i < size - 1;i++){
            queue2.push(queue1.front());
            queue1.pop();
        }
        int a = queue1.front();
        queue2.push(queue1.front());
        queue1.pop();
        while(!queue2.empty()){
            queue1.push(queue2.front());
            queue2.pop();
        }
        return a;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return queue1.empty();
    }

private:
    queue<int> queue1;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
