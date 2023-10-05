#include<stdio.h>
#include<stdlib.h>


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

struct node *sortedInsert(struct node* head, int data) {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    
    if (head == NULL || data < head->data) {
        newNode->next = head;
        return newNode;
    }

    struct node *current = head;

   
    while (current->next != NULL && data > current->next->data) {
        current = current->next;
    }

    
    newNode->next = current->next;
    current->next = newNode;

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
    
    int data;
    printf("enter the element to be inserted : ");
    scanf("%d",&data);

    head=sortedInsert(head,data);
    display(head);
}