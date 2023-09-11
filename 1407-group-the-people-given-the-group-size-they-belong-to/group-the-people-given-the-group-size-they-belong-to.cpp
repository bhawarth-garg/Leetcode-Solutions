class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gs) {
        
         int n= gs.size();
         map<int, vector<int>> m;

         for(int i=0;i<n;i++)
         {
             m[gs[i]].push_back(i);
         }

         vector<vector<int>> ans;
          vector<int> v;
         for(auto it: m)
         {
             for(int i=0;i<it.second.size();i++)
             {
                 v.push_back(it.second[i]);
                 if(v.size()==it.first)
                {
                    ans.push_back(v);
                    v.clear();
                }
             }
         }

         return ans;
    }
};