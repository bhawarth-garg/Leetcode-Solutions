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
    int maxLevelSum(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        
        int level=0, sum=0, size, maxm=INT_MIN, c=0;
        
        while(!q.empty())
        {
            size= q.size();
            c++;
            sum=0;
            while(size--)
            {
                auto it = q.front();
                q.pop();
                
                if(it->left)
                    q.push(it->left);
                if(it->right)
                    q.push(it->right);
                
                sum+= it->val;
            }
            if(sum>maxm)
            {
                maxm= sum;
                level= c;
            }
        }
        
        return level;
    }
};