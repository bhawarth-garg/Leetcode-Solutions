class Solution {
public:

    int solve(vector<vector<int>>&pair, vector<vector<int>>&dp,int ind, int prev)
    {
        int n= pair.size();
        if(ind>=n)
        {
            return 0;
        }

        if(dp[ind][prev+1]!=-1)  return dp[ind][prev+1];
        int p=0,np=0;

        if(prev==-1 || pair[ind][0]>pair[prev][1])
            p= 1+ solve(pair,dp, ind+1, ind);
        
        np= solve(pair,dp , ind+1, prev);

        return dp[ind][prev+1]= max(p, np);

    }
    int findLongestChain(vector<vector<int>>& pairs) {
        
        int n= pairs.size();
        sort(pairs.begin(), pairs.end());

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        return solve(pairs, dp, 0, -1);

    }
};