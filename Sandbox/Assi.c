#include <stdio.h>

int count_rock = 0;
int count_paper = 0;
int count_sci = 0;

int prediction()
{
    if (count_rock > count_paper && count_rock > count_sci)
        return 1;
    else if (count_paper > count_rock && count_paper > count_sci)
        return 2;
    else
        return 0;
}

void update_count(int user_input)
{
    if (user_input == 0)
        count_rock++;
    else if (user_input == 1)
        count_paper++;
    else
        count_sci++;
}

int player_score = 0;
int computer_score = 0;

void update_score(int user_input)
{
    int pred = prediction();
    if (user_input == 0)
    {
        if (pred == 0)
        {
            printf("You played ROCK, Computer played ROCK.\n");
            printf("\nComputer Score: %d\nPlayer Score: %d\n", computer_score, player_score);
        }
        else if (pred == 1)
        {
            printf("You played ROCK, Computer played PAPER.\n");
            computer_score++;
            printf("\nComputer Score: %d\nPlayer Score: %d\n", computer_score, player_score);
        }
        else
        {
            printf("You played ROCK, Computer played SCISSORS.\n");
            player_score++;
            printf("\nComputer Score: %d\nPlayer Score: %d\n", computer_score, player_score);
        }
    }
    else if (user_input == 1)
    {
        if (pred == 0)
        {
            printf("You played PAPER, Computer played ROCK.\n");
            player_score++;
            printf("\nComputer Score: %d\nPlayer Score: %d\n", computer_score, player_score);
        }
        else if (pred == 1)
        {
            printf("You played PAPER, Computer played PAPER.\n");
            printf("\nComputer Score: %d\nPlayer Score: %d\n", computer_score, player_score);
        }
        else
        {
            printf("You played PAPER, Computer played SCISSORS.\n");
            computer_score++;
            printf("\nComputer Score: %d\nPlayer Score: %d\n", computer_score, player_score);
        }
    }
    else
    {
        if (pred == 0)
        {
            printf("You played SCISSORS, Computer played ROCK.\n");
            computer_score++;
            printf("\nComputer Score: %d\nPlayer Score: %d\n", computer_score, player_score);
        }
        else if (pred == 1)
        {
            printf("You played SCISSORS, Computer played PAPER.\n");
            player_score++;
            printf("\nComputer Score: %d\nPlayer Score: %d\n", computer_score, player_score);
        }
        else
        {
            printf("You played SCISSORS, Computer played SCISSORS.\n");
            printf("\nComputer Score: %d\nPlayer Score: %d\n", computer_score, player_score);
        }
    }
}

void choice(int userInput){
    switch (userInput)
    {
    case 0:
        printf("ROCK");
        break;
    
    case 1:
        printf("PAPER");
        break;
    
    case 2:
        printf("SCISSOR");
        break;
    
    default:
        break;
    }
}

void end_game(int computer_score, int player_score)
{
    if (computer_score == 10)
    {
        printf("\nComputer Won!!\n");
    }
    else if (player_score == 10)
    {
        printf("\nYou Won!!\n");
    }
}

int main()
{
    int user_input;
    char user_name[50];

    printf("Enter Your Name: ");
    scanf("%s", user_name);

    while (1)
    {
        printf("Enter 0 for ROCK\nEnter 1 for PAPER\nEnter 2 for SCISSORS.\n");
        scanf("%d", &user_input);

        if (user_input < 0 || user_input > 2)
        {
            printf("\n%s this is Invalid Input!!\n", user_name);
            printf("\nComputer Score: %d\nPlayer Score: %d\n", computer_score, player_score);
            continue;
        }

        update_score(user_input);
        update_count(user_input);
        end_game(computer_score, player_score);

        if (computer_score == 10 || player_score == 10)
        {
            break;
        }
    }
    return 0;
}