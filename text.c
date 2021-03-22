/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeDuplicateNodes(struct ListNode* head){
   
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    int index[20000]={0};

    struct ListNode* cur=head;
    struct ListNode* prev=NULL;
    while(cur)
    {
        
        if(index[cur->val]==0)
        {
            index[cur->val]=1;
            prev=cur;
            cur=cur->next;
        }
        else
        {
            prev->next=cur->next;
            free(cur);
            cur=prev->next;
        }
    }
    return head;
}