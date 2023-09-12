class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        
         int n= nums.size();
          int minm= INT_MAX, maxm= INT_MIN, ind1, ind2;
          ind1= ind2=0;
         for(int i=0;i<n;i++)
         {
             if(nums[i]>maxm)
             {
                 maxm= nums[i];
                 ind1= i;
             }
             if(nums[i]<minm)
             {
                 minm= nums[i];
                 ind2=i;
             }
         }
          
          int ind= max(ind1, ind2);
          ind1= min(ind1, ind2);
          ind2= ind;

          int count= min(ind1+1+(n-ind2), min(ind2+1, n-ind1) );

          return count;
    }
};