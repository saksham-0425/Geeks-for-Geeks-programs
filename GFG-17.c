#include<stdio.h>
#include<stdlib.h>

// Ques- Remove the duplicates elements from the linked list 

struct node{
    int data;
    struct node*next;
};

int display(struct node*ptr){
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

struct node * removeduplicates(struct node*head){
    struct node* p = head;
    
    while (p != NULL && p->next != NULL) {
        struct node* q = p;
        while (q->next != NULL) {
            if (p->data == q->next->data) {
                struct node* temp = q->next;
                q->next = q->next->next;
                free(temp);
            } else {
                q = q->next;
            }
        }
        p = p->next;
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

    // head=deletenode(head);
    // display(head);
    
    head=removeduplicates(head);
    display(head);
    return 0;
}