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

struct node *moveToFront(struct node *head){
         if (head == NULL || head->next == NULL) {
        return head;
    }

    struct node *p = head;
    struct node *q = head->next;
   

    
    while (q->next != NULL) {
        p = p->next;
        q = q->next;
    }

    
    p->next = NULL; 
    q->next = head; 
    head = q; 

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
    
    head=moveToFront(head);
    display(head);
}