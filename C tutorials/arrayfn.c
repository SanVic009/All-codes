# include<stdio.h>

void prnnum(int arr[], int n);

int main(){
    int arr[]= {1,2,3,4,5,6,};
    prnnum(arr,6);
    return 0;
}

void prnnum(int arr[], int n){
    for(int i=0;i<n;i++){
        printf("%d \t", arr[i]);
    }
}