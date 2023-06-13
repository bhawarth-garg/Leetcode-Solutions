//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        int n= x.length();
        stack<char>st;
        
        for(int i=0;i<n;i++)
        {
            if(!st.empty() &&  ((x[i]==')' && st.top()=='(') ||  (x[i]=='}' && st.top()=='{') || (x[i]==']' && st.top()=='[')))
                st.pop();
            else if(x[i]=='(' || x[i]=='['  || x[i]=='{')
                st.push(x[i]);
            
            else
            return false;
        }
        
        return st.empty();
        // Your code here
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends