/*Department of Computer Engineering has student's club named 'Pinnacle Club'. Students of second, third and 
final year of department can be granted membership on request. Similarly, one may cancel the membership of club. 
First node is reserved for president of club and last node is reserved for the secretary of the club. Write C 
program to maintain club member ‘s information using singly linked list. Store student PRN and Name. 
Write functions to: a) Add and delete the members as well as president or even secretary. b) Compute total number 
of members of club c) Display members d) sorting of two linked list e) merging of two linked list 
f) Reversing using three pointers */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node 
{
    char name[20];
    char prn[11];
    struct node *next;
} Node;

Node *getnode() 
{
    Node *newnode;
    newnode = (Node *)malloc(sizeof(Node));
    printf("\nEnter the Name: ");
    scanf(" %s", newnode->name);
    printf("\nEnter the PRN: ");
    scanf(" %s", newnode->prn);
    newnode->next = NULL;
    return newnode;
}

Node *create(Node *head) 
{
    Node *temp, *newnode;
    char ch = 'y';
    
    temp = head;
    while (ch == 'y') 
    {
        newnode = getnode();
        temp->next = newnode;
        temp = newnode;
        printf("\n Do you want to add a node (y/n): ");
        scanf(" %c", &ch);
    }
    
    return head;
}

int len(Node *head) 
{
    int i = 0;
    Node *curr;
    curr = head->next;
    while (curr != NULL) 
    {
        i++;
        curr = curr->next;
    }
    return i;
}

void insert(Node *head) 
{
    int i = 0, pos, k;
    Node *curr, *newnode;
    curr = head;
    k = len(head);
    newnode = getnode();
    printf("\n Enter Position: ");
    scanf("%d", &pos);
    if (pos > k + 1 || pos < 1) 
    {
        printf("Invalid position!\n");
    } 
    else 
    {
        while (curr != NULL && i < pos - 1) 
        {
            i++;
            curr = curr->next;
        }
        newnode->next = curr->next;
        curr->next = newnode;
    }
}

void delete(Node *head) 
{
    int pos, i = 0;
    Node *curr, *temp;
    curr = head;
    int k = len(head);
    printf("\n Enter Position to Delete: ");
    scanf("%d", &pos);
    if (pos > k || pos < 1) 
    {
        printf("Invalid position!\n");
    } 
    else 
    {
        while (curr != NULL && i < pos - 1) 
        {
            i++;
            curr = curr->next;
        }
        temp = curr->next;
        curr->next = temp->next;
        free(temp);
    }
}

void merge(Node *head1, Node *head2) 
{
    Node *temp = head1;
    while (temp->next != NULL) 
    {
        temp = temp->next;
    }
    temp->next = head2->next;
    free(head2);
}

void selection_sort(Node *head) 
{
    Node *i, *j;
    char temp_name[20], temp_prn[11];
    
    for (i = head->next; i != NULL; i = i->next) 
    {
        for (j = i->next; j != NULL; j = j->next) 
        {
            if (strcmp(i->prn, j->prn) > 0) 
            {
                // Swap names
                strcpy(temp_name, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, temp_name);
                
                // Swap PRNs
                strcpy(temp_prn, i->prn);
                strcpy(i->prn, j->prn);
                strcpy(j->prn, temp_prn);
            }
        }
    }
}

void display(Node *head) 
{
    Node *temp;
    temp = head->next;
    if (temp == NULL) 
    {
        printf("\n List Empty");
        return;
    }
    while (temp != NULL) 
    {
        printf(" %s (%s) ", temp->name, temp->prn);
        temp = temp->next;
    }
    printf("\n");
}

int main() 
{
    int ch;
    Node *head, *head2;

    head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    
    do 
    {
        printf("1. Create SLL\n2. Insert\n3. Delete\n4. Merge\n5. Selection Sort\n6. Display\n7. Exit\nEnter your Choice: ");
        scanf("%d", &ch);
        switch (ch) 
        {
            case 1:
                printf("\n Create SLL\n");
                head = create(head);
                break;
            case 2:
                insert(head);
                break;
            case 3:
                delete(head);
                break;
            case 4:
                head2 = (Node *)malloc(sizeof(Node));
                head2->next = NULL;
                head2 = create(head2);
                merge(head, head2);
                break;
            case 5:
                selection_sort(head);
                break;
            case 6:
                printf("\n Display SLL\n");
                display(head);
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Oops! Wrong Choice\n");
        }
    } while (ch != 7);

    return 0;
}