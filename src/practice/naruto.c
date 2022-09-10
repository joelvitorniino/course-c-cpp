#include <stdio.h>
#include <string.h>

int main()
{
    printf("******************************\n");
    printf("Hello. Welcome to naruto quiz!\n");
    printf("******************************\n");

    char wordCorrect[7] = "Sasuke";

    char shot[100];
    int attempts = 1;

    while(1) 
    {
        printf("Attempts %d\n", attempts++);
        printf("What is your attempt?\n");

        scanf("%s", &shot);
        printf("Your shot is %s\n", shot);

        if(strcmp(shot, wordCorrect) == 0) 
        {
            printf("Great! That it's sasuke!");
            break;
        }
    }
}