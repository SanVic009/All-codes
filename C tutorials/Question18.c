# include<stdio.h>

int odd(int arr[], int n);

int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,0};

    printf("Total number of odd numbers in the array is %d", odd(arr, 10));    
    return 0;
}

int odd(int arr[], int n){
    int x=0;
   for(int i=0; i<n;i++){
    if((arr[i]%2)!=0){
        x++;
    }
   }
   return x;
}