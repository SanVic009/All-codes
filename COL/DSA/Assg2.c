#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//input of the values of matrix
void insertVal (int mat[20][20], int cols, int rows){
    printf("Enter the values of the matrix: \n");
    for (int  i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("Enter the value of mat[%d][%d] :", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

//display of the sparse matrix
void display (int mat[20][20], int cols, int rows){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

//display of compact matrix
void displayCompt ( int mat[20][3])
{
    int rows = mat[0][2] + 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

//converting to compact matrix 
void compact(int mat[20][20], int rows, int cols, int compactMat[10][3]){
    int compRow =1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if(mat[i][j] != 0)
            {
                compactMat[compRow][0] = i;
                compactMat[compRow][1] = j;
                compactMat[compRow][2] = mat[i][j];
                compRow++;
            }
        }
    }
    compactMat[0][0] = rows;
    compactMat[0][1] = cols;
    compactMat[0][2] = (compRow-1);
}

// void simpleTranspose(int mat[10][3], int transMat[20][20]){

//     int size = mat[0][2];
//     // int transMat[10][3];

//     for (int i = 0; i < size; i++)
//     {
//         if(mat[i][1] == i){
//             transMat[i][0] = mat[i][1];
//             transMat[i][1] = mat[i][0];
//             transMat[i][2] = mat[i][2];
//         }
//     }
// }

int main(){

    int rows, cols, transMat[20][20];

    printf("Enter the values of rows and columns:");
    scanf("%d %d", &rows, &cols );

    int **mat = (int **) calloc (rows, sizeof(int));
    for (int i = 0; i < rows; i++)
    {
        mat[i] = (int *) calloc(cols, sizeof(int));
    }

    int **compactMat = (int **) calloc(rows, sizeof(int));
    for (int i = 0; i < rows; i++)
    {
        compactMat[i] = (int *) calloc(cols, sizeof(int));
    }

    // int **transMat = (int **) calloc(rows, sizeof(int));
    // for (int i = 0; i < rows; i++)
    // {
    //     transMat[i] = (int *) calloc(cols, sizeof(int));
    // }

    insertVal(mat, cols, rows);
    display(mat, cols, rows);

    printf("Compact martix is: \n");
    compact(mat, rows, cols,compactMat);

    // int size = compactMat[0][2];

    displayCompt(compactMat);


    return 0;
}