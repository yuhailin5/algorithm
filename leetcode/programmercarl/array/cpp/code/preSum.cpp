/*
 * @Description: 前缀和学习
 * @Author: 天涯过客
 * @Date: 2025-01-28 00:51:21
 */

#include<bits/stdc++.h>
using namespace std;

/**
 * @brief 前缀和
 * 
 */
class PrefixSum {
public:
    vector<int> preSum;
    vector<int> nums;
    PrefixSum(vector<int>& nums) {
        int n = nums.size();
        preSum.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            preSum[i] = preSum[i - 1] + nums[i - 1];
        }
    }

    int query(int i, int j) {
        return preSum[j + 1] - preSum[i];
    }
};



int main() {




    return 0;
}