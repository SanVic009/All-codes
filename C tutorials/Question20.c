# include<stdio.h>

int main(){
    int table[10][2];
    for(int i=0;i<10; i++){
        for(int j=0;j<2;j++){
            table[i][j]=(i+1)*(j+2);
        }
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 2; j++)
        {
           if(j==0){
            printf("%d \t", table[i][j]);
           }else{
            printf("%d \n", table[i][j]);
            }
        }
        
    }
    

    
    return 0;
}