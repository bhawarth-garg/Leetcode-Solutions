class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        
        int n= nums.size();
        int l,e;
        l=e=0;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]<pivot)
                l++;
            else if(nums[i]==pivot)
                e++;
        }
        vector<int> v(n);
        int i=0, j=l, k=l+e;
        for(int x=0;x<n;x++)
        {
            if(nums[x]<pivot)
            {
                v[i]= nums[x];
                i++;
            }
            else if(nums[x]==pivot)
            {
                v[j]= nums[x];
                j++;
            }
            else
            {
                v[k]= nums[x];
                k++;
            }
        }
        return v;
    }
};