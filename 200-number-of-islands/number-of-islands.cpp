class Solution {
public:
vector<vector<int>> dir{{0,1},{0,-1},{1,0},{-1,0}}; 
    void dfs(vector<vector<char>> &grid, vector<vector<bool>> &vis, int i, int j)
    {
        
        int n= grid.size(), m= grid[0].size();

        // if(i<0 || j<0 ||i>=n || j>=m || vis[i][j])
        //     return;

        vis[i][j]=true;
        int r,c;
        for(int k=0;k<4;k++)
        {
            r= i+dir[k][0];
            c= j+dir[k][1];

            if(r>=0 && c>=0 && r<n && c<m && !vis[r][c] && grid[r][c]=='1')
            {
                dfs(grid, vis, r,c);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        vector<pair<int, int>> mat;
        vector<vector<bool>> vis(n, vector<bool>(m,false));


        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    mat.push_back({i,j});
                }
                else
                    vis[i][j]=true;
            }
        }
        cout<<mat.size()<<" ";
        int count=0;
        for(int i=0;i<mat.size();i++)
        {
             int r=mat[i].first;
             int c= mat[i].second;
            if(!vis[r][c])
            {
                cout<<r<<" "<<c<<endl;
                count++;
                dfs(grid, vis, r,c);
            }
        }

        return count;
    }
};