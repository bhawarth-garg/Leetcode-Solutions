//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  vector<Node*> path;
  void dfs(Node* root, vector<Node*> &v, int target)
  {
    if(!root)
    {
        return ;
    }
    v.push_back(root);
    if(root->data==target)
    {
        path=v;
        return;
    }
    if(root->left)
        dfs(root->left, v, target);
    if(root->right)
        dfs(root->right, v, target);
    
    v.pop_back();
      
  }
  int solve(Node* root)
  {
      if(!root)
      {
          return 0;
      }
      int l=0,r=0;
      
      l+= solve(root->left);
      r+= solve(root->right);
      
      return max(l,r)+1;
      
  }
    int minTime(Node* root, int target) 
    {
        vector<Node*> v;
        dfs(root, v, target);
        
        // for(int i=0;i<path.size();i++)
        //     cout<<path[i]->data<<" ";
        int n= path.size(), i=0, maxm= INT_MIN;
        
        int value;
        
        for(i=0;i<path.size()-1;i++)
        {
            if(path[i]->left==path[i+1])
            {
                value = solve(path[i]->right) ;
            }
            else
            {
                value = solve(path[i]->left);
            }
            value += n-i-1;
            // cout<<value<<" ";
            maxm= max(maxm, value);
        }
        
        maxm= max(maxm, max(solve(path[n-1]->left),solve(path[n-1]->right)));
        
        return maxm;
        
        // Your code goes here
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends