//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxDifferenceBST(Node *root,int target){
        // Code here
        int sum1, sum2= INT_MAX;
        sum1= 0;
        bool val= false;
        
        queue<pair<Node* , int>> q;
        
        q.push({root, 0});
        
        while(!q.empty())
        {
            auto temp= q.front();
            q.pop(); 
            
            Node* x= temp.first;
            int y= temp.second;
            
            if(x->data==target)
            {
                val =true;
                sum1= y;
                while(!q.empty())
                {
                    q.pop();
                }
                if(x->left)
                {
                    q.push({x->left, 0});
                }
                if(x->right)
                {
                    q.push({x->right, 0});
                }
            }
            else
            {
                if(x->left)
                {
                    q.push({x->left, y+x->data});
                }
                if(x->right)
                {
                    q.push({x->right, y+x->data});
                }
                if(!x->left && !x->right && val)
                {
                    sum2= min(sum2, y+x->data);
                }
            }
        }
        
       // cout<<sum1<<" "<<sum2<<endl;
        if(!val)
            return -1;
        if(sum2==INT_MAX)
        {
            return sum1;
        }
        
        return sum1-sum2;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends