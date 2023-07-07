class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int n= nums.size();
        int i=0, j=0, z=0;
        int maxm=0;
        
        while(j<n)
        {
            if(nums[j]==1)
            {
                maxm= max(maxm, j-i+1);
            }
            else
            {
                while(i<=j && z>=k)
                {
                    if(nums[i]==0)
                        z--;
                    i++;
                }
                if(z<k)
                {
                    z++;
                    maxm= max(maxm, j-i+1);
                }
            }
            j++;
        }
        
        return maxm;
        
    }
};