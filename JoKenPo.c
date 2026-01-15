#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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