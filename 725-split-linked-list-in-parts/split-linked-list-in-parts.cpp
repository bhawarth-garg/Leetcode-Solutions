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
 ListNode* temp;

 ListNode* listEl(int k)
 {
    //  ListNode* newList= new ListNode();
    if(!temp)
        return NULL;
     ListNode* newList= new ListNode(temp->val);
     
     ListNode* head= newList;
    while(k-1 && temp && temp->next)
    {
        newList->next= new ListNode(temp->next->val);
        temp= temp->next;
        newList= newList->next;
        k--;
    }
    if(temp)
        temp= temp->next;
    return head;
 }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        vector<ListNode*> v;
        temp= head;
        int count=0;
        while(temp)
        {
            count++;
            temp= temp->next;

        }
        

        int size= count/k;
        int rem= count%k;
        temp= head;
        // cout<<count<<size<<rem;

        while(k)
        {
            if(rem)
            {
                v.push_back(listEl(size+1));
                rem--;
            }
            else
                v.push_back(listEl(size));

            k--;

        }

        return v;
    }
};