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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* temp= head;
        int count=0;
        while(temp)
        {
            count++;
            temp=temp->next;
        }
        
        if(n>count || n==0)
            return head;
        if(n==count)
            return head->next;
        
        int ind= count-n-1;
        temp=head;
        while(temp && temp->next)
        {
            if(ind==0)
            {
                temp->next= temp->next->next;
            }
            ind--;
            temp=temp->next;
        }
        
        return head;
    }
};