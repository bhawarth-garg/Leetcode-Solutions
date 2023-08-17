// class Solution {
// public:
// int inf= 100000;

//     int solve(vector<vector<int>> &dp, vector<vector<bool>> &vis, int i, int j, int m, int n)
//     {
//         if(i<0 || i>=m || j<0 || j>=n)
//         {
//             return inf;
//         }

        
//         cout<<i<<"  "<<j<<"         ";

//         if(dp[i][j]!=-1) 
//             return dp[i][j];

//         vis[i][j]=true;
//         vector<int> v(4);
//         v[0]= solve(dp, vis, i-1, j, m ,n)+1;
//         v[1]= solve(dp, vis, i+1, j, m ,n)+1;
//         v[2]= solve(dp, vis, i, j-1, m ,n)+1;
//         v[3]= solve(dp, vis, i, j+1, m ,n)+1;

//         return dp[i][j]= *min_element(v.begin(), v.end());
//     }
//     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
//         int m= mat.size();
//         int n= mat[0].size();

//         vector<vector<int>> dp(m, vector<int> (n,-1));
//         vector<vector<bool>> vis(m, vector<bool>  (n,false));

//         for(int i=0;i<m;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 if(mat[i][j]==0)
//                 {
//                     dp[i][j]=0;
//                     vis[i][j]=true;
//                 }
//             }
//         }

//         for(int i=0;i<m;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 if(!vis[i][j])
//                 {
//                     int ans= solve(dp, vis, i,j , m,n);
//                     vis[i][j]=true;
//                 }
//             }
//         }
        

//         return dp;


//     }
// };
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                    q.push({i,j});
                else
                    grid[i][j]=-1;
            }
        }
        vector<int> d={-1,0,1,0,-1};
        while(!q.empty())
        {
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                pair<int,int> p=q.front();
                q.pop();
                for(int j=0;j<4;j++)
                {
                    int r=p.first+d[j];
                    int c=p.second+d[j+1];
                    if(r>=0 && c>=0 && r<m && c<n && grid[r][c]==-1)
                    {
                        grid[r][c]=1+grid[p.first][p.second];
                        q.push({r,c});
                    }
                }
            }
        }
        return grid;
    }
};