# include<stdio.h>
# include<string.h>

int main(){
    char str[] = {'c','h','a','r','\0'};
    char str2[]= "string";
    for (int i = 0; str[i] != '\0'; i++)
    {
        printf("%c", str[i]);
    }
    for (int i = 0; str2[i] != '\0'; i++)
    {
        printf("%c", str2[i]);
    }
    
    return 0;
}