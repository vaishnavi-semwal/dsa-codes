#include<stdio.h>
#include<stdlib.h>
#define max 10
void enqueue(int arr[], int *front, int *rear, int item)
{
       if(*rear== max-1)
       {
        printf("overflow!\n");
        return ;
       }
       if(*rear == -1)
       {
        *rear=0;
        *front=0;
        arr[*rear]=item;
       }
       else{
        *rear+=1;
        arr[*rear]=item;
       }
}
void dequeue(int arr[] , int *front , int *rear)
{
    if(*front== -1)
    {
        printf("underflow!\n");
    }
    else
    {
        printf("%d is dequeued\n", arr[*front]);
        (*front)++;
    }

}
void traverse(int arr[] , int *front , int *rear)
{
     if(*front== -1)
     {
        printf("empty!\n");
     }
     else{
       int  i=*front , j=*rear;
        while(arr[i] <= arr[j])
        {
             printf("%d",arr[i]);
             printf("\n");
             i++;
        }
     }
}
int main()
{
    int value ,choice;
    int queue[max], front=-1,rear=-1;
    while(1)
    {
        printf("\n1.enqueue\n2.dequeue\n3.traverse\n4.exit");
        printf("\nenter the choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("\nenter value to enqueue: ");
            scanf("%d",&value);
            enqueue(queue, &front,&rear,value);
            printf("\nvalue enqueued!");
            break;

            case 2: dequeue(queue, &front, &rear);
           
            break;

            case 3: traverse(queue, &front,&rear);
            break;

            case 4:
            
             exit(1);

            default:  printf("invalid choice\n");
          
        }
       
    }
     return 0;
}
