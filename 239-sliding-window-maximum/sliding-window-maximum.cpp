class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n= nums.size();
        priority_queue<int> pq;
        vector<int> v;
        map<int, int> m;
        for(int i=0;i<k;i++)
        {
            pq.push(nums[i]);
        }
        v.push_back(pq.top());

        for(int i=k;i<n;i++)
        {
            m[nums[i-k]]++;
            pq.push(nums[i]);
            while(m[pq.top()])
            {
                m[pq.top()]--;
                if(m[pq.top()]==0)
                    m.erase(pq.top());
                pq.pop();  
            }
            if(!pq.empty())
                v.push_back(pq.top());
        }

        return v;
    }
};