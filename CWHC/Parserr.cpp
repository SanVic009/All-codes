#include <bits/stdc++.h>

using namespace std;

void parse(char *input){
    int flip, index =0;
    for (int i = 0; i < strlen(input); i++)
    {
        if( input[i]=='<'){
            flip =1;
            continue;
        }else if (input[i]=='>')
        {
            flip=0;
            continue;
        }
        if(flip==0){
            input[index]=input[i];
            index++;
        }
    }
    input[index]='\0';
    while (input[0]==' '){
        for (int i = 0; i < strlen(input); i++)
        {
            input[i]=input[i+1];
        }
    }
    while(input[strlen(input)]==' '){
        input[strlen(input)-1]='\0';
    }
}

int main(){
    char input[100];
    gets(input);
    cout<<input<<endl;
    parse(input);
    cout<<"the final string is '"<<input<<"'"<<endl;
    return 0;
}