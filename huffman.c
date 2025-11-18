#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 20

struct symbols
{
    char sym;
    int freq, code[10];
} ARR[MAX];

typedef struct Huff_Tree
{
    char sym;
    int freq;
    struct Huff_Tree *lptr, *rptr;
} HT;

HT *PQ[MAX * 2];
int front = 0, rear = 0;

HT *gethtnode()
{
    HT *temp = (HT *)malloc(sizeof(HT));
    temp->sym = '\0';
    temp->freq = -1;
    temp->lptr = temp->rptr = NULL;
    return temp;
}

int accept()
{
    int n, i, j;
    printf("\n\nEnter the number of Symbols: ");
    scanf("%d", &n);
    while ((getchar()) != '\n');

    for (i = 0; i < n; i++)
    {
        printf("\nSymbol: ");
        scanf("%c", &ARR[i].sym);
        while ((getchar()) != '\n');
        printf("Frequency: ");
        scanf("%d", &ARR[i].freq);
        for (j = 0; j < 10; j++)
            ARR[i].code[j] = -1;
    }
    return n;
}

void insertpq(HT *t)
{
    int i, j;
    if (rear == 0)
    {
        PQ[0] = t;
    }
    else
    {
        for (i = rear - 1; i >= front; i--)
        {
            if (PQ[i]->freq > t->freq)
                PQ[i + 1] = PQ[i];
            else
                break;
        }
        PQ[i + 1] = t;
    }
    rear++;
}

HT *delmin()
{
    if (front == rear) return NULL;
    return PQ[front++];
}

void insertsyms(int n)
{
    for (int i = 0; i < n; i++)
    {
        HT *nht = gethtnode();
        nht->sym = ARR[i].sym;
        nht->freq = ARR[i].freq;
        insertpq(nht);
    }
}

HT *create()
{
    HT *n1, *n2, *n3;

    while (rear - front > 1)
    {
        n1 = delmin();
        n2 = delmin();

        n3 = gethtnode();
        n3->freq = n1->freq + n2->freq;
        n3->lptr = n1;
        n3->rptr = n2;

        insertpq(n3);
    }

    return delmin();
}

int search(HT *t, char x)
{
    if (t == NULL) return 0;
    if (t->sym == x) return 1;
    return search(t->lptr, x) || search(t->rptr, x);
}

void coding(HT *hth, int n)
{
    for (int i = 0; i < n; i++)
    {
        HT *temp = hth;
        int j = 0;

        while (temp->lptr != NULL && temp->rptr != NULL)
        {
            if (search(temp->lptr, ARR[i].sym))
            {
                ARR[i].code[j++] = 0;
                temp = temp->lptr;
            }
            else
            {
                ARR[i].code[j++] = 1;
                temp = temp->rptr;
            }
        }
    }
}

void display(int n)
{
    printf("\n\nSYMBOL\tFREQUENCY\tCODE\n");
    for (int i = 0; i < n; i++)
    {
        printf("\n  %c   \t   %3d   \t", ARR[i].sym, ARR[i].freq);
        if (ARR[i].code[0] == -1)
            printf("0/1");
        else
        {
            for (int j = 0; ARR[i].code[j] != -1; j++)
                printf("%d", ARR[i].code[j]);
        }
    }
}

void freeTree(HT *root)
{
    if (root == NULL) return;
    freeTree(root->lptr);
    freeTree(root->rptr);
    free(root);
}

int main()
{
    int no_syms;
    char con;

    do
    {
        printf("\n\tGenerate HUFFMAN CODES\n");

        no_syms = accept();
        for (int i = 0; i < MAX * 2; i++)
            PQ[i] = NULL;
        front = rear = 0;

        insertsyms(no_syms);
        HT *hthead = create();

        coding(hthead, no_syms);
        display(no_syms);

        freeTree(hthead);

        printf("\n\nDo you want to continue (y/n): ");
        scanf(" %c", &con);
    } while (tolower(con) == 'y');

    return 0;
}
