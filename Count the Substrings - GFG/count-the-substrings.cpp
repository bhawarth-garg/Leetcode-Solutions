//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countSubstring(string s)
    {
        int count=0;
        int n= s.length();
        int l,u;
        l=u=0;
        // code here
        for(int i=0;i<n;i++)
        {
             l=u=0;
            for(int j=i;j<n;j++)
        {
               
                if((int)s[j]<=90 && (int)s[j]>=65)
                {
                    u++;
                }
                else if((int)s[j]<=122&& (int)s[j]>=97)
                {
                    l++;
                }
                if(l==u)
                    count++;
                
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends