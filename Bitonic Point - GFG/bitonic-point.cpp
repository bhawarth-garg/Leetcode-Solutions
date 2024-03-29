//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int findMaximum(int arr[], int n) {
	    // code here
	    int low=0, up= n-1;
	    
	    while(low<=up)
	    {
	        int mid= low+ (up-low)/2;
	        if(mid==0 || mid==n-1)
	            break;
	        
	        if(mid>0 && mid<n-1 && arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
	            return arr[mid];
	        if(mid>0 && mid<n-1 && arr[mid]>arr[mid-1] && arr[mid]<arr[mid+1])
	            low= mid+1;
	        else if(mid>0 && mid<n-1 && arr[mid]<arr[mid-1] && arr[mid]>arr[mid+1])
	            up= mid-1;
	        
	    }
	    
	    if(arr[0]>arr[n-1])
	        return arr[0];
	   
	   return arr[n-1];
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaximum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends