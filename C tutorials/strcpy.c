# include<stdio.h>
# include<string.h>

int main(){
    char str1[]="'Og string'";
    char str2[]="'new string'";

    printf("before swapping, the values of str1 and str2 are :%s and %s resp \n", str1, str2);

    strcpy(str1,str2);

    printf("after swapping, the values of str1 and str2 are :%s and %s resp", str1, str2);

    return 0;
}