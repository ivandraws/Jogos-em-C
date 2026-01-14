#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int result(char *comp, char *player);

int main(void)
{
    srand(time(NULL));
    char *jogadas[] = {"Pedra", "Papel", "Tesoura"};
    char *player = malloc(sizeof(float) * 4);
    int compChoice;

    printf("%s\n", jogadas[0]);
    printf("%s\n", jogadas[1]);
    printf("%s\n", jogadas[2]);
   do
    {
        compChoice = rand() % 3;
        printf("Player, escolha sua jogada: ");
        scanf("%s", player);
    } while (result(jogadas[compChoice], player) == 0);

    if (result(jogadas[compChoice], player) == 1)
        printf("Player veceu!\n");
    if (result(jogadas[compChoice], player) == 2)
        printf("Comp venceu!");

    if (result(jogadas[compChoice], player) == -1)
        printf("Soething went wrong\n");
    free(player);
    return 0;
}

int result(char *comp, char *player)
{
    if (strcmp(comp, player) == 0)
    {
        printf("Its a TIE!\n");
        return 0;
    }
    else
    {
        if ((strcmp(player, "Pedra") == 0 && strcmp(comp, "Tesoura") == 0) || (strcmp(player, "Papel") == 0 && strcmp(comp, "Pedra") == 0) || (strcmp(player, "Tesoura") == 0 && strcmp(comp, "Papel") == 0))
        {
            return 1;
        }
        
        if ((strcmp(comp, "Pedra") == 0 && strcmp(player, "Tesoura") == 0)  || ((strcmp(comp, "Papel") == 0) && strcmp(player, "Pedra") == 0) || (strcmp(comp, "Tesoura") == 0 && strcmp(player, "Papel") == 0))
        {
            return 2;
        }
    }
    
    return -1;
}