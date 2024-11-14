# include<stdio.h>

void namestring(char arr[]);

int main(){
    char firstname[]="Sanchit";
    char lastname[]="Victus";

    namestring(firstname);
    namestring(lastname);

    return 0;
}

void namestring(char arr[]){
    for(int i=0; arr[i]!=0;i++){
        printf("%c", arr[i]);
    }
    printf("\n");
}