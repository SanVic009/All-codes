# include<stdio.h>
# include<string.h>

// basically yaha %c se input le rahe hai
int main(){
    char str[100];
    char ch;
    int i=0;
    printf("This program is to take input in form of a string using a loop \n");
    printf("Enter your loop now\n");
    while(ch != '\n'){
        scanf("%c",&ch);
        str[i]= ch;
        i++;
    }
   str[i]='\0';
   puts(str);
    
    return 0;
}