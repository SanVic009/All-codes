# include<stdio.h>

int main(){
    // one huge drawback of scanf is it cannot take multiline strings
    //one method is to use gets and output it by puts://
    char str[100];
    printf("Please enter your name to reprint it using puts :");
    fgets(str,100,stdin);
    puts(str);
    return 0;
}