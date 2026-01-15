#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int result(char *comp, char *player);

int main(void)
{
    srand(time(NULL));
    char *jogadas[] = {"Pedra", "Papel", "Tesoura"};
    int compChoice;
    int count[3] = {0, 0, 0}; // Counter for Pedra, Papel, Tesoura
    int iterations = 100;

    printf("Executando %d iteracoes para obter estatisticas das escolhas do computador...\n\n", iterations);

    // Run 100 times and collect statistics
    for (int i = 0; i < iterations; i++)
    {
        compChoice = rand() % 3;
        count[compChoice]++;
    }

    // Display results
    printf("Resultados apos %d iteracoes:\n", iterations);
    printf("======================================\n");
    for (int i = 0; i < 3; i++)
    {
        double percentage = (count[i] * 100.0) / iterations;
        printf("%s: %d vezes (%.2f%%)\n", jogadas[i], count[i], percentage);
    }
    printf("======================================\n");
    
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