class Solution {
public:
    bool check(vector<int>&nums, int ind, int target, vector<vector<int>> &dp)
    {
        if(ind>=nums.size() || target<0)
            return false;
        if(target==0)
            return true;
        if(dp[ind][target]!=-1)  return dp[ind][target];
        
        int p,np;
        p=np= false;
        
        p= check(nums, ind+1, target-nums[ind], dp);
        np= check(nums, ind+1, target, dp);
        
        
        return dp[ind][target]= p||np;
    }
    bool canPartition(vector<int>& nums) {
        
        int n= nums.size();
        int sum=0;
        
        for(int i=0;i<n;i++)
        {
            sum+= nums[i];
        }
        
        if(sum%2)
            return false;
        
        
        
        int target= sum/2;
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        
        return check(nums, 0,target, dp);
    }
};