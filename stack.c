/* Implement stack as an ADT and apply it for different expression conversions (infix to postfix or infix to prefix 
(Any one), prefix to postfix or prefix to infix, postfix to infix or postfix to prefix (Any one) */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char stack[50];
int top = -1;

void push(char c) 
{
    if (top == 49) 
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop() 
{
    if (top == -1) 
    {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack[top--];
}

char peek() 
{
    if (top == -1) 
    {
        return '\0';
    }
    return stack[top];
}

int priority(char op) 
{
    switch (op) 
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

int isempty() 
{
    return top == -1;
}

void infixToPostfix(char infix[], char postfix[]) 
{
    char token;
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; i++) 
    {
        token = infix[i];

        if (isalnum(token)) 
        {
            postfix[j++] = token;
        } 
        else if (token == '(') 
        {
            push(token);
        }
        else if (token == ')') 
        {
            while (!isempty() && peek() != '(') 
            {
                postfix[j++] = pop();
            }
            if (!isempty())
            {
                pop(); 
            }
        } 
        else 
        {
            while (!isempty() && priority(token) <= priority(peek())) 
            {
                postfix[j++] = pop();
            }
            push(token);
        }
    }

    while (!isempty()) 
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

void infixToPrefix(char infix[], char prefix[]) 
{
    int i, j = 0;
    char reversedInfix[50], temp;

    
    int len = strlen(infix);
    for (i = 0; i < len; i++) 
    {
        if (infix[i] == '(')
            reversedInfix[len - 1 - i] = ')';
        else if (infix[i] == ')')
            reversedInfix[len - 1 - i] = '(';
        else
            reversedInfix[len - 1 - i] = infix[i];
    }
    reversedInfix[len] = '\0';

    
    char reversedPostfix[50];
    infixToPostfix(reversedInfix, reversedPostfix);

   
    len = strlen(reversedPostfix);
    for (i = 0; i < len; i++)
        prefix[i] = reversedPostfix[len - 1 - i];
    prefix[len] = '\0';
}

void postfixToPrefix(char postfix[], char prefix[]) 
{
    char token;
    int i, j = 0;
    char temp[50];

   
    char stack[50][50];
    int top = -1;

    for (i = 0; postfix[i] != '\0'; i++) 
    {
        token = postfix[i];
        if (isalnum(token)) 
        {
            char temp[2] = {token, '\0'};
            strcpy(stack[++top], temp);
        } 
        else 
        {
            char op1[50], op2[50];
            strcpy(op1, stack[top--]);
            strcpy(op2, stack[top--]);
            sprintf(temp, "%c%s%s", token, op2, op1);
            strcpy(stack[++top], temp);
        }
    }

    strcpy(prefix, stack[top]);
}

void prefixToPostfix(char prefix[], char postfix[]) 
{
    char token;
    int i, j = 0;
    char temp[50];

    char stack[50][50];
    int top = -1;

    int len = strlen(prefix);
    for (i = len - 1; i >= 0; i--) 
    {
        token = prefix[i];
        if (isalnum(token)) 
        {
            char temp[2] = {token, '\0'};
            strcpy(stack[++top], temp);
        } 
        else 
        {
            char op1[50], op2[50];
            strcpy(op1, stack[top--]);
            strcpy(op2, stack[top--]);
            sprintf(temp, "%s%s%c", op1, op2, token);
            strcpy(stack[++top], temp);
        }
    }

    strcpy(postfix, stack[top]);
}

int main() 
{
    char infix[50], postfix[50], prefix[50];
    int choice;

    do 
    {
        printf("\nMenu:\n");
        printf("1. Infix to Postfix\n");
        printf("2. Infix to Prefix\n");
        printf("3. Postfix to Prefix\n");
        printf("4. Prefix to Postfix\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter infix expression: ");
                scanf("%s", infix);
                infixToPostfix(infix, postfix);
                printf("Postfix expression: %s\n", postfix);
                break;

            case 2:
                printf("Enter infix expression: ");
                scanf("%s", infix);
                infixToPrefix(infix, prefix);
                printf("Prefix expression: %s\n", prefix);
                break;

            case 3:
                printf("Enter postfix expression: ");
                scanf("%s", postfix);
                postfixToPrefix(postfix, prefix);
                printf("Prefix expression: %s\n", prefix);
                break;

            case 4:
                printf("Enter prefix expression: ");
                scanf("%s", prefix);
                prefixToPostfix(prefix, postfix);
                printf("Postfix expression: %s\n", postfix);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please enter a number between 1 and 5.\n");
        }

    } while (choice != 5);

    return 0;
}
