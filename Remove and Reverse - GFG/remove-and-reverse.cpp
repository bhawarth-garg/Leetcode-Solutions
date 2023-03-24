//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string s) {
        // code here
        
        int n= s.length();
        
        int st=0, end=n-1;
        
         vector<int> v(26,0);
        
        for(int i=0;i<n;i++)
        {
            v[s[i]-'a']++;
        }
        // for(int i=0;i<26;i++)
        // {
        //     cout<<v[i]<<" ";
        // }
        string st1, st2;
        st1=st2="";
        int side=0;
        
        while(st<=end)
        {
           // cout<<"st: "<<st<<"  end: "<<end<<" "<<side<<"          ";
            if(!side)
            {
                //cout<<s[st]<<" "<<v[s[st]-'a']<<" ";
                if(v[s[st]-'a']==1)
                {
                    //cout<<"st: "<<s[st]<<"  ";
                    st1+= s[st];
                }
                else
                {
                    v[s[st]-'a']--;
                    side=1;
                }
                st++;
            }
            else
            {
                //cout<<s[end]<<" "<<v[s[end]-'a']<<" ";
                if(v[s[end]-'a']==1)
                {
                   // cout<<"end: "<<s[end]<<"  "; 
                    st2+= s[end];
                }
                else
                {
                    v[s[end]-'a']--;
                    side=0;
                }
                end--;
            }
            //cout<<endl;
            
        }
       // cout<<st1<<" "<<st2<<"  ";
        string str="";
        str+= st1;
        reverse(st2.begin(), st2.end());
        str+= st2;
        
        
        int len= n- str.length();
        
        if(len%2)
        {
            reverse(str.begin(), str.end());
            return str;
        }
        return str;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends