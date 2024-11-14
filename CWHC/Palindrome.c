#include <stdio.h>
#include <string.h>

void palindrome(int number){
    int rev=0;
    int temp=number;
    while(number!=0){
        rev=rev*10+(number%10);
        number=number/10;
    }

    if(temp==rev){
        printf("The number entered is a palindrome.\n");
    } else printf("The number entered is not a palindrome.\n");
}

int main(){
    int num;
    printf("Enter the number :");
    scanf("%d", &num);
    palindrome(num);
    return 0;
}