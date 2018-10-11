//
// Created by chenzhiji on 18-10-11.
//

#include "iostream"
#include "vector"

using namespace std;

class MinStack {
private:
    vector<int> my_stack;
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        my_stack.push_back(x);
    }

    void pop() {
        if(!my_stack.empty())
            my_stack.pop_back();
    }

    int top() {
        if(!my_stack.empty())
            return my_stack.back();
        else
            return false;
    }

    int getMin() {
        if(!my_stack.empty()){
            int min = my_stack.front();
            for(int i = 0; i < my_stack.size(); i++){
                if(my_stack[i] < min)
                    min = my_stack[i];
            }
            return min;
        }
        else
            return false;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */