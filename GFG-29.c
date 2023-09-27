#include <stdio.h>
#include <stdlib.h>

// Ques- check if linked list is palindrome or not :-

// the logic behind this code is get the middle node of the linked list and do the reversal of the linked list
// elements after the middle node and then add the reversal linked list to the middle and match starting elements and
// the elements after the middle elements. if they are equal then the list is palindrome else not. 

// 1->2->3(middle)->(reversed)1->2->3->NULL;

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

struct node*getmid(struct node*head){
    struct node*fast=head->next;
    struct node*slow=head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

struct node*reverse(struct node*head){
    struct node*curr=head;    
    struct node*prev=NULL;    
    struct node*nex=NULL;
    while(curr!=NULL){
        nex=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nex;
    }    
    return prev;

}

int palindrome(struct node*head){
   
    if(head->next==NULL){
       return 1 ;
    }

    // step 1 :- find middle

    struct node* mid=getmid(head);

    // step 2 :- reverse the linked list after middle 

    struct node*q=mid->next;

    mid->next=reverse(q);
    
    // step 3 :- compare both the halves 

    struct node*head1=head;
    struct node*head2=mid->next;

    while(head2!=NULL){
        if(head1->data!=head2->data){
            return 0;
        }
        head1=head1->next;
        head2=head2->next;
    }

    // repeat step 2 i.e return this as it was

    q=mid->next;
    q->next=reverse(q);

    return 1;
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

    int ans=palindrome(head);
    
    if(ans==1){
        printf(" Palindrome ");
    }
    else{
        printf(" Not Palindrome ");
    }
}