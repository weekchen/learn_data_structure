//
// Created by chenzhiji on 18-10-18.
//
#include "iostream"
#include "stack"

using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(empty())
            return NULL;
        stack<int> s2;
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int a = s2.top();
        s2.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return a;

    }

    /** Get the front element. */
    int peek() {
        if(empty())
            return NULL;
        stack<int> s2;
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int a = s2.top();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return a;

    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty();
    }

private:
    stack<int> s1;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
