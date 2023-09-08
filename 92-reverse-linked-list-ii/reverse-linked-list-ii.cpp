/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* solve(ListNode* root,  int k)
        
    {
        if(!root ||!root->next)  return root;
        ListNode* prev, *curr, *nex;
        prev= root;
        curr= root->next;
        
        while(k && curr)
        {
            nex= curr->next;
            curr->next= prev;
            
            prev= curr;
            curr=nex;
            
            k--;

        }
        root->next= nex;
        
        return prev;
        
        
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode* temp = head;
        
        if(left==1)
            return solve(head, right-left);
        int k= right-left;
        while(left-2)
        {
            temp= temp->next;
            left--;
        }
        temp->next= solve(temp->next, k);
        
        
        return head;
        
    }
};