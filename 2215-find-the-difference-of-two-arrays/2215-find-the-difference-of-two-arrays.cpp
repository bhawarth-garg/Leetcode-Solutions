class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
        int n1= nums1.size();
        int n2= nums2.size();
        
        vector<vector<int>> ans(2, vector<int>());
        
        map<int, int> m1;
        map<int, int> m2;
        for(int i=0;i<n1;i++)
        { 
            m1[nums1[i]]++;
        }
        for(int i=0;i<n2;i++)
        {
            m2[nums2[i]]++;
        }
        for(int i=0;i<n1;i++)
        {
            if(!m2[nums1[i]] && m1[nums1[i]])
            {
                m1[nums1[i]]=0;
                ans[0].push_back(nums1[i]);
            }
                
        }
        for(int i=0;i<n2;i++)
        {
            if(!m1[nums2[i]] && m2[nums2[i]])
            {
                m2[nums2[i]]=0;
                ans[1].push_back(nums2[i]);
            }
        }
        
        return ans;
         
    }
};