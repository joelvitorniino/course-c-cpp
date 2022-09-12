#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMERO_DE_TENTATIVAS 5
#define MAX_LEN 128

int main(void)
{   
    char *filename = "./ascii/castelo.txt";
    FILE *fptr = NULL;

    if((fptr = fopen(filename,"r")) == NULL)
    {
        fprintf(stderr,"error opening %s\n",filename);
        return 1;
    }

    printf("\n\n");
    print_image(fptr);
    printf("\n\n");

    fclose(fptr);

    int segundos = time(0);
    srand(segundos);

    int numerogrande = rand();

    int numerosecreto = numerogrande % 100;
    int chute;
    int tentativas = 1;
    double pontos = 1000;

    int acertou = 0;

    int nivel;
    printf("Qual o nível de dificuldade?\n");
    printf("(1) Fácil (2) Médio (3) Difícil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    int numerodetentativas;

    switch(nivel) {
        case 1:
            numerodetentativas = 20;
            break;
            
        case 2:
            numerodetentativas = 15;
            break;

        default:
            numerodetentativas = 6;
            break;
    }

    for(int i = 1; i <= numerodetentativas; i++){
        printf("Tentativa %d\n", tentativas);
        printf("Qual é o seu chute? ");

        scanf("%d", &chute);
        printf("Seu chute foi %d\n", chute);

        if (chute < 0) {
            printf("Você não pode chutar números negativos!\n");
            continue;
        }

        acertou = (chute == numerosecreto);
        int maior = (chute > numerosecreto);

        if(acertou) {
            break;
        }

        else if (maior) {
            printf("Seu chute foi maior que o número secreto\n");
        }
        
        else {
            printf("Seu chute foi menor que o número secreto\n");
        }

        tentativas++;

        double pontosperdidos = abs(chute - numerosecreto) / 2.0;

        pontos = pontos - pontosperdidos;
    }

    printf("Fim de jogo!\n");

    if(acertou) {
        filename = "./ascii/sorriso.txt";

        if((fptr = fopen(filename,"r")) == NULL)
        {
            fprintf(stderr,"error opening %s\n",filename);
            return 1;
        }

        print_image(fptr);
        printf("\n\n");
        printf("\n\n");

        printf("Você ganhou!\n");
        printf("Você acertou em %d tentativas\n", tentativas);
        printf("Total de pontos: %.1f\n", pontos);
    } else {
        printf("Você perdeu! Tente de novo!\n");
        printf("\n\n");

        filename = "./ascii/careta.txt";

        if((fptr = fopen(filename,"r")) == NULL)
        {
            fprintf(stderr,"error opening %s\n",filename);
            return 1;
        }


        print_image(fptr);
        printf("\n\n");
    };

}

void print_image(FILE *fptr)
{
    char read_string[MAX_LEN];
 
    while(fgets(read_string,sizeof(read_string),fptr) != NULL)
        printf("%s",read_string);
}