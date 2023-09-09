class Solution {
public:


int solve( vector<int> &nums, vector<int> &dp, int target)
{
     int n= nums.size();
    if(target<0 )
        return 0;
    if(target==0)
        return 1;

    if(dp[target]!=-1)   return dp[target];

    int pick=0;

    for(int i=0;i<n;i++)
    {
        pick+= solve(nums, dp, target-nums[i]);
    }

    // cout<<ind<<" "<<pnm<<" "<<npm<<<<endl;

    return dp[target]= pick;
}
    int combinationSum4(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
         int n= nums.size();
         vector<int> dp(target+1,-1);
        // map<int, int> m;

         return solve(nums, dp, target);

    }
};