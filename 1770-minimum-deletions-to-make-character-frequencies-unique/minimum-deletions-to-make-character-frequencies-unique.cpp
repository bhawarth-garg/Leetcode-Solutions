class Solution {
public:
    int minDeletions(string s) {
        
         int n= s.length();
         vector<int> freq(26,0);
          map<int,int> m;

         for(int i=0;i<n;i++)
         {
             freq[s[i]-'a']++;
         }
         for(int i=0;i<26;i++)
         {
            //  cout<<freq[i]<<"  ";
            if(freq[i]>0)
                m[freq[i]]++;
         }
         int count=0;

         for(int i=0;i<26;i++)
         {
             if(m[freq[i]]>1 && freq[i]!=0)
             {
                for(int j=freq[i]-1;j>=0;j--)
                {
                    if(!m[j] || !j)
                    {
                        // freq[i]= j;
                        m[j]++;
                        m[freq[i]]--;
                        count+= freq[i]-j;
                        break;
                    }
                }
             }
         }

         return count;


    }
};