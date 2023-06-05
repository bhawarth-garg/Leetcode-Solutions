class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n= nums.size();
        int maxm= *max_element(nums.begin(), nums.end());
        int sum=0;
        
        for(int i=0;i<n;i++)
        {
            sum+= nums[i];
            if(sum<0)
                sum=0;
            if(sum!=0 && sum>maxm)
                maxm= sum;
       }
        
        return maxm;
    }
};