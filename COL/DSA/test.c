#include <stdio.h>

void accept(int arr[5][5],int m,int n) {
    int i,j;
    printf("Enter the matrix value\n");
    for (i=0;i<m;i++) {
        for (j=0;j<n;j++) {
            scanf("%d",&arr[i][j]);
        }
    }
}

void display(int arr[5][5],int m,int n) {
    int i,j;
    printf("Matrix is:\n");
    for (i=0;i<m;i++) {
        for (j=0;j<n;j++) {
            printf("%d",arr[i][j]);
        }
        printf("\n");
    }
}

void displaySM(int arr[15][3],int m,int n) {
    int i,j;
    printf("Matrix is:\n");
    for (i=0;i<m;i++) {
        for (j=0;j<n;j++) {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}

void compact(int arr[5][5],int m,int n,int b[15][3]) {
    b[0][0] = m;
    b[0][1] = n;
    int k=1;
    int i,j;
    for (i=0;i<m;i++) {
        for (j=0;j<n;j++) {
            if(arr[i][j] != 0) {
                b[k][0] = i;
                b[k][1] = j;
                b[k][2] = arr[i][j];
                k++;
            }
        }
    }
    b[0][2] = k-1;
}

void simpleTranspose(int arr[15][3], int b[15][3]) {
    b[0][0] = arr[0][1];
    b[0][1] = arr[0][0];
    b[0][2] = arr[0][2];

    if (b[0][2] <= 0)
    return;
    int q=1;
    for(int col=0; col< arr[0][1]; col++) {
        for (int p=1; p <= arr[0][2]; p++) {
            if(arr[p][1] == col) {
                b[q][0] = arr[p][1];
                b[q][1] = arr[p][0];
                b[q][2] = arr[p][2];
                q++;
            }
        }
    } 
    displaySM(b,q,3);
}

void fastTranspose(int arr[15][3], int b[15][3])
{
    int i,m,n,pos[15],count[15];
    for(i=0;i<arr[0][1];i++)
    {
        pos[i]=0;
    }
    for(i=0;i<15;i++)
    {
        count[i]=0;
      
    }
    for(i=1;i<=arr[0][2]+1 ;i++)
    {
        m=arr[i][1];
        count[m]++;
    }
    pos[0] = 1;
    for(i=1;i<arr[0][1];i++)
    {
        pos[i] = pos[i-1] + count[i-1];
    }

    for(i=1;i<=arr[0][2];i++)
    {
        m = b[i][1];
        n = pos[m];
        pos[m]++;
        b[n][0]= arr[i][1];
        b[n][1]= arr[i][0];
        b[n][2]= arr[i][2];
    }
    b[0][0]= arr[0][1];
    b[0][1]= arr[0][0];
    b[0][2]= arr[0][2];
    displaySM(b,b[0][2],3);
}

 
int main() {
    
    int m,n,arr[5][5],b[15][3],c[15][3];

    printf("Enter order of matrix\n");
    scanf("%d%d",&m,&n);

    accept(arr,m,n);
    display(arr,m,n);

    compact(arr,m,n,b);
    displaySM(b,b[0][2]+1,3);

    simpleTranspose(b,c);
    
    fastTranspose(b,c);

}