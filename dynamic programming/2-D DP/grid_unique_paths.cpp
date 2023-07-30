// recursion + memoization

class Solution {
public:

    int f(int i, int j, vector<vector<int>>& dp){
        if (i<0 || j<0) return 0;
        if (i==0 && j==0) return 1;
        if (dp[i][j] != -1) return dp[i][j];

        int up = f(i-1, j, dp);
        int left = f(i, j-1, dp);

        return dp[i][j] = up + left;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m-1, n-1, dp);
    }
};

// tabulation

class Solution {
public:

int uniquePaths(int m, int n){
    vector<vector<int> > dp(m,vector<int>(n,-1));
    for(int i=0; i<m ;i++){
      for(int j=0; j<n; j++){
          
          //base condition
          if(i==0 && j==0){
              dp[i][j]=1;
              continue;
          }
          
          int up=0;
          int left = 0;
          
          if(i>0) 
            up = dp[i-1][j];
          if(j>0)
            left = dp[i][j-1];
            
          dp[i][j] = up+left;
      }
  }
  
  return dp[m-1][n-1];
    
}
};

// space optimization

class Solution {
public:


int uniquePaths(int m, int n){
    vector<int> prev(n, 0);
    for(int i=0; i<m ;i++){
        vector<int> cur(n, 0);
      for(int j=0; j<n; j++){
          
          //base condition
          if(i==0 && j==0){
              cur[j]=1;
              continue;
          }
          
          int up=0;
          int left = 0;
          
          if(i>0) 
            up = prev[j];
          if(j>0)
            left = cur[j-1];
            
          cur[j] = up+left;
      }
      prev = cur;
  }
  
  return prev[n-1];
    
}
};