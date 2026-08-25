#include <stdio.h>
#include <stdlib.h>

void enqueue(int arr[], int max, int *front, int *rear, int value)
{
    if (*rear == max - 1)
    {
        printf("Overflow!\n");
    }
    else if (*rear == -1)
    {
        *rear = 0;
        *front = 0;
        arr[*rear] = value;
    }
    else
    {
        *rear = *rear + 1;
        arr[*rear] = value;
    }
}

void push(int arr2[], int max, int *top, int m)
{
    if (*top == max - 1)
    {
        printf("Overflow!\n");
        return;
    }
    else
    {
        *top = *top + 1;
        arr2[*top] = m;
    }
}

int pop(int arr2[], int *top)
{
    int value;

    if (*top == -1)
    {
        printf("Underflow!\n");
        return -1;
    }
    else
    {
        value = arr2[*top];
        *top = *top - 1;
        return value;
    }
}

int dequeue(int arr[], int *front, int *rear)
{
    int value;

    if (*front == -1)
    {
        printf("Underflow!\n");
        return -1;
    }
    else
    {
        value = arr[*front];

        if (*front == *rear)
        {
            *front = -1;
            *rear = -1;
        }
        else
        {
            *front = *front + 1;
        }

        return value;
    }
}

void reverse(int queue[], int stack[], int max,
             int *front, int *rear, int *top)
{
    int m;


    while (*front != -1)
    {
        m = dequeue(queue, front, rear);
        push(stack, max, top, m);
    }


    while (*top != -1)
    {
        m = pop(stack, top);
        enqueue(queue, max, front, rear, m);
    }
}

int main()
{
    int queue[30], stack[30];
    int max = 30;
    int front = -1, rear = -1, top = -1;
    int choice, value;

    while (1)
    {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Reverse");
        printf("\n4. Exit");

        printf("\nEnter the choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);

                enqueue(queue, max, &front, &rear, value);
                printf("Value enqueued!\n");
                break;

            case 2:
                value = dequeue(queue, &front, &rear);

                if (value != -1)
                    printf("%d is dequeued.\n", value);

                break;

            case 3:
                reverse(queue, stack, max, &front, &rear, &top);
                printf("Queue reversed!\n");
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}