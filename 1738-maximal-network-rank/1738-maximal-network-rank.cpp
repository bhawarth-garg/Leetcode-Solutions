class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        int l= roads.size();
        vector<vector<int>> mat(n, vector<int>());

        for(int i=0;i<l;i++)
        {
            mat[roads[i][0]].push_back(roads[i][1]);
            mat[roads[i][1]].push_back(roads[i][0]);
        }
        int ans=0, count=0;

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                count =mat[i].size()+ mat[j].size();
                for(int k=0;k<mat[j].size();k++)
                {
                    if(mat[j][k]==i)
                    {
                        count-=1;
                        break;
                    }
                }
                ans= max(ans, count);
            }
        }
        return ans;
    }
};