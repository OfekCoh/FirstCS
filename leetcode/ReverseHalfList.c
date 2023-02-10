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

struct Node* reverse_half(struct Node* head, int* x)
{
    struct Node *end;
    if(!head) return head;
    (*x)++;
    if(!head->next) return head;
    end= reverse_half(head->next,x);
    *x-=2;
    if(*x>=0)
    {
        if(*x==0) {head->next=end; return head;}
        if(*x>0) {head->next->next=head; head->next=NULL; return end;}
    }
    return head;
}

int main() {
    int x=0;
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
    fourth->next = NULL;

    printf("Circular Linked List: ");
    reverse_half(head, &x);
    printList(head);
    return 0;
}
