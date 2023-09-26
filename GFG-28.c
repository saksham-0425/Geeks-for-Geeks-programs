#include <stdio.h>
#include <stdlib.h>

// Ques- Remove all the occurences of the duplicates in the linked list :-

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

struct node *removeallduplicates(struct node *head)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->next = head;
    struct node *prev = temp;
    while (head != NULL)
    {
        if (head->next != NULL && head->data == head->next->data)
        {
            while (head->next != NULL && head->data == head->next->data)
            {
                head = head->next;
            }
            prev->next = head->next;
        }
        else
        {
            prev = prev->next;
        }
        head = head->next;
    }
    return temp->next;
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

    head = removeallduplicates(head);
    display(head);
}