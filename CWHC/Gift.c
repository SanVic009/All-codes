# include<stdio.h>
# include<string.h>

int main(){
    int scmarks, mtmarks;
    printf("Enter your science marks ");
    scanf("%d", &scmarks);
    printf("Enter your maths marks ");
    scanf("%d", &mtmarks);

    if ((scmarks>=33)&&(mtmarks>=33)){

        printf("You will get a gift worth 45 rupees");

    }else if((scmarks>=33)||(mtmarks>=33)){

        printf("You will get a gift worth 15 rupees");

    }else{printf("Sorry you did not pass. Try better next time.");}
    return 0;
}