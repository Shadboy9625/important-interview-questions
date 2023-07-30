//RECURSION + MEMOIZATION
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int f(int ind, int T, vector<int>& nums, vector<vector<int>>& dp) {
        if (ind == 0) {
            if (T % nums[0] == 0) return T/nums[0];
            return 1e9;
        }
        if (dp[ind][T] != -1) return dp[ind][T];

        int notTake = 0 + f(ind-1, T, nums, dp);
        int take = INT_MAX;
        if (nums[ind] <= T) take = 1 + f(ind, T-nums[ind], nums, dp);

        return dp[ind][T] = min(take, notTake);
    }

    int coinChange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        int ans = f(n-1, target, nums, dp);   
        if (ans >= 1e9) return -1;
        return ans;
    }
};

//TABULATION

class Solution {
public:

    int coinChange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target+1, 0));
        for (int T=0; T<=target; T++) {
            if (T % nums[0] == 0) dp[0][T] = T/nums[0];
            else dp[0][T] = 1e9;
        }

        for (int ind=1; ind<n; ind++) {
            for (int T=0; T<=target; T++) {
                int notTake = 0 + dp[ind-1][T];
                int take = INT_MAX;
                if (nums[ind] <= T) take = 1 + dp[ind][T-nums[ind]];

                dp[ind][T] = min(take, notTake);
            }
        }

        int ans = dp[n-1][target];
        if (ans >= 1e9) return -1;
        return ans;
    }
};