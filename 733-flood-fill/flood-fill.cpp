class Solution {
public:
    vector<vector<int>> dir{{0,1},{0,-1}, {1,0},{-1,0}};
    void dfs(vector<vector<int>>& image, vector<vector<bool>> &vis, int sr, int sc,int cf)
    {
        int n= image.size();
        int m= image[0].size();
        vis[sr][sc]= true;
        int ci= image[sr][sc];
        image[sr][sc]= cf;
        for(int i=0;i<4;i++)
        {
            int r= sr+dir[i][0], c= sc+dir[i][1];

            if(r>=0 && c>=0&& r<n && c<m && image[r][c]==ci && !vis[r][c])
                dfs(image, vis, r,c,cf );
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int n= image.size();
        int m= image[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        dfs(image, vis, sr, sc,color);

        return image;
        
    }
};