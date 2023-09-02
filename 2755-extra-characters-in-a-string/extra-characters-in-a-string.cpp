class Solution {
public:
int solve(string s, map<string, int> &m, vector<vector<int>> &dp,int ind, int prev)
{
    int n= s.length();
    if(ind>=n)
    {
        return ind-prev-1;
    }
    if(dp[ind][prev+1]!=-1)  return dp[ind][prev+1];
    int pm,npm, em;
    pm= npm= em= INT_MAX;

    em= ind-prev+ solve(s, m,dp, ind+1, ind);
    if(m[s.substr(prev+1, ind-prev)])
        pm= solve(s, m,dp, ind+1, ind);
    npm= solve(s, m, dp,ind+1, prev);

    // cout<<ind<<" "<<em<<" "<<pm<<" "<<npm<<endl;

    return dp[ind][prev+1]= min(pm, min(npm, em));

}
    int minExtraChar(string s, vector<string>& d) {
        
        int n= s.length();


        map<string, int> m;
        for(int i=0;i<d.size();i++)
        {
            m[d[i]]++;
        }
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(s, m,dp, 0, -1);
    }
};