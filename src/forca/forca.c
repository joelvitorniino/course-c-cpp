#include <stdio.h>
#include <string.h>

int main()
{
   char palavrasecreta[20];

   sprintf(palavrasecreta, "MELANCIA");
   
   int acertou = 0;
   int enforcou = 0;

   do {
      char chute;
      scanf("%c", &chute);

      for(int i = 0; i < strlen(palavrasecreta); i++) {
         if(palavrasecreta[i] == chute) {
            printf("A posição %d tem essa letra!\n", i);
         }
      }

   } while(!acertou && !enforcou);
}