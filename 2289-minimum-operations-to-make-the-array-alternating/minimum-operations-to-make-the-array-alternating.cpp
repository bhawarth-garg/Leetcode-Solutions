class Solution {
public:
 int findMax(map<int, int> &m, int m1)
 {
      int maxm=0 ,val;
     for(auto it:  m)
     {
         if(it.second>maxm && it.first!=m1)
         {
             maxm= it.second;
             val= it.first;
         }
     }
     return val;
 }
    int minimumOperations(vector<int>& nums) {
        
         map<int, int> m1,m2;
        int n= nums.size();
         int e,o;
         e=o=0;

        for(int i=0;i<n;i+=2)
        {
            m2[nums[i]]++;
            e++;
        }

        for(int i=1;i<n;i+=2)
        {
            m1[nums[i]]++;
            o++;
        }
        int count=INT_MAX;

        // for(auto it: m1)
        // {
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        // cout<<"whfuiwehf"<<endl;;
        // for(auto it: m2)
        // {
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        


        int maxe1, maxe2, maxo1, maxo2;
        maxe1= findMax(m2, 0);
        maxe2= findMax(m2, maxe1);
        maxo1= findMax(m1, 0);
        maxo2= findMax(m1, maxo1);

        cout<<maxe1<<" "<<maxe2<<" "<<maxo1<<" "<<maxo2<<endl;

        if(maxe1!=maxo1)
        {
            return e-m2[maxe1]+o-m1[maxo1];
        }

        if(maxe1==maxe2 && maxo1==maxo2)
            return min(e,o);
        if(maxo2==maxo1)
            return min(e-m2[maxe2], e-m2[maxe1]+ o);
        if(maxe1==maxe2)
            return min( o-m1[maxo2], e+o-m1[maxo1] );
    

        return min(e-m2[maxe1]+o-m1[maxo2], e-m2[maxe2]+o-m1[maxo1]);

    }
};