#include <stdio.h>
#include <string.h>

void palindrome(char str[]){
    int len=strlen(str);
    int count=0;
    for (int i=0; i<len/2;i++){
        if(str[i]==str[len-i-1]) count++;
    }
    if(count==(len/2))printf("This string is a plindrome\n");
    else printf("This string is not a palindrome.\n");
}

int main(){
    char *input;
    gets(input);
    palindrome(input);
    return 0;
}