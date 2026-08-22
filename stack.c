#include <stdio.h>

#define MAX 100

void create(int stack[], int *top)
{
    *top = -1;
}

void push(int stack[], int *top, int value)
{
    if (*top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        (*top)++;
        stack[*top] = value;
    }
}

void pop(int stack[], int *top)
{
    if (*top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("Popped Element = %d\n", stack[*top]);
        (*top)--;
    }
}

void print(int stack[], int top)
{
    int i;

    if (top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Stack Elements are:\n");
        for (i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

void size(int top)
{
    printf("Size = %d\n", top + 1);
}

void isEmpty(int top)
{
    if (top == -1)
        printf("Stack is Empty\n");
    else
        printf("Stack is Not Empty\n");
}

int main()
{
    int stack[MAX];
    int top;
    int choice, value;

    create(stack, &top);

    do
    {
        printf("\n1.Push\n2.Pop\n3.Print\n4.Size\n5.Is Empty\n6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            push(stack, &top, value);
            break;

        case 2:
            pop(stack, &top);
            break;

        case 3:
            print(stack, top);
            break;

        case 4:
            size(top);
            break;

        case 5:
            isEmpty(top);
            break;

        case 6:
            printf("Program Ended.\n");
            break;

        default:
            printf("Invalid Choice\n");
        }

    } while (choice != 6);

    return 0;
}