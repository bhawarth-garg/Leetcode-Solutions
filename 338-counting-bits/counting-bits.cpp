class Solution {
public:
    vector<int> countBits(int n) {
         vector<int> v;

         for(int i=0;i<n+1;i++)
         {
             int count=0, num=i;
             while(num)
             {
                 count+=num&1;
                 num>>=1;
             }
             v.push_back(count);
         }
         return v;
        
    }
};