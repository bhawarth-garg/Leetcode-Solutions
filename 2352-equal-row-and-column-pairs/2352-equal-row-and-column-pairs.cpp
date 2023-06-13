class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int count=0;
        int n= grid.size();        
        map<vector<int>, int> mr, mc;
        
        vector<int> v;
        
        for(int i=0;i<n;i++)
        {
            mr[grid[i]]++;
        }
        for(int j=0;j<n;j++)
        {
            for(int i=0;i<n;i++)
            {
                v.push_back(grid[i][j]);
            }
            mc[v]++;
            v.clear();
        }
        
        for(auto it: mr)
        {
            count+= it.second*(mc[it.first]);
        }
        
        return count;
    }
};