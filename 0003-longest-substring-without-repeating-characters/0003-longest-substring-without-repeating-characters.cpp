class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n= s.length();
        map<char,int> m;
        int maxm= 0, len=0;
        
        for(int i=0;i<n;i++)
        {
            if(m[s[i]]>=i-len)
            {
                maxm= max(maxm, len);
                len= i-m[s[i]];
            }
            m[s[i]]=i+1;
            len++;
            
        }
        
        maxm= max(maxm, len);
        
        return maxm;
    }
};