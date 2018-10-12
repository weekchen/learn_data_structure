//
// Created by chenzhiji on 18-10-11.
//
#include "iostream"
#include "stack"
#include "string"

using namespace std;

class ValidParrentheses {
public:
    bool isValid(string s) {
        stack<char> p;
        for(int i = 0; i < s.size(); i++)
        {
            if(!p.empty() && abs(s[i] - p.top()) <= 2 && abs(s[i] - p.top()) > 0)
                p.pop();
            else
                p.push(s[i]);
        }
        return p.empty();
    }
};