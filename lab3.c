// Develop a C program to:
// 1.Read two sparse matrices of the same order.
// 2.Convert both into 3-tuple representation.
// 3.Perform matrix addition.
// 4.Display the resultant matrix in both normal matrix form and 3-tuple form.

#include <stdio.h>

#define MAX 20

typedef struct TERM
{
    int row, col, val;
} TERM;

void convert(int a[MAX][MAX], TERM t[], int r, int c)
{
    int i, j, k = 1;

    /* First row stores rows, columns and number of non-zero elements  3*3*/
    t[0].row = r;
    t[0].col = c;

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (a[i][j] != 0)
            {
                t[k].row = i;
                t[k].col = j;
                t[k].val = a[i][j];
                k++;
            }
        }
    }

    t[0].val = k - 1;
}

void displayTuple(TERM t[])
{
    int i;

    printf("Row\tCol\tVal\n");

    for (i = 0; i <= t[0].val; i++)
    {
        printf("%d\t%d\t%d\n",
               t[i].row,
               t[i].col,
               t[i].val);
    }
}

int main()
{
    int a[MAX][MAX], b[MAX][MAX], sum[MAX][MAX];
    int r, c, i, j;

    TERM t1[MAX], t2[MAX], ts[MAX];

    printf("Enter rows and columns: ");
    scanf("%d%d", &r, &c);

    printf("Enter first matrix:\n");

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter second matrix:\n");

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    /* Convert first matrix to 3-tuple */
    convert(a, t1, r, c);

    /* Convert second matrix to 3-tuple */
    convert(b, t2, r, c);

    printf("\nMatrix 1 3-Tuple:\n");
    displayTuple(t1);

    printf("\nMatrix 2 3-Tuple:\n");
    displayTuple(t2);

    /* Matrix addition */
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }

    /* Convert resultant matrix to 3-tuple */
    convert(sum, ts, r, c);

    /* Display resultant normal matrix */
    printf("\nResultant Matrix:\n");

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d\t", sum[i][j]);
        }

        printf("\n");
    }

    /* Display resultant 3-tuple */
    printf("\nResultant 3-Tuple:\n");
    displayTuple(ts);

    return 0;
}
