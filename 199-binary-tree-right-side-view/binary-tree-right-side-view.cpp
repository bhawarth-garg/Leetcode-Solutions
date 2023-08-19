/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        
        queue<TreeNode*> q;
        vector<int> l;
        vector<int> r;
        if(!root)
        {
            return r;
        }
        q.push(root);
         int size, ind;
        while(!q.empty())
        {
            size= ind= q.size();
            l.push_back(q.front()->val);
            while(size--)
            {
                auto temp= q.front();
                q.pop();

                if(!size)
                {
                    r.push_back(temp->val);
                }

                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }

        }

        return r;
            }
};