#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
 


struct ListNode* merge(struct ListNode* list1, struct ListNode* list2)
{
    struct ListNode *head,*temp,*sec;
    if(!list1) return list2;
    if(!list2) return list1;
    if(list1->val > list2-> val)
    {
        head=list2;
        sec=list1;
    }
    else
    {
        head=list1;
        sec=list2;
    }
    for(temp=head; temp->next && sec ; temp=temp->next)
    {
        if(temp->next->val > sec->val)
        {
            list1=temp->next;
            temp->next=sec;
            sec=sec->next;
            temp->next->next=list1;
        }
    }
    if(sec) temp->next=sec;
    return head; 
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
    int i;
    struct ListNode *head=NULL;
    if(listsSize==0) return NULL;
    for(i=0;i<listsSize;i++)
    {
        head=merge(head,lists[i]);
    }
    return head;
}