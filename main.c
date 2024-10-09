#include <stdio.h>


int main() {
    char priklad[1000];
    int vysledek = 0;
    int cislo = 0;
    char operace = '+';

    printf("Zdravim, vypocitam ti jakykoliv priklad, ale jsou dve podminky. \n 1) Priklad musi obsahovat pouze + a - \n 2) Priklad musi mit maximalne 1000 znaku (neuveritelne tezke dodrzet) \n Zde napis svuj priklad: ");
    scanf("%s", priklad);

    for (int i = 0; priklad[i] != '\0'; i++) {
        if (priklad[i] >= '0' && priklad[i] <= '9') {
            cislo = 0;
            while (priklad[i] >= '0' && priklad[i] <= '9') {
                cislo = cislo * 10 + (priklad[i] - '0');
                i++;
            }
            if (operace == '+') {
                vysledek += cislo;
            } else if (operace == '-') {
                vysledek -= cislo;
            } else {
                vysledek = cislo;
            }
            i--;
        } else if (priklad[i] == '+' || priklad[i] == '-') {
            operace = priklad[i];
        } else if (priklad[i] != ' ') {
            printf("Neplatny znak: %c\n", priklad[i]);
            return 1;
        }
    }

    printf("Vysledek je: %d\n", vysledek);
    return 0;
}
