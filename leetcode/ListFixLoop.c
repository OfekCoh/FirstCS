#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* head) {
    struct Node* temp = head;
    while(temp != NULL){
            printf("%d ", temp->data);
            temp = temp->next;
    }
}

void remove2(struct Node* head)
{
    struct Node *slow=head, *fast=head;
    int len=0;
    do
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    while(slow!=fast);
    for(slow=slow->next;slow!=fast;slow=slow->next) len++;
    slow=head;
    while(slow!=fast)
    {
        slow=slow->next;
        fast=fast->next;
    }    
    while(len!=0)
    {
        fast=fast->next;
        len--;
    }
    fast->next=NULL;
    return;
}

int main() {
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;
    struct Node* fourth = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = head;

    printf("Circular Linked List: ");
    remove2(head);
    printList(head);
    return 0;
}
