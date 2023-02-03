class Solution {
public:
   
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        
        vector<vector<int>> mat(n, vector<int> ());
        
        vector<int> vis(n,-1);
        
        
        for(int i=0;i<paths.size();i++)
        {
            mat[paths[i][0]-1].push_back(paths[i][1]-1);
            mat[paths[i][1]-1].push_back(paths[i][0]-1);
        }
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<mat[i].size();j++)
//             {
//                 cout<<mat[i][j]<<" ";
                
//             }
//             cout<<endl;
//         }
        
        vis[0]=0;
        vector<int> v(4);
        for(int i=1;i<n;i++)
        {
            for(int i=0;i<4;i++)
                v[i]=0;
            
            for(int j=0;j<mat[i].size();j++)
            {
                if(vis[mat[i][j]]>=0)
                    v[vis[mat[i][j]]]=1;
                     //cout<<"hello";
            }
            for(int k=0;k<=3;k++)
            {
                if(v[k]==0)
                {
                    vis[i]=k;
                    break;
                }
                
            }
        }
        
        for(int i=0;i<n;i++)
        {
            vis[i]+=1;
        }
                       
return vis;
    }

};