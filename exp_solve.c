#include<stdio.h>
#include<ctype.h>
int stack[100];
int top=-1;
void push(int m)
{
    top+=1;
    stack[top]=m;
}
int pop()
{
    int a;
    if(top== -1)
    {
        return -1;
    }
    else{
       a=stack[top];
       top--;
       return a;
    }
}
int main()
{
     int t;
     printf("enter the no. of test cases: ");
     scanf("%d",&t);
     for(int i=0; i< t; i++)
     {
        char str[100];
        printf("enter the string: ");
        fgets(str, 100, stdin);
        int res=0;
        for(int j=0 ; str[j]!='\0'; j++)
        {
             if( isdigit(str[j]))
             {
                   push(str[j]- '0');
             }
             else if(str[j]== '+'|| str[j]== '-'|| str[j]== '/'|| str[j]== '*'|| str[j]== '%')
             {
                int  a=pop(), b=pop();
                if(str[j]== '+')
                {
                    res=a+b;
                }
                else if(str[j]== '-')
                {
                    res=b-a;
                }
                else if(str[j]== '/')
                {
                    res=b/a;
                }
                else if(str[j]== '*')
                {
                    res=b*a;
                }
                else if(str[j]== '%')
                {
                    res=b%a;
                }
                push(res);

             }

        }
        printf("\nresult is %d: ", res);
     }
    return 0;
}