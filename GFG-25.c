#include<stdio.h>
#include<stdlib.h>

// Ques- identical linked list or not :-

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

int identicalornot(struct node* head1, struct node* head2){
   struct node*p=head1;
   struct node*q=head2;
   
   while(p!=NULL && q!=NULL){
       if(p->data!=q->data){
          return 0;
       }
       p=p->next;
       q=q->next;
   }
   
   if(p!=NULL || q!=NULL){
       return 0;
   }
   
   return 1;
}

void main()
{
    struct node *head1= NULL;
    struct node *p;
    struct node *q;

    int n;
    printf("Enter the nodes you want to create: ");
    scanf("%d", &n);

    p = (struct node *)malloc(sizeof(struct node));
    printf("enter data : \n");
    scanf("%d", &p->data);

    head1 = p;
    struct node *x = head1;

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
    
    struct node *head2= NULL;
    struct node *p2;
    struct node *q2;

    int n2;
    printf("Enter the nodes you want to create for linked list 2 : ");
    scanf("%d", &n2);

    p2 = (struct node *)malloc(sizeof(struct node));
    printf("enter data : \n");
    scanf("%d", &p2->data);

    head2 = p2;
    struct node *x2 = head2;

    for (int i = 0; i < (n2 - 1); i++)
    {
        q2 = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &q2->data);
        q2->next = NULL;
        p2->next = q2;
        p2 = q2;
    }

    printf("The linked list elements are: \n");
    display(x2);

    int b= identicalornot(head1,head2);
    if(b==0){
        printf("not identical ");
    }
    else{
        printf("identical linked list ");
    }

    
}