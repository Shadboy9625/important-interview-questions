#include <bits/stdc++.h>
using namespace std;

//RECURSION + MEMOIZATION

class Solution {
public:

    int f(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
        if (i<0 || j<0) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == t[j]) return dp[i][j] = 1 + f(i-1, j-1, s, t, dp);

        return dp[i][j] = 0 + max(f(i-1, j, s, t, dp), f(i, j-1, s, t, dp));
    }

    int longestCommonSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));

        return f(n-1, m-1, s, t, dp);
    }
};

//SHIFTING OF INDEX TO WRITE ABOVE SOLUTION
//PREFERRED SOLUTION TO BETTER UNDERSTAND THE RECURSION + MEMOIZATION APPROACH AND LATER APPROACH TO TABULATION APPROACH
class Solution {
public:

    int f(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
        if (i == 0 || j == 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        if (s[i-1] == t[j-1]) return dp[i][j] = 1 + f(i-1, j-1, s, t, dp);

        return dp[i][j] = max(f(i-1, j, s, t, dp), f(i, j-1, s, t, dp));
    }

    int longestCommonSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));

        return f(n, m, s, t, dp);
    }
};

//TABULATION

class Solution {
public:

    int longestCommonSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

        for (int i=0; i<=n; i++) dp[i][0] = 0;
        for (int j=0; j<=m; j++) dp[0][j] = 0;

        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                if (s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]); 
            }
        }
        return dp[n][m];
    }
};

//SPACE OPTIMIZATION

class Solution {
public:

    int longestCommonSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<int> prev(m+1, 0), cur(m+1, 0);

        for (int j=0; j<=m; j++) prev[j] = 0;

        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                if (s[i-1] == t[j-1]) cur[j] = 1 + prev[j-1];
                else cur[j] = max(prev[j], cur[j-1]); 
            }
            prev = cur;
        }
        return prev[m];
    }
};