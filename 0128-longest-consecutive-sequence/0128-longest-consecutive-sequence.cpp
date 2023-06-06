class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        priority_queue<int, vector<int> , greater<int>> q;
        int n= nums.size();
        
        if(n==0)
            return 0;
        
        for(int i=0;i<n;i++)
        {
            q.push(nums[i]);
        }
        int prev= q.top();
        q.pop();
        int maxm= 1, len=1;
        
        while(!q.empty())
        {
            if(q.top()==prev+1)
            {
                len++;
            }
            else if(q.top()>prev)
            {
                len=1;
            }
            prev= q.top();
            q.pop();
            maxm= max(maxm, len);
        }
        
        return maxm;
    }
};