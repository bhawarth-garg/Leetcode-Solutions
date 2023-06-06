class Solution {
public:
  
    int solve(vector<vector<int>> &dp,  int i, int j, int m, int n)
    {
        if(i>=m || i<0 || j>=n || j<0)
            return 0;
        if(i==m-1 && j==n-1)
            return 1;
        
        if(dp[i][j]!=-1)  return dp[i][j];
        int d=0, r=0;
        
        d+= solve(dp, i+1, j,m,n);
        r+= solve(dp, i, j+1, m,n);
        
        return dp[i][j]= d+r;        
        
    }
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m, vector<int>(n,0));
        dp[0][0]=1;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i>=1)
                    dp[i][j]+= dp[i-1][j];
                if(j>=1)
                    dp[i][j]+= dp[i][j-1];
                
            }
        }
        // cout<<dp[0][1]<<"  ";
        
        return dp[m-1][n-1];
        
    }
};