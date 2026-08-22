#include <stdio.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    if (top == -1)
        return '\0';
    return stack[top--];
}

int main()
{
    int T;

    printf("Enter number of test cases: ");
    scanf("%d", &T);

    for(int i = 1; i <= T; i++)
    {
        char str[100];

        printf("Enter expression: ");
        scanf("%s", str);

        top = -1;          // Make stack empty
        int balanced = 1;  // Assume expression is balanced

        for(int j = 0; str[j] != '\0'; j++)
        {
            if(str[j] == '(' || str[j] == '{' || str[j] == '[')
            {
                push(str[j]);
            }
            else if(str[j] == ')' || str[j] == '}' || str[j] == ']')
            {
                char ch = pop();

                if((str[j] == ')' && ch != '(') ||
                   (str[j] == '}' && ch != '{') ||
                   (str[j] == ']' && ch != '['))
                {
                    balanced = 0;
                    break;
                }
            }
            else
            {
                balanced = 0;
                break;
            }
        }

        if(top != -1)
        {
            balanced = 0;
        }

        if(balanced)
            printf("Balanced\n");
        else
            printf("Unbalanced\n");
    }

    return 0;
}