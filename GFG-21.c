#include<stdio.h>
#include<stdlib.h>

// Ques- Find the sum of n nodes from last :-

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

int sumoflastNnodes(struct node*head){
    printf("enter the N number of nodes : ");
    int n;
    scanf("%d",&n);

    struct node*p=head;
    struct node*q=head;
    int count=0;
    while(p!=NULL){
        count++;
        p=p->next;
    }
    int a=count-n;
    for(int i=0;i<a;i++){
        q=q->next;
    }
    int sum=0;
    while(q!=NULL){
       sum=sum+q->data;
       q=q->next;
    }
    return sum;
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

    int b=sumoflastNnodes(head);
    printf("the sum is : %d",b);

}
