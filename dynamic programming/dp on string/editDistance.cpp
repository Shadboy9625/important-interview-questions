#include <bits/stdc++.h>
using namespace std;

//RECURSION + MEMOIZATION

class Solution {
public:

    int f(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
        if (i==0) return j;
        if (j==0) return i;
        if (dp[i][j] != -1) return dp[i][j];

        if (s1[i-1] == s2[j-1]) return dp[i][j] = 0 + f(i-1, j-1, s1, s2, dp);
        return dp[i][j] = 1 + min({f(i-1, j, s1, s2, dp), f(i, j-1, s1, s2, dp), f(i-1, j-1, s1, s2, dp)});
    }

    int minDistance(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return f(n, m, s1, s2, dp);
    }
};

//TABULATION

class Solution {
public:

    int minDistance(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for (int i=0; i<=n; i++) dp[i][0] = i;
        for (int j=0; j<=m; j++) dp[0][j] = j;

        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                if (s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
            }
        }
        return dp[n][m];
    }
};