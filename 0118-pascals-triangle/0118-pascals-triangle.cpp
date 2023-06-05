class Solution {
public:
    vector<vector<int>> generate(int n) {
        
        vector<vector<int>>  ans;
        vector<int> v;

        v.push_back(1);

        ans.push_back(v);

        while(n-1)
        {
            v.clear();
            v.push_back(1);
            int ind= ans.size()-1;
            for(int i=0;i<ans[ind].size()-1;i++)
            {
                v.push_back(ans[ind][i]+ans[ind][i+1]);
            }
            v.push_back(1);

            ans.push_back(v);

            n--;
           
        }

        return ans;

    }
};