#include <stdio.h>
#include <stdlib.h>

// Ques- find the intersection point in the Y shaped linked list :-

struct node
{
    int data;
    struct node *next;
};

int length(struct node*head){
    int l=0;
    while(head!=NULL){
        l++;
        head=head->next;
    }
    return l;
}

int intersection(struct node*head1,struct node*head2){
    int l1=length(head1);
    int l2=length(head2);

    int d=0;
   struct node*ptr1;
   struct node*ptr2;
   if(l1>l2){
       d=l1-l2;
       ptr1=head1;
       ptr2=head2;
   }
   else{
       d=l2-l1;
       ptr1=head2;
       ptr2=head1;
   }
   
   while(d){
       ptr1=ptr1->next;
       if(ptr1==NULL){
           return -1;
       }
       d--;
   }
   while(ptr1!=NULL && ptr2!=NULL){
   
       if(ptr1==ptr2){
           return ptr1->data;
       }
       ptr1=ptr1->next;
       ptr2=ptr2->next;
   }
   return -1;

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

    int a=intersection(head,head2);
    printf("%d",a);
}