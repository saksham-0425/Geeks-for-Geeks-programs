#include<stdio.h>
#include<stdlib.h>

// Ques- Finding middle element in a linked list


struct node{
    int data;
    struct node* next;
};

int display(struct node*ptr){
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

int getmiddle(struct node *head){
    struct node *ptr;
    ptr=head;
    int count=0;
    while(ptr!=NULL){
        count++;
        ptr=ptr->next;
    }

    int mid=count/2;
    
    for(int i=0;i<mid;i++){
        head=head->next;
    }

    return head->data;

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

    printf("\nThe middle element of the linked list is: \n");
    int midelement=getmiddle(head);
    printf("%d",midelement);
     
    
    return 0;
}
