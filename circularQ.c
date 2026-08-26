#include<stdio.h>
#include<stdlib.h>
#define max 10

//to insert elements
void enqueue(int arr[], int *front, int *rear, int item)
{
       if(*front == (*rear+1)%max)
       {
        printf("overflow!\n");
        return ;
       }
       if(*front == -1) //because if front = -1 , then rear = -1 , then to inser element into q , we updated then to 0
       {
        *rear=0;
        *front=0;
        arr[*rear]=item;
       }
       else{
        *rear= (*rear+1)%max; 
        //if queue is full then rear+1 == max , so this function is saying that if quque is full them % it with max
        //  then rear will be 0 , and new element will be inserted at arr[0] ie at start of the queue
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
        if(*front==*rear)  //its saying that if only 1 element exists , then after dequeing queue should be empty
        {
            *front = *rear =-1;
        }
        else
        {
        *front =(*front +1)%max;  //deletion
        }
    }

}
void traverse(int arr[] , int *front , int *rear)
{
     if(*front== -1)
     {
        printf("empty!\n");
     }
     int i=*front;
     while(1)
     {
        printf("%d",arr[i]);
        if(i==rear)
        {
            break;
        }
        i=(i+1)%max;  //moves to the next position, including wrapping around.
     }
     printf("\n");
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