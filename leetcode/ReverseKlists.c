#include <stdio.h>
#include <stdlib.h>

struct ListNode
{   
    int val;
    struct ListNode *next;
};


struct ListNode* reverse(struct ListNode* head)
{
    if(!head || !head->next) return head;
    struct ListNode *curr=head,*next=head->next,*prev=NULL;
     while(curr)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        head=prev;
    }
    return head;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k)
{
    int i=1,first=1;
    struct ListNode *p=NULL, *temp=head, *start=NULL, *end=NULL;
    if(k==1) return head;
    if(!head || !head->next) return head;
    while(temp)
    {
        if(i==1) start=temp;
        if(i==k)
        {
            p=temp->next;
            temp->next=NULL;
            if(first==1){ head=reverse(start); first=0; }
            else end->next=reverse(start);
            start->next=p;
            end=start;
            temp=start;
            i=0;
        }
        i++;
        temp=temp->next;
    }
    return head;
}