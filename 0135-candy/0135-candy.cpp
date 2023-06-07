class Solution {
public:
    int candy(vector<int>& r) {
        
        int n= r.size();
        vector<int> c(n,1);
        vector<pair<int, int>> rat;
        if(n==1)
            return 1;
        
        for(int i=0;i<n;i++)
        {
            
            rat.push_back({r[i],i});
        }
        sort(rat.begin(), rat.end());
        
        
        for(int i=0;i<n;i++)
        {
            int ind= rat[i].second;
            // cout<<ind<<endl;
            if(ind==0)
            {
                if(r[ind]>r[ind+1])
                {
                    c[ind]= max(c[ind], c[ind+1]+1);
                }
            }
            else if(ind==n-1)
            { 
                if(r[ind]>r[ind-1])
                {
                    c[ind]= max(c[ind], c[ind-1]+1);
                }
            }
            else
            {
                if(r[ind]>r[ind+1])
                {
                    c[ind]= max(c[ind], c[ind+1]+1);
                }
                if(r[ind]>r[ind-1])
                {
                     c[ind]= max(c[ind], c[ind-1]+1);   
                }
            }
        }
        
        long long int sum=0;
        for(int i=0;i<n;i++)
        {
            // cout<<c[i]<<" ";
            sum+= c[i];
        }
        
        return (int)sum;
            
    }
};