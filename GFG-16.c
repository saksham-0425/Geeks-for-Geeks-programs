#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

int display(struct node*ptr){
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

struct node* deletenode(struct node*head){
    struct node *a=head;
    struct node *b=head->next;

    printf("enter the position of the node you want to delete : ");
    int x;
    scanf("%d",&x);
    
    if(x==1){
        head=head->next;
        free(a);
    }
    else if(x==2){
        a->next=b->next;
        free(b);
    }
    else{
        
        for(int i=2;i<x;i++){
        
        a=a->next;
        b=b->next;
        }
        a->next=b->next;
        free(b);
    }
    
    return head;
}

int main(){
    
    struct node *head=NULL;
    struct node *p;
    struct node *q;
    
    
    int n;
    printf("Enter the nodes you want to create: ");
    scanf("%d",&n);

    p = (struct node *)malloc(sizeof(struct node));
    printf("enter data : \n");
    scanf("%d",&p->data);

    head = p;
    struct node*x=head;

    for (int i = 0; i < (n-1); i++)
    {
        q = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &q->data);
        q->next = NULL;
        p->next = q;
        p =q;
    }

    printf("The linked list elements are: \n");
    display(x);

    printf("\n");

    head=deletenode(head);
    display(head);

    return 0;
}