# include<stdio.h>
# include<string.h>

int main(){
    char str1[100]="Og string";
    char str2[]=" new string";
    strcat(str1,str2);
    puts(str1);
    return 0;
}
//here cat in strcat means catenation meaning adding the value of b to a and making it a + b and not replacing a with b.