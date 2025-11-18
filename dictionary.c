/* Implement a dictionary using a binary search tree where the dictionary stores keywords & its meanings. Perform following operations:
	Insert a keyword
	Delete a keyword
	Create mirror image and display level wise
    Copy
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct TreeNode 
{
    char name[20];
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* getnode() 
{
    TreeNode* newnode = (TreeNode*)malloc(sizeof(TreeNode));
    printf("Enter Name: ");
    scanf("%s", newnode->name);  
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

TreeNode* create(TreeNode* root) 
{
    char ch = 'y';
    while (ch == 'y') 
	{
        TreeNode* temp = root;
        int flag = 0;
        TreeNode* curr = getnode();

        if (root == NULL) 
		{
            return curr;  
        }

        while (flag == 0) 
		{
            if (strcmp(temp->name, curr->name) > 0) 
			{
                if (temp->left == NULL) 
				{
                    temp->left = curr;
                    flag = 1;
                } 
				else 
				{
                    temp = temp->left;
                }
            } 
			else 
			{
                if (strcmp(temp->name, curr->name) < 0) 
				{
                    if (temp->right == NULL) 
					{
                        temp->right = curr;
                        flag = 1;
                    } 
					else 
					{
                        temp = temp->right;
                    }
                } 
                else 
                {
                    
                    printf("Name already exists in the tree.\n");
                    free(curr);  
                    flag = 1;    
                }
            }
        }
        printf("\nEnter 'y' to continue adding nodes (y/n): ");
        scanf(" %c", &ch);
    }
    return root;
}

void inorder(TreeNode* node) 
{
    if (node == NULL) return;
    inorder(node->left);
    printf("%s ", node->name);
    inorder(node->right);
}

void display(TreeNode *root) 
{
    if (root == NULL) 
	{
        printf("Tree is Empty\n");
        return;
    }

    TreeNode *Q[20];  
    int front = 0, rear = 0;  
    Q[rear++] = root; 
    int level = 0; 

    while (front < rear) 
	{
        int levelSize = rear - front;  
        printf("\nLevel %d: ", level);  

        for (int i = 0; i < levelSize; i++) 
		{
            TreeNode *temp = Q[front++];  

            printf("%s ", temp->name);  
            if (temp->left != NULL) 
			{
                Q[rear++] = temp->left;  
            }
            if (temp->right != NULL) 
			{
                Q[rear++] = temp->right;  
            }
        }
        level++;
    }
    printf("\n");
}

void mirror(TreeNode *root)
{
	TreeNode *temp;
	temp = root->left;
	root->left = root->right;
	root->right = temp;
	if (root->left != NULL)
	{
		mirror(root->left);
	}
	if (root->right != NULL)
	{
		mirror(root->right);
	}
}

TreeNode *copy(TreeNode *root) 
{
    if (root == NULL) 
	{
        return NULL;
    }
    TreeNode *temp = (TreeNode*)malloc(sizeof(TreeNode));
    strcpy(temp->name, root->name);
    temp->left = copy(root->left);
    temp->right = copy(root->right);
    return temp;
}

int main() 
{
    TreeNode *root = NULL;
    char choice;

    root = getnode();
	create(root);  

    do {
        printf("\nMenu:\n");
        printf("1. Inorder Traversal\n");
        printf("2. Level Wise Display\n");
        printf("3. Copy\n");
		printf("4. Mirror\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) 
		{
            case '1':
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case '2':
                printf("Level Wise Display: ");
                display(root);
                break;
            case '3':
			{
                TreeNode *copiedTree = copy(root);
                printf("Tree copied successfully.\n");
                display(copiedTree);
                break;
			}
            case '4':
				mirror(root);
				inorder(root);
				break;
            case '5':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != '5');

    return 0;
}

