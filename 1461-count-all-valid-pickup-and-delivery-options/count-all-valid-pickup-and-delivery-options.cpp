class Solution {
public:
 int mod= 1e9+7;
//  long long ans=0;
// dp with memo gives tle so have to use p&c concepts;
 int solve(vector<pair<bool, bool>> &vis,vector<vector<int>> &dp, int n, int ind, int picks)
 {
     if(ind>=2*n)
     {
        // ans= (ans+1)%mod;
        return 1;
     }

     if(dp[ind][picks]!=-1)  return dp[ind][picks];
     long long p=0,np=0;

    for(int i=0;i<n;i++)
    {
        if(!vis[i].first)
        {
            vis[i].first= true;
            p+= solve(vis, dp,n, ind+1, picks+1);
            vis[i].first= false;
        }
        if(vis[i].first && !vis[i].second)
        {
            vis[i].second= true;
            np+= solve(vis, dp, n, ind+1, picks);
            vis[i].second= false;
        }
    }

    return dp[ind][picks]= (int)((p+np)%mod);
 }

    int countOrders(int n) {
        // vector<pair<bool, bool>> vis(n, {false,false});
        // vector<vector<int>> dp(2*n, vector<int>(n+1,-1));
        
        // return solve(vis,dp, n, 0,0);

        // return (int)(ans%mod);
        long long count=1;

        for(int i=2;i<=n;i++)
        {
            count= (count*(2*i-1)*(i))%mod;
        }

        return (int)count;
    }
};