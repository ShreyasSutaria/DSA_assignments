#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *head = NULL;

node* create_node();
void display();
int count_nodes();
void add_first(int data);
void add_last(int data);
void add_special(int data,int pos);
void delete_last();
void delete_first();
void delete_special(int pos);

int main()
{
    add_first(40);
    add_first(30);
    add_first(20);
    add_first(10);
    display();
    add_last(50);
    display();
    return 0;

    node *result;
    result = linearsearch(20);
    If(result == NULL)
    {
        Printf("Key not found ");
    }
    Else
    {
        Printf("Key found !");
    }

}

node* create_node()
{
    node *new_node = malloc(sizeof(node));
    new_node->data = 0;
    new_node->next = NULL;

    return new_node;
}

void display()
{
    if(head == NULL)
    {
        printf("List is Empty!\n");
    }
    else
    {
     node *trav = head;
     printf("Head");
     do{
        printf("->%d",trav->data);
        trav = trav->next;
     }while(trav != head);
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

void add_first(int data)
{
    node* new_node = create_node();
    new_node->data = data;

    if(head == NULL)
    {
        head = new_node;
        new_node->next = head; //circular
    }
    else
    {
      node *trav = head;
      while(trav->next != NULL)
      {
        trav = trav->next;
      } 
      new_node->next = head;
      head=new_node;

      trav->next =head;
    }
}

void add_last(int data)
{
    node* new_node = create_node();
    new_node->data = data;

    if(head == NULL)
    {
        head = new_node;
        new_node->next = head; // circular
    }
    else
    {
        node* trav=head;
        while(trav->next != head);
        {
            trav = trav->next;
        }
        trav->next = new_node;
        new_node->next=head; //circular
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
        node *new_node=create_node();
        new_node->data = data;

        node *trav=head;
        for(int i=1;i<pos-1;i++)
        {
            trav = trav->next;
        }
        new_node->next = trav->next;
        trav->next = new_node;
    }
 }

void delete_first()
{
    if(head == NULL)
    {
        printf("List is empty!");
    }
    else if(head->next=NULL)
    {
        free(head);
        head=NULL;
    }
    else
    {
        node *trav = head;
        while(trav->next != head);
        {
          trav=trav->next;
        }
        node *temp = head;
        head = temp->next;
        trav->next = head;

        free(temp);
        temp = NULL;
    }
}

void delete_last()
{
    if(head==NULL)
    {
        printf("List is empty");
    }
    else if(head->next == head)
    {
        free(head);
        head=NULL;
    }
    else
    {
        node *trav=head;
        while(trav->next->next != NULL)
        {
            trav = trav->next;
        }
        free(trav->next);
        trav->next = head;
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
        node *trav = head;
        for(int i=1;i<pos-1;i++)
        {
            trav = trav->next;
        }

        node *temp = trav->next;
        trav->next=temp->next;
        //trav->next = trav->next->next;
        free(temp);
        temp = NULL;
        
    }
 }

Struct node* linear_search(int key)
{
    Struct node *trav = head;
    do
    {
        If(trav->data == key)
        {
            Return trav;
        }
    Trav = trav->next;
    }While(trav != head)
    Return NULL; // key not found.
    }
