#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node* create_node();
void display();
int count_nodes();
void add_first(int data);
void add_last(int data);
void add_special(int data,int pos);
void delete_first();
void delete_last();
void delete_special(int pos);
struct node* find_mid();
 
 int main()
 {
    add_first(40);
    add_first(30);
    add_first(20);
    add_first(10);
    display();
    add_last(50);
    display();
    struct node* mid = find_mid();
    printf("mid = %d\n",mid->data);
    
    

    return 0;
 }

 struct node* create_node()
 {
     struct node *ptr = malloc(sizeof(struct node));

     ptr->data = 0;
     ptr->next = NULL;

     return ptr;
 }

 void display()
 {
    if(head == NULL)
    {
        printf("Link is Empty !\n");
    }
    else
    {
        struct node *trav = head;
        printf("Head");
        while(trav != NULL)
        {
            printf("->%d",trav->data);
            trav = trav->next;
        }
    }
    printf("\n");
 }

 int count_nodes()
 {
    int count = 0;
    if(head == NULL)
    {
        printf("List is Empty!\n");
    }
    else
    {
        struct node *trav=head;
        while(trav != NULL)
        {
            count++;
            trav = trav->next;
        }
    }
    return count;
 }

 void add_first(int data)
 {
    struct node *ptr = create_node();
    ptr->data = data;

    if(head==NULL)
    {
        head=ptr;
    }
    else
    {
        ptr->next = head;
        head = ptr;
    }
 }

 void add_last(int data)
 {
     struct node *ptr = create_node();
     ptr->data = data;

     if(head==NULL)
     {
        head=ptr;
     }
     else
     {
         struct node *trav = head;
         while(trav->next != NULL)
         {
            trav = trav->next;
         }
         trav->next = ptr;
     }
 }

 void add_special(int data,int pos)
 {
    if(head==NULL)
    {
        if(pos == 1)
        {
            add_first(data);
        }
        else
        {
            printf("Invalid.......\n");
        }
    }
    else if(pos == 1)
    {
        add_first(data);
    }
    else if(pos == count_nodes()+1)
    {
        add_last(data);
    }
    else if(pos<1 || pos>count_nodes()+1)
    {
        printf("Invalid\n");
    }
    else
    {
        struct node *ptr=create_node();
        ptr->data = data;

        struct node *trav=head;
        for(int i=1;i<pos-1;i++)
        {
            trav = trav->next;
        }
        ptr->next = trav->next;
        trav->next = ptr;
    }
 }

 void delete_first()
 {
    if(head == NULL)
    {
        printf("List is Empty\n");
    }
    else if(head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct node *temp = head;
        head = head->next;
        //head = temp->next;

        free(temp);
        temp=NULL;
    }
 }

 void delete_last()
 {
    if(head == NULL)
    {
        printf("List is empty\n");
    }
    else if(head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct node *trav = head;
        while(trav->next->next != NULL)
        {
            trav = trav->next;
        }
        free(trav->next);
        trav->next = NULL;
    }
 }

 void delete_special(int pos)
 {
    if(head == NULL)
    {
        printf("List is empty!\n");
    }
    else if(pos==1)
    {
        delete_first();
    }
    else if(pos== count_nodes())
    {
        delete_last();
    }
    else if(pos<1 || pos>count_nodes())
    {
        printf("Invalid\n");
    }
    else
    {
        struct node *trav = head;
        for(int i=1;i<pos-1;i++)
        {
            trav = trav->next;
        }
        struct node *temp = trav->next;
        trav->next=temp->next;
        //trav->next = trav->next->next;
        free(temp);
        temp = NULL;
    }
 }

 struct node* find_mid()
 {
    struct node* slow = head;
    struct node* fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
 }