#include<stdio.h>
#include<stdlib.h>

// Ques- Swap the kth elements from starting and last :-

struct node{
    int data;
    struct node*next;
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

struct node* swapkthnodes(struct node* head, int n) {
    printf("Enter the positions of the nodes you want to swap (k and n-k): ");
    int k;
    scanf("%d", &k);

    if (k <= 0 || k > n || 2 * k - 1 == n) {
        printf("Swapping not possible\n");
        return head;
    } else {
        struct node* p = head;
        struct node* q = head;
        struct node* prevP = NULL;
        struct node* prevQ = NULL;

        for (int i = 1; i < k; i++) {
            prevP = p;
            p = p->next;
        }

        for (int i = 1; i < n - k + 1; i++) {
            prevQ = q;
            q = q->next;
        }

        if (prevP != NULL) {
            prevP->next = q;
        } else {
            head = q;
        }

        if (prevQ != NULL) {
            prevQ->next = p;
        } else {
            head = p;
        }

        struct node* temp = p->next;
        p->next = q->next;
        q->next = temp;

        return head;
    }
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

    head=swapkthnodes(head,n);
    display(head);
}