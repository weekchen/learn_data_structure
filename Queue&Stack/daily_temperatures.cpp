//
// Created by chenzhiji on 18-10-12.
//
#include "iostream"
#include "vector"
#include "stack"

using namespace std;

//class Solution {
//public:
//    vector<int> dailyTemperatures(vector<int>& T) {
//        vector<int> result;
//        int num, flg;
//        for(int i = 0; i < T.size(); i++) {
//            num = 0;
//            flg = 1;
//            for (int j = 1; j < T.size() - i; j++) {
//                num = num + 1;
//                if (T[i + j] > T[i]) {
//                    flg = 0;
//                    break;
//                }
//            }
//            if(flg)
//                result.push_back(0);
//            else
//                result.push_back(num);
//        }
//        return result;
//    }
//};
/**
 * better example from leetcode
 */

class DailyTemperatures {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<int> st;
        for (int i=0; i<temperatures.size(); ++i){
            while(!st.empty() && (temperatures[st.top()] < temperatures[i])){
                int idx = st.top(); st.pop();
                result[idx]=i-idx;
            }
            st.emplace(i);
        }
        return result;
    }
};