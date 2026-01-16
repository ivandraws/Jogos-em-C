#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int diceTypes[] = {4, 6, 8, 10, 12, 16, 20, 100};
    int qntd = sizeof(diceTypes) / sizeof(diceTypes[0]);
    int try, t = 0, roll, i;

    printf("Which dice do you wanna roll ?\n");
    scanf("%i", &try);

    for (i = 0; i < qntd; i++)
    {
        if (try == diceTypes[i])
        {
            t = try;
            break;
        }
    }

    if (t == 0)
    {
        printf("Wrong dice!\n");
    }
    else
    {
        roll = rand() % t + 1;
        printf("%i sides dice result: %i\n", diceTypes[i], roll);
    }
    return 0;
}
