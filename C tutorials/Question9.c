# include<stdio.h>

void table(int a); // why void, why not int?//
int main(){
    int a, pr;
    printf("Please enter the number of the desired table :");
    scanf("%d",&a);

    table(a);
    return 0;
}
//ye function value import kaise kar raha hai??

//hi this is future sanchit, ye function vahi value import karta hai jo usko calling ke wakt bracket me dete hai
void table(int a){
    for (int i = 1; i <= 10; i++) //yaha return kyu nahi likha?? 
    {
        printf("%d \n", a*i);
    }
    
}
