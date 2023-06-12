class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        
        int n= s.length();
        
        int c=0, maxm= 0, st=0, curr=0;
        
        for(int i=0;i<n-1;i++)
        {
            if(!c && s[i]==s[i+1])
            {
                c=1;
                curr=i;
            }
            else if(s[i]==s[i+1])
            {
                maxm= max(maxm, i+1-st);
                st=curr+1;  
                curr=i;
            }
        }
        maxm= max(maxm, n-st);
        
        
        return maxm;
        
    }
};