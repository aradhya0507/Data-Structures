/*Implement threaded binary tree and perform inorder traversal.*/

#include <stdio.h>
#include <stdlib.h>

struct tbtnode
{
    int data;
    int rbit, lbit;
    struct tbtnode *rightc;
    struct tbtnode *leftc;
};

struct tbtnode *head = NULL;

void create()
{
    if (head != NULL)
    {
        printf("Tree already exists. Please choose another option.\n");
        return;
    }

    head = (struct tbtnode*)malloc(sizeof(struct tbtnode));
    head->lbit = 1;
    head->rbit = 0;
    head->leftc = head->rightc = head;

    struct tbtnode *root = (struct tbtnode*)malloc(sizeof(struct tbtnode));
    printf("Enter root data: ");
    scanf("%d", &root->data);
    head->leftc = root;
    root->lbit = root->rbit = 0;
    root->leftc = head;
    root->rightc = head;

    char ch;
    do
    {
        int flag = 0;
        struct tbtnode *temp = root;
        struct tbtnode *curr = (struct tbtnode*)malloc(sizeof(struct tbtnode));
        printf("Accept data for new node: ");
        scanf("%d", &curr->data);
        curr->lbit = curr->rbit = 0;

        while (flag == 0)
        {
            char choice;
            printf("Choose direction (l/r): ");
            scanf(" %c", &choice);

            if (choice == 'l')
            {
                if (temp->lbit == 0)
                {
                    curr->rightc = temp;
                    curr->leftc = temp->leftc;
                    temp->leftc = curr;
                    temp->lbit = 1;
                    printf("%d attached to left of %d\n",curr->data,temp->data);
                    flag = 1;
                }
                else
                {
                    temp = temp->leftc;
                }
            }
            else if (choice == 'r')
            {
                if (temp->rbit == 0)
                {
                    curr->leftc = temp;
                    curr->rightc = temp->rightc;
                    temp->rightc = curr;
                    temp->rbit = 1;
                    printf("%d attached to right of %d\n",curr->data,temp->data);
                    flag = 1;
                }
                else
                {
                    temp = temp->rightc;
                }
            }
            else
            {
                printf("Invalid choice. Please enter 'l' or 'r'.\n");
            }
        }

        printf("Continue adding nodes? (y/n): ");
        scanf(" %c", &ch);
    } while (ch == 'y');
}

void display(struct tbtnode *node)
{
    if (node == head) return;
    printf("%d", node->data);
    if (node->lbit) display(node->leftc);
    if (node->rbit) display(node->rightc);
}

void showTree()
{
    if (head == NULL)
    {
        printf("The tree is empty.\n");
        return;
    }
    printf("Tree elements: ");
    display(head->leftc);
    printf("\n");
}

int main()
{
    int choice;
    do
    {
        printf("\nMenu:\n1. Create Tree\n2. Display Tree\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                create();
                break;
            case 2:
                showTree();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);
    return 0;
}