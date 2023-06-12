class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        int n= nums.size();
        vector<string> ans;
        
        if(n==0)
            return ans;
        
        
        int st=0, curr;
        
        for(int i=1;i<n;i++)
        {
            if(nums[i]!=nums[i-1]+1)
            {
                if(st==i-1)
                    ans.push_back(to_string(nums[st]));
                else
                    ans.push_back(to_string(nums[st])+"->"+to_string(nums[i-1]));
                
                st=i;
            }
            
        }
        if(st==n-1)
            ans.push_back(to_string(nums[st]));
        else
            ans.push_back(to_string(nums[st])+"->"+to_string(nums[n-1]));
        
        return ans;
        
    }
};