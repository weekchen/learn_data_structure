//
// Created by chenzhiji on 18-10-18.
//

#include "iostream"
#include "stack"
#include "queue"
#include "cmath"

using namespace std;

class DecoderString {
public:
    string decodeString(string s) {
        string result;
        stack<char> stack1;
        for(auto i : s){
            if(i != ']')
                stack1.push(i);
            else{
                stack<char> stack2;
                while(stack1.top() != '['){
                    stack2.push(stack1.top());
                    stack1.pop();
                }
                stack1.pop();
                string string1;
                while(!stack2.empty()){
                    string1.push_back(stack2.top());
                    stack2.pop();
                }
                int n = 0;
                int num = 0;
                while(stack1.top() <= '9' && stack1.top() >= '0'){
                    num = num + (stack1.top()-'0') * int(pow(10, n));
                    n++;
                    stack1.pop();
                    if(stack1.empty())
                        break;
                }
                for(int j=0; j < num; j++){
                    for(auto k : string1)
                        stack1.push(k);
                }
            }

        }
        stack<char> stack3;
        while(!stack1.empty()){
            stack3.push(stack1.top());
            stack1.pop();
        }
        while(!stack3.empty()){
            result.push_back(stack3.top());
            stack3.pop();
        }
        cout << result << endl;
        return result;
    }
};

int main(){
    string s = "100[leetcode]";
    DecoderString m;
    m.decodeString(s);
}