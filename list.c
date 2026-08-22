//stack using linked list
// global variable 
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int value)
{
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = value;
    newnode->next = NULL;

    if (top == NULL)
    {
        top = newnode;
    }
    else
    {
        temp = top;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
    }
}

void pop()
{
    struct node *temp, *prev;

    if (top == NULL)
    {
        printf("Stack Underflow\n");
        return;
    }

    if (top->next == NULL)
    {
        printf("Deleted: %d\n", top->data);
        free(top);
        top = NULL;
    }
    else
    {
        temp = top;

        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }

        printf("Deleted: %d\n", temp->data);

        prev->next = NULL;
        free(temp);
    }
}

void display()
{
    struct node *temp;

    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    temp = top;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    push(10);
    push(20);
    push(30);

    display();

    pop();
    display();

    return 0;
}