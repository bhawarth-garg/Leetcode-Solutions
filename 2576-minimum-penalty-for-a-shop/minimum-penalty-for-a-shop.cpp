class Solution {
public:
    int bestClosingTime(string c) {
        int n= c.size();
        int s=0;
        vector<int> v(n+1);
        v[0]=0;
        for(int i=0;i<n;i++)
        {
            if(c[i]=='Y')
                s+=1;
            else
                s-=1;
            
            v[i+1]= s;
        }
        int maxm= 0, ind=0;
        for(int i=0;i<n+1;i++)
        {
            // cout<<v[i]<<" ";

            if(v[i]>maxm)
            {
                maxm= v[i];
                ind=i;
            }


        }
        return ind;



        
    }
};