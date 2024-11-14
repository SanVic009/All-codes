# include<stdio.h>

int main(){
    // if we use pointer notation, then we will be able to reinitialize the value of the string
    // but if we use the array notation, we wont be able to reinitialise it.
    char *str="Test string";
    puts(str);
    str="Hello world";
    puts(str);
    char str2[]="this cannot change";//I cannot change str 2 after this.
    puts(str2);
    // str2="hello world";

    return 0;
}