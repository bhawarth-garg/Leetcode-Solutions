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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        queue<TreeNode*> q;
        vector<int> v;
        vector<vector<int>> ans;

        if(!root)
            return ans;
        
        q.push(root);
        int c=0;

        while(!q.empty())
        {
            int size= q.size();
            while(size--)
            {
                auto temp= q.front();
                q.pop();
                v.push_back(temp->val);

                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);

            }
            if(c%2)
                reverse(v.begin(), v.end());
            c++;
            ans.push_back(v);
            v.clear();
        }

        return ans;


    }
};