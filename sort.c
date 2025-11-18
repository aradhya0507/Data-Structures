/*Write a C program to create a student database using an array of structures. Apply Sorting techniques
(Bubble sort ,Insertion Sort, Selection Sort).*/

#include <stdio.h>
struct student 
{
    int rn;
    char n[20];
} s[100], copy;

void getData(struct student s[], int n1) 
{
    for (int i = 0; i < n1; i++) 
    {
        printf("Enter Name: ");
        scanf("%19s", s[i].n); 
        printf("Enter Roll Number: ");
        scanf("%d", &s[i].rn);
    }
}

void display(struct student s[], int n1) 
{
    printf("Name\tRoll Number\n");
    for (int i = 0; i < n1; i++) 
    {
        printf("%s\t%d\n", s[i].n, s[i].rn);
    }
}

void bubbleSort(struct student s[], int n1) 
{
    for (int i = 0; i < n1 - 1; i++) 
    {
        for (int j = 0; j < n1 - i - 1; j++) 
        {
            if (s[j].rn > s[j + 1].rn) 
            {
                copy = s[j];
                s[j] = s[j + 1];
                s[j + 1] = copy;
            }
        }
    }
}

void selectionSort(struct student s[], int n1) 
{
    for (int i = 0; i < n1 - 1; i++) 
    {
        int min = i;
        for (int j = i + 1; j < n1; j++) 
        {
            if (s[j].rn < s[min].rn)
            {
                min = j;
            }
        }
        copy = s[min];
        s[min] = s[i];
        s[i] = copy;
    }
}

void insertionSort(struct student s[], int n1) 
{
    for (int i = 1; i < n1; i++) 
    {
        struct student key = s[i];
        int j = i - 1;
        while (j >= 0 && s[j].rn > key.rn) 
        {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = key;
    }
}


int main() 
{
    int size, ch, cho;
    
    do 
    {
        printf("Enter Number of Students: ");
        scanf("%d", &size);

        getData(s, size);

        printf("Enter your Choice\n1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n");
        scanf("%d", &ch);

        switch (ch) 
        {
            case 1:
                bubbleSort(s, size);
                display(s, size);
                break;
            case 2:
                selectionSort(s, size);
                display(s, size);
                break;
            case 3:
                insertionSort(s, size);
                display(s, size);
                break;
            default:
                printf("Oops! Wrong Choice\n");
                continue;
        }

        printf("\nDo you want to continue?\n1. Yes\n2. No\n");
        scanf("%d", &cho);

    } while (cho == 1);

    return 0;
}
