#include<stdio.h>
void toh(int n , char source , char mid , char destination)
{
    //base case: move only 1 disk , as we move 1st disk from source to destination
    if(n==1)
    {
        printf("move disk 1 from %c to %c\n", source , destination);
        return;
    }

    //move top n-1 disks from source to mid
     toh(n-1 , source , destination , mid);
     // move nth largest disk from source to destination
        printf("move disk %d from %c to %c\n",n, source , destination);

        //move n-1 disks from mid to destination
              toh(n-1 , mid ,source, destination);
}

int main()
{
    int n;
    printf("enter the no. ofdesks: ");
    scanf("%d",&n);
    toh(n,'A','B','C');
    return 0;
}