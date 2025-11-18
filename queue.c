/*Queues are frequently used in computer programming, and a typical example is the creation of a job queue by an 
operating system. If the operating system does not use priorities, then the jobs are processed in the order they 
enter the system. Write a program for simulating job queue. Write functions to add job and delete job from queue.*/

#include <stdio.h>
#include <string.h>

struct Queue
{
    char jname[50];
    int jobid;
};

struct Queue Q[5];
int rear = -1;
int front = -1;
int id = 1;

int Full()
{
    if ((rear + 1) % 5 == front)
    {
        return 1;
    }
    return 0;
}


int Empty()
{
    if (rear == front)
    {
        return 1;
    }
    return 0;
}


void linadd()
{
    if (Full())
    {
        printf("Sorry! Queue is Full\n\n");
    }
    else
    {
        rear++;
        if (rear >= 5)
        {
            rear = 0;
        }
        Q[rear].jobid = id++;
        printf("Enter job name: ");
        scanf("%s", Q[rear].jname);
        printf("\nJob added successfully\n");
    }
}


void ciradd()
{
    if (Full())
    {
        printf("Sorry! Queue is Full\n\n");
    }
    else
    {
        rear = (rear + 1) % 5;
        Q[rear].jobid = id++;
        printf("Enter job name: ");
        scanf("%s", Q[rear].jname);
        printf("\nJob added successfully\n");
    }
}


void lindelet()
{
    if (Empty())
    {
        printf("\nQueue is Empty\n");
    }
    else
    {
        printf("\nDeleted Job ID: %d, Job Name: %s\n", Q[front + 1].jobid, Q[front + 1].jname);
        front++;
        if (front >= 5)
        {
            front = 0;
        }
        if (front > rear)
        {
            front = -1;
            rear = -1;
        }
    }
}


void cirdelet()
{
    if (Empty())
    {
        printf("\nQueue is Empty\n");
    }
    else
    {
        printf("\nDeleted Job ID: %d, Job Name: %s\n", Q[front].jobid, Q[front].jname);
        front = (front + 1) % 5;
        if (front == (rear + 1) % 5)
        {
            front = -1;
            rear = -1;
        }
    }
}


void display()
{
    int i;
    printf("\nQueue contents:\n");
    for (i = front + 1; i != (rear + 1) % 5; i = (i + 1) % 5)
    {
        printf("Job ID: %d, Job Name: %s\n", Q[i].jobid, Q[i].jname);
    }
    printf("\n");
}

int main()
{
    int ch, choice, cont = 1;
    do
    {
        printf("Enter your choice:\n1. Linear Queue\n2. Circular Queue\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                front = rear = -1; 
                do
                {
                    printf("\nEnter your choice:\n1. Add Job\n2. Delete Job\n3. Display\n4. Exit\n");
                    scanf("%d", &ch);
                    switch (ch)
                    {
                        case 1:
                            linadd();
                            break;

                        case 2:
                            lindelet();
                            break;

                        case 3:
                            display();
                            break;

                        case 4:
                            cont = 0;
                            break;

                        default:
                            printf("Oops! Wrong choice\n");
                    }

                } while (cont == 1);
                break;

            case 2:
                front = rear = -1; 
                do
                {
                    printf("\nEnter your choice:\n1. Add Job\n2. Delete Job\n3. Display\n4. Exit\n");
                    scanf("%d", &ch);
                    switch (ch)
                    {
                        case 1:
                            ciradd();
                            break;

                        case 2:
                            cirdelet();
                            break;

                        case 3:
                            display();
                            break;

                        case 4:
                            cont = 0;
                            break;

                        default:
                            printf("Oops! Wrong choice\n");
                    }
                    
                } while (cont == 1);
                break;

            default:
                printf("Oops! Wrong choice\n");
        }

    } while (choice == 1 || choice == 2);

    return 0;
}

