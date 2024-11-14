# include<stdio.h>
# include<string.h>

int main(){
    char str1[]="'Og string'";
    char str2[]="'new string'";
    // it compares 1 letter first , if they are same then moves on to the next letter using ASCII values

    int x=strcmp(str1, str2);
    printf("%d", x);
    //here n=110, o=111. which implies o-n=-1

    return 0;
}