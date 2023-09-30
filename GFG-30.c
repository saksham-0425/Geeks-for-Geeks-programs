#include <stdio.h>
#include <stdlib.h>

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

    

    struct node *head2 = NULL;
    struct node *r;
    struct node *s;

    int m;
    printf("Enter the nodes you want to create (linkedlist 2): ");
    scanf("%d", &m);

    r= (struct node *)malloc(sizeof(struct node));
    printf("enter data : \n");
    scanf("%d", &r->data);

    head2 = r;
    struct node *y = head2;

    for (int i = 0; i < (m - 1); i++)
    {
        s = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &s->data);
        s->next = NULL;
        r->next = s;
        r = s;
    }

    printf("The linked list 1 elements are: \n");
    display(x);

    printf("The linked list 2 elements are: \n");
    display(y);

}