#include <stdio.h>

#define MAX 100

typedef struct
{
    int row;
    int col;
    int value;
} Term;

void createSparseMatrix(int matrix[][MAX], int rows, int cols, Term sparseMatrix[])
{
    int k = 1;
    sparseMatrix[0].row = rows;
    sparseMatrix[0].col = cols;
    sparseMatrix[0].value = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] != 0)
            {
                sparseMatrix[k].row = i;
                sparseMatrix[k].col = j;
                sparseMatrix[k].value = matrix[i][j];
                k++;
            }
        }
    }
    sparseMatrix[0].value = k - 1;
}

void simpleTranspose(Term a[], Term b[])
{
    int n = a[0].value;
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].value = n;

    int k = 1;
    for (int i = 0; i < a[0].col; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[j].col == i)
            {
                b[k].row = a[j].col;
                b[k].col = a[j].row;
                b[k].value = a[j].value;
                k++;
            }
        }
    }
}

void fastTranspose(Term a[], Term b[])
{
    int rowTerms[MAX], startingPos[MAX];
    int n = a[0].value;
    int numCols = a[0].col;

    b[0].row = numCols;
    b[0].col = a[0].row;
    b[0].value = n;

    if (n > 0)
    {
        for (int i = 0; i < numCols; i++)
        {
            rowTerms[i] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            rowTerms[a[i].col]++;
        }

        startingPos[0] = 1;
        for (int i = 1; i < numCols; i++)
        {
            startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
        }

        for (int i = 1; i <= n; i++)
        {
            int j = startingPos[a[i].col]++;
            b[j].row = a[i].col;
            b[j].col = a[i].row;
            b[j].value = a[i].value;
        }
    }
}

void printSparseMatrix(Term sparseMatrix[])
{
    int n = sparseMatrix[0].value;
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i <= n; i++)
    {
        printf("%d\t%d\t%d\n", sparseMatrix[i].row, sparseMatrix[i].col, sparseMatrix[i].value);
    }
}

int main()
{
    int matrix[MAX][MAX], rows = 0, cols = 0;
    Term sparseMatrix[MAX], transposedMatrix[MAX];
    int choice;

    while (1)
    {
        printf("\nSparse Matrix Menu:\n");
        printf("1. Create Sparse Matrix\n");
        printf("2. Display Sparse Matrix\n");
        printf("3. Simple Transpose\n");
        printf("4. Fast Transpose\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the number of rows and columns of the matrix: ");
            scanf("%d%d", &rows, &cols);

            printf("Enter the elements of the matrix:\n");
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    scanf("%d", &matrix[i][j]);
                }
            }

            createSparseMatrix(matrix, rows, cols, sparseMatrix);
            printf("Sparse Matrix created.\n");
            break;

        case 2:
            if (rows == 0 || cols == 0)
            {
                printf("Sparse Matrix not created yet.\n");
            }
            else
            {
                printf("\nSparse Matrix Representation:\n");
                printSparseMatrix(sparseMatrix);
            }
            break;

        case 3:
            if (rows == 0 || cols == 0)
            {
                printf("Sparse Matrix not created yet.\n");
            }
            else
            {
                simpleTranspose(sparseMatrix, transposedMatrix);
                printf("\nSimple Transpose:\n");
                printSparseMatrix(transposedMatrix);
            }
            break;

        case 4:
            if (rows == 0 || cols == 0)
            {
                printf("Sparse Matrix not created yet.\n");
            }
            else
            {
                fastTranspose(sparseMatrix, transposedMatrix);
                printf("\nFast Transpose:\n");
                printSparseMatrix(transposedMatrix);
            }
            break;

        case 5:
            printf("Exiting program.\n");
            return 0;

        default:
            printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    }

    return 0;
}
/*
~~~~~~~~~~~~~~~~~~~~ OUTPUT ~~~~~~~~~~~~~~~~~~~~ 

PS C:\Users\Sanch\OneDrive\Sanchit\All codes\COL\DSAColl> cd "c:\Users\Sanch\OneDrive\Sanchit\All codes\COL\DSAColl\" ; if ($?) { gcc Test2.c -o Test2 } ; if ($?) { .\Test2 }

Sparse Matrix Menu:
1. Create Sparse Matrix
2. Display Sparse Matrix
3. Simple Transpose
4. Fast Transpose
5. Exit
Enter your choice: 1
Enter the number of rows and columns of the matrix: 3
3
Enter the elements of the matrix:
0
0
0
1
1
1
0
1
1
Sparse Matrix created.

Sparse Matrix Menu:
1. Create Sparse Matrix
2. Display Sparse Matrix
3. Simple Transpose
4. Fast Transpose
5. Exit
Enter your choice: 2

Sparse Matrix Representation:
Row     Column  Value
3       3       5
1       0       1
1       1       1
1       2       1
2       1       1
2       2       1

Sparse Matrix Menu:
1. Create Sparse Matrix
2. Display Sparse Matrix
3. Simple Transpose
4. Fast Transpose
5. Exit
Enter your choice: 3

Simple Transpose:
Row     Column  Value
3       3       5
0       1       1
1       1       1
1       2       1
2       1       1
2       2       1

Sparse Matrix Menu:
1. Create Sparse Matrix
2. Display Sparse Matrix
3. Simple Transpose
4. Fast Transpose
5. Exit
Enter your choice: 4

Fast Transpose:
Row     Column  Value
3       3       5
0       1       1
1       1       1
1       2       1
2       1       1
2       2       1

Sparse Matrix Menu:
1. Create Sparse Matrix
2. Display Sparse Matrix
3. Simple Transpose
4. Fast Transpose
5. Exit
Enter your choice: 5
Exiting program.
*/