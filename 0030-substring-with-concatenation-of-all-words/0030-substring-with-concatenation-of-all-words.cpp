class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        
        int size= words.size();
        int l= words[0].size();
        int n= s.length();
        int len= l*size;
        
        vector<int> v;
        
        if(n<len)
            return v;
        
        
        string w;
        map<string, int> m, temp;
        
        for(int i=0;i<size;i++)
        {
            m[words[i]]++;
        }
        
        for(int i=0;i<=n-len;i++)
        {
            temp=m;
            for(int j=i;j<i+len;j+=l)
            {
                w=s.substr(j, l);
                if(!temp[w])
                    break;
                else
                {
                    temp[w]--;
                    if(!temp[w])
                        temp.erase(w);
                }
            }
            
            if(!temp.size())
                v.push_back(i);
        }
        
        
        return v;
    }
};