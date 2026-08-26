#include<stdio.h>
#include<stdlib.h>
void enqueue1(int arr1[] , int max , int *front1 , int *rear1, int item)
{
      if(*rear1 == max -1)
    {
        printf("overflow!");
    }
    else if(*rear1 == -1)
    {
        *rear1 = 0;
        *front1 = 0;
        arr1[*rear1] = item;
    }
    else
    {
         *rear1 +=1;
         arr1[*rear1] = item;
    }
}

void enqueue2(int arr2[] , int max , int *front2 , int *rear2, int num)
{
     if(*rear2 == max -1)
    {
        printf("overflow!");
    }
    else if(*rear2 == -1)
    {
        *rear2 = 0;
        *front2 = 0;
        arr2[*rear2] = num;
    }
    else
    {
         *rear2 +=1;
         arr2[*rear2] = num;
    }
}

void dequeue1(int arr1[] , int max , int *front1 , int *rear1)
{
    if(*front1 == -1)
    {
        printf("underflow!");
    }
    else
    {
        printf("%d is dequeued ", arr1[*front1]);
        *front1 = *front1 +1;
    }
}

void dequeue2(int arr2[] , int max , int *front2 , int *rear2)
{
    if(*front2 == -1)
    {
        printf("underflow!");
    }
    else
    {
        printf("%d is dequeued ", arr2[*front2]);
        *front2 = *front2 +1;
    }
}

int main()
{
    int queue1[20] , queue2[20] , front1 = -1 , front1 =-1, rear1 =-1, rear2=-1;
    int choice, value;
    printf("------- IMPLEMENTATION OF STACK USING QUEUE-------\n");
    while(1)
    {
        printf("\n1.enqueue\n2.dequeue\n3.showing result\n4.exit");
        printf("\nenter the choice: ");
        scanf("%d", &choice);
    }
}