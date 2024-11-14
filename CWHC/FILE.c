#include <stdio.h>
#include <string.h>

/*
there are 3 basic modes of opening files. they are 
r for reding file
w for writnig file
a for appending in a file

there are extension of r and w
r+ for reading and writing but cannot create a new file
w+ for both reading and writing.

there are many more modes but these are the most basic and the most used ones

*/
int main(){
    FILE *ptr=NULL;

    char str[34]="This is a text message";

    // ~~~~~~ For reading a file ~~~~~~
    // ptr= fopen("Sample.txt", "r");
    // fscanf(ptr, "%s", str);

    // printf("%s\n", str);

    ptr=fopen("Sample.txt", "a");
    fprintf(ptr,"%s", str);
    fclose(ptr);
    return 0;
}