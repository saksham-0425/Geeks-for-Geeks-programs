#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
    int flag;
};

int detectloop(struct node*head){
   struct node* fast = head;
   struct node* slow = head;
    
    
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        
        if (fast == slow) {
            return 1;  
        }
    }
    
    return 0; 
}


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
        q->next = head;
        p->next = q;
        p = q;
    }


    printf("The linked list elements are: \n");
    display(x);
    
    int a=detectloop(head);
    if(a==1){
        printf("loop found");
    }
    else{
        printf("loop not found");
    }

    
}