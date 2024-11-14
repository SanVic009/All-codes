# include<stdio.h>

float temp( float C);

int main(){
    float C;
    printf("Please enter the temperature in degree celscius to convert it in to farhenite:");
    scanf("%f", &C);

    temp(C);
    return 0;
}

float temp(float C){
    float tempK = C*(9.0/5.0)+32.0;
    printf("%f", tempK);
}