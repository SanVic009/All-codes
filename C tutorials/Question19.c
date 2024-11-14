# include<stdio.h>

int reverse(int arr[], int n);

int main(){
    int arr[ ]={1,2,3,4,5};
    for (int i=0;i<5;i++){
        if (i==5)
        {
            printf("%d \t \n",arr[i]);
        }else{
             printf("%d \t", arr[i]);
        }
    }
    reverse(arr, 5);

    for (int i=0;i<5;i++){
        if (i==5)
        {
            printf("%d \t \n",arr[i]);
        }else{
             printf("%d \t", arr[i]);
        }
    }
    return 0;
}

int reverse(int arr[], int n){
    for(int i=0;i<n/2;i++){
        int firstval=arr[i];
        int secondval=arr[n-i-1];
        arr[n-i-1]=firstval;
        arr[i]=secondval;
    }
    for(int i=0;i<n;i++){
        printf("%d \t", arr[i]);
    }
}