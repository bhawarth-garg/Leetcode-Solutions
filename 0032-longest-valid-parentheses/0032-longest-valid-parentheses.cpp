class Solution {
public:
    int longestValidParentheses(string s) {
        
        stack<pair<char, int>>st;
        int maxm=0;
        int n= s.length();
        for(int i=0;i<n;i++)
        {
            if(s[i]==')' && !st.empty() && st.top().first=='(')
                st.pop();
            else
            {
                st.push({s[i], i});
            }
                
        }
        int prev= n;
        
        while(!st.empty())
        {
            maxm= max(maxm, prev-st.top().second-1);
            prev= st.top().second;
            st.pop();
        }
        maxm= max(maxm, prev-0);
        
        return maxm;
    }
};