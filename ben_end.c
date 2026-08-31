#include<stdio.h>
#include<stdlib.h>

struct node
{
     int data;
     struct node *next;
};
typedef struct node sn;

sn *insertAtBeginning(sn *head)
{
    sn *temp ;  //temp is used for new node 
    temp = (sn *)malloc(sizeof(sn));  
    if(temp==NULL)//this actually checks whether the malloc was successful or not
    {
        printf("overflow!");
    }
    else{     //means if memory allocation was successfusl
        temp->next = head; //connect new node to older node
        head=temp;
        printf("\nenter the value: ");
        scanf("%d",&temp-> data);// take the data
    
    }
    
    return head;
}

sn *insertAtEnd(sn *head)
{
    sn *temp; // it will poinr to new node that we want to insert
    temp = (sn*)malloc(sizeof(sn));
    if(temp==NULL)//memory allocation failed
    {
        printf("overflow!");
    }
    else if(head == NULL)//memory allocation successfull and if list is sempty
    {
        head = temp; //because list is empty new node becomes firt node
        temp->next = NULL;// and new node is the last node
        printf("\nenter the value: ");
        scanf("%d", &temp->data);
    }
    else //if list was not empty
    {
        sn *p = head; //p will travel throughout the list
                      // so that we can insert a end

        while(p->next != NULL) // continuing p as long as p is not the last node
        {
           p=p->next; //moves p to next node
        }
        p->next = temp; //new node becomes the last node
        temp->next=NULL; //last node points to null
        scanf("%d",&temp->data);
    }
    return head;
}

sn *deleteAtBeginning(sn *head)
{
    sn *temp;
    if(head==NULL)
    {
        printf("underflow!");
    }
    else
    {
        temp = head;
        head=head->next;
        free(temp);
    }
    return head;
}

sn *deleteAtEnd(sn *head)
{
    sn *temp;
    if(head == NULL)
    {
        printf("underflow!");
    }
    else if(head->next == NULL)  //condition for only one node
    {
        temp=head;
        head=head->next;
        free(temp);
    }
    else  //condition for more then 1 node
    {
        sn *p=head;
        while(p->next->next != NULL)
        {
            p=p->next;
        }

        temp=p->next;
        p->next=NULL;
        free(temp);
    }
    return head;
}

void display(sn *head)
{
    sn *p = head;

    if(head == NULL)
    {
        printf("List is empty!");
    }
    else
    {
        while(p != NULL)
        {
            printf("%d ", p->data);
            p = p->next;
        }
    }
}

int main()
{
    sn *head;
    int choice;
    head=NULL;

    while(1)
    {
        printf("\n----- MENU -----\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at last\n");
        printf("3. Delete from beginning\n");
        printf("4. Delete from last\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1: head = insertAtBeginning(head);
            break;

            case 2: head = insertAtEnd(head);
            break;

            case 3: head = deleteAtBeginning(head);
            break;

            case 4: head = deleteAtEnd(head);
            break ;
            case 5: display(head);
            break;

            case 6: 
            exit(0);

            default: printf("invalid choice");
        }
    }
    return 0;
}