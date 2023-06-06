class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n= nums.size();
        int c=1, el= nums[0];
        
        for(int i=1;i<n;i++)
        {
            if(c>0 && el!=nums[i])
                c--;
            else if(c>0 && el==nums[i])
                c++;
            else
            {
                el= nums[i];
                c++;
            }
        }
        
        return el;
    }
};