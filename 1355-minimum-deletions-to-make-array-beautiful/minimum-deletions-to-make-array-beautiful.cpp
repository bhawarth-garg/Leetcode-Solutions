class Solution {
public:
    int minDeletion(vector<int>& nums) {
        
         int n= nums.size();
          int checker=0, count=0;

         for(int i=0;i<n;i++)
         {
             if(i<n-1 && i%2==checker)
             {
                if(nums[i]==nums[i+1])
                {
                    count++;
                    checker= (checker==0?1:0);
                }
             }
         }
         if((n-count)%2!=0)
            count++;

        return count;
    }
};