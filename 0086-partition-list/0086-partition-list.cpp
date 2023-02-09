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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode* temp= head;

        if(!temp|| !temp->next)
        {
            return temp;
        }

        ListNode* prev=NULL;
        ListNode*  store;
        int st=0;

        if(head->val>=x)
        {
            while(temp && temp->next)
            {
                if(temp->next->val<x)
                {
                    store= temp->next;
                    temp->next= temp->next->next;
                    store->next= head;
                    head= store;
                    prev= head;
                    st=1;
                    break;
                }
                temp=temp->next;
            }

        }

        while(temp && temp->next)
        {
            if(!st && temp->next->val>=x)
            {
                st=1;
                prev= temp;
                 temp= temp->next;
            }
            else if(st && temp->next->val<x)
            {
                store= prev->next;
                prev->next= temp->next;
                temp->next= temp->next->next;
                prev->next->next= store;
                prev= prev->next;
            }
            else
            {
                temp= temp->next;
            }
        }

        return head;
    }
};