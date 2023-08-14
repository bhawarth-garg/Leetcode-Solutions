class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n= nums.size();

        int prev= 0, curr=1, ind=2;

        while(prev<n-2 && ind<n)
        {
            if(nums[prev]==nums[curr])
            {
                if(nums[ind]==nums[curr])
                {
                    nums[ind]=INT_MAX;
                    ind= ind+1;
                }
                else
                {
                    prev= ind;
                    curr= ind+1;
                    ind= ind+2;
                }
            }
            else
            {
                prev= curr;
                curr= ind;
                ind= ind+1;
            }
        }
        // for(int i=0;i<n;i++)
        // {
        //     cout<<nums[i]<<" ";
        // }
        // return 0;
         int i, j;
         i=j=0;
        while(j<n && i<=j)
        {
            while(j<n && nums[j]==INT_MAX)
            {
                j++;
            }
            
            if(j<n)
            {
                swap(nums[i], nums[j]);
                i++;
                j++;    
            }

        }
        cout<<i<<" ";

        return i;
    }
};