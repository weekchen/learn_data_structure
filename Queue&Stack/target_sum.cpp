//
// Created by chenzhiji on 18-10-18.
//
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

//class Solution {
//public:
//    int findTargetSumWays(vector<int>& nums, int S) {
//        int sum = 0, n = 0;
//        num = 0;
//        target = S;
//        getSum(sum, n, nums);
//        return num;
//    }
//
//private:
//    int num, target;
//    void getSum(int sum, int n, vector<int>& nums){
//        if(n != nums.size() - 1){
//            getSum(sum + nums[n], n+1, nums);
//            getSum(sum - nums[n], n+1, nums);
//        }
//        else
//        {
//            if(sum == target)
//                num++;
//        }
//    }
//};
/**
 * nice sample
 */

class TargetSum {
public:
    int findTargetSumWays(vector<int>& nums, int s) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return sum < s || (s + sum)%2 == 1 ? 0 : subsetSum(nums, (s + sum) >> 1); // s+sum >>1 == s+sum /2 ==sum(P)
    }

    int subsetSum(vector<int>& nums, int s) {
        int dp[s + 1] = { 0 };
        dp[0] = 1;
        for (int n : nums)
            for (int i = s; i >= n; i--)
                dp[i] += dp[i - n];
        return dp[s];
    }
};