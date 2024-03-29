#include <stdlib.h>
struct node{
    int data;
    struct node * addr;
};
 
void insertAtEnd(struct node ** head,int val)
{
    struct node * curr=(struct node *)malloc(sizeof(struct node));
    curr=*head;
    while(curr && curr->addr)
    {
        curr=curr->addr;
    }
    struct node* new_node = (struct node*) malloc(sizeof(struct node)); 
    new_node->data  = val; 
    new_node->addr = NULL; 
    curr->addr= new_node; 
    
}
void printList(struct node ** head)
{
    struct node * curr=(struct node *)malloc(sizeof(struct node));
    curr=*head;
    while(curr)
    {
        printf("%d\n",curr->data);
        printf("%d\n",curr->addr);
        curr=curr->addr;
    }
}
int findMiddleElement(struct node * f,struct node * s)
{
    if(s->addr==NULL)
    return f->data;
    else
    {
        f=f->addr;
        if(s->addr->addr)
        s=s->addr->addr;
        else
        s=s->addr;
        findMiddleElement(f,s);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    struct node* head=(struct node *)malloc(sizeof(struct node));
    head->data=0;
    head->addr=NULL;
    for(int i=0;i<n;i++)
    {
        int val;
        scanf("%d",&val);
        insertAtEnd(&head,val);
    }
    printList(&head);
    
    int num=findMiddleElement(head,head->addr);
    printf("%d\n",num);
    return 0;
}