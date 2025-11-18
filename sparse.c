/*Write a C program for sparse matrix realization and operations on it- Simple Transpose, Fast Transpose.*/

#include <stdio.h>
#include <string.h>

void display(int a[][3], int m) 
{
    for(int i = 0; i < m; i++) 
    {
        for(int j = 0; j < 3; j++) 
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

void sparseMatrix(int a[][100], int m, int n, int c, int b[][3]) 
{
    int count = 1;
    b[0][0] = m;
    b[0][1] = n;
    b[0][2] = c;
    for(int i = 0; i < m; i++) 
    {
        for(int j = 0; j < n; j++) 
        {
            if (a[i][j] != 0) 
            {
                b[count][0] = i;
                b[count][1] = j;
                b[count][2] = a[i][j];
                count++;
            }
        }
    }
    printf("\nSparse Matrix\n");
    display(b, c + 1); 
}

void simpleTranspose(int b[][3], int m, int n, int c) 
{
    int transpose[c + 1][3];
    
    transpose[0][0] = n;
    transpose[0][1] = m;
    transpose[0][2] = c;
    
    if (c > 0) 
    {
        int current = 1;
        for (int i = 0; i < n; i++) 
        {
            for (int j = 1; j <= c; j++) 
            {
                if (b[j][1] == i) 
                {
                    transpose[current][0] = b[j][1];
                    transpose[current][1] = b[j][0];
                    transpose[current][2] = b[j][2];
                    current++;
                }
            }
        }
    }
    
    printf("\nSimple Transpose\n");
    display(transpose, c + 1); 
}

void fastTranspose(int b[][3], int m, int n, int c) 
{
    int s[n], index[n], transpose[c + 1][3];
    transpose[0][0] = n;
    transpose[0][1] = m;
    transpose[0][2] = c;
    
    
    for (int i = 0; i < n; i++) 
    {
        s[i] = 0;
    }
    
    for (int i = 1; i <= c; i++) 
    {
        s[b[i][1]]++;
    }
    
    index[0] = 1;
    for (int i = 1; i < n; i++) 
    {
        index[i] = index[i - 1] + s[i - 1];
    }
    
    for (int i = 1; i <= c; i++) 
    {
        int j = b[i][1];
        int pos = index[j];
        transpose[pos][0] = b[i][1];
        transpose[pos][1] = b[i][0];
        transpose[pos][2] = b[i][2];
        index[j]++;
    }
    
    printf("\nFast Transpose\n");
    display(transpose, c + 1); 
}

int main() 
{
    int a[100][100], m, n, c = 0, choice1;
    char choice2[10];
    
    do 
    {
        printf("Enter Rows: ");
        scanf("%d", &m);
        printf("Enter Columns: ");
        scanf("%d", &n);
        
        printf("Enter the elements of Sparse Matrix:\n");
        for(int i = 0; i < m; i++) 
        {
            for(int j = 0; j < n; j++) 
            {
                printf("Enter the element in a[%d][%d]: ", i, j);
                scanf("%d", &a[i][j]);
                if (a[i][j] != 0) 
                {
                    c++;
                }
            }
        }
        
        int b[c + 1][3];
        sparseMatrix(a, m, n, c, b);
        
        printf("\nHow do you want to transpose?\n1. Simple Transpose\n2. Fast Transpose\n");
        scanf("%d", &choice1);
        
        switch (choice1) 
        {
            case 1:
                simpleTranspose(b, m, n, c);
                break;
            case 2:
                fastTranspose(b, m, n, c);
                break;
            default:
                printf("Oops Wrong Choice!\n");
        }
        
        printf("\nDo you want to continue?\n1. Yes\n2. No\n");
        scanf("%s", choice2);
    } while(strcmp(choice2, "Yes") == 0 || strcmp(choice2, "yes") == 0);
    
    return 0;
}
