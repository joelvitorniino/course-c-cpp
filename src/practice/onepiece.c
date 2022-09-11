#include <stdio.h>
#include <string.h>

int main()
{   
    printf("*****************\n");
    printf("Welcome to One Piece quiz!\n");
    printf("*****************\n");

    char wordCorrect[6] = "Luffy";
    char shot[100];

    while(1)
    {
        printf("What is your attempt?\n");
        scanf("%s", &shot);

        if(strcmp(shot, wordCorrect) == 0) 
        {
            printf("Great! That it's a Luffy!\n");
            break;
        }

        else
        {
            printf("Continue bro!\n");
            continue;
        }
    }
}