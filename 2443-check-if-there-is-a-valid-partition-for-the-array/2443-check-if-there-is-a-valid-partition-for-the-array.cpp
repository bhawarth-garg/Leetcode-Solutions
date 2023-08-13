class Solution {
public:
bool solve(vector<int> &nums, vector<int> &dp, int prev, int curr, int ind)
{
    int n= nums.size();
    if(prev>=n)
        return true;
    if(prev==n-1)
        return false;

    if(dp[prev]!=-1)  return dp[prev];

    bool  p, np;
    p=np= false;
    if(nums[curr]==nums[prev])
    {
        if(ind<n && nums[ind]==nums[curr])
        {
            p= solve(nums, dp,ind+1, ind+2, ind+3);
        }
        np= solve(nums,dp, ind, ind+1, ind+2);
    }
    else if(ind<n && nums[curr]-nums[prev]==1 )
    {
        if(nums[ind]- nums[curr]==1)
            p= solve(nums, dp,ind+1, ind+2, ind+3);
    }

    return dp[prev]= p || np;
}
    bool validPartition(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n+1, -1);

        return solve(nums, dp,0,1,2);
        
    }
};