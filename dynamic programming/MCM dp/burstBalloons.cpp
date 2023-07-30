//RECURSION + MEMOIZATION

#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:

    int f(int i, int j, vector<int>& a, vector<vector<int>>& dp) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int maxi = INT_MIN;
        for (int k=i; k<=j; k++) {
            int cost = a[i-1]*a[k]*a[j+1] + f(i, k-1, a, dp) + f(k+1, j, a, dp);
            maxi = max(maxi, cost);
        }
        return dp[i][j] = maxi;
    }

    int maxCoins(vector<int>& a) {
        int n = a.size();
        a.insert(a.begin(), 1);
        a.push_back(1);
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return f(1, n, a, dp);
    }
};


//TABULATION

class Solution {
public:

    int maxCoins(vector<int>& a) {
        int n = a.size();
        a.insert(a.begin(), 1);
        a.push_back(1);
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        for (int i=n; i>=1; i--) {
            for (int j=1; j<=n; j++) {
                if (i>j) continue;
                int maxi = INT_MIN;
                for (int k=i; k<=j; k++) {
                    int cost = a[i-1]*a[k]*a[j+1] + dp[i][k-1] + dp[k+1][j];
                    maxi = max(maxi, cost);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][n];
    }
};