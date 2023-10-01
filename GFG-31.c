#include <stdio.h>
#include <stdlib.h>

// Ques- delete the nodes having greater value on right :-

struct node
{
    int data;
    struct node *next;
};

void display(struct node *ptr)
{

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

struct node*reverse(struct node*head){
    struct node*curr=head;
    struct node*prev=NULL;
    struct node*nx=NULL;
    while(curr!=NULL){
        nx=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nx;
    }
    head=prev;
    return head;
}

struct node*compute(struct node*head){
    head=reverse(head);
    struct node*q=head;
    int max=head->data;
    struct node*prev=head->next;
    while(head){
       if(head->data>=max){
         max=head->data;
         prev=head;
         head=head->next;
       }
       else{
        prev->next=head->next;
        head=prev->next;
       }
    }
    head=reverse(q);
    return head;
}
     

void main()
{
    struct node *head = NULL;
    struct node *p;
    struct node *q;

    int n;
    printf("Enter the nodes you want to create: ");
    scanf("%d", &n);

    p = (struct node *)malloc(sizeof(struct node));
    printf("enter data : \n");
    scanf("%d", &p->data);

    head = p;
    struct node *x = head;

    for (int i = 0; i < (n - 1); i++)
    {
        q = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &q->data);
        q->next = NULL;
        p->next = q;
        p = q;
    }

    printf("The linked list elements are: \n");
    display(x);

    head=compute(head);
    display(head);
}