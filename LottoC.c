#include <stdio.h>
#include <string.h>

void main()
{
    char introductionMenu[][100] = {
        "Step del gioco",
        "1) Inserimento dell'importo",
        "2) Scegliere su quante ruote giocare",
        "2.1) Se si sceglie di giocare su una ruota, scegliere quale",
        "3) Inserire i propri numeri",
        "4) Inserire su cosa si vuole scommettere"
    };

    char numberOfWheelMenu[][100] = {
        "Su quante ruote vuoi puntare?",
        "[1] - Scelta libera di una ruota",
        "[2] - Tutte e 10 le ruote"
    };

    char specificWheelsMenu[][100] = {
        "Su quale ruota vuoi puntare?",
        "[1] - BARI",
        "[2] - CAGLIARI",
        "[3] - FIRENZE",
        "[4] - GENOVA",
        "[5] - MILANO",
        "[6] - NAPOLI",
        "[7] - PALERMO",
        "[8] - ROMA",
        "[9] - TORINO",
        "[10] - VENEZIA"
    };

    char betTypeMenu[][100] = {
        "Quale puntate vuoi scegliere?",
        "[1] - SINGOLO",
        "[2] - AMBO",
        "[3] - TERNA",
        "[4] - QUATERNA",
        "[5] - CINQUINA"
    };

    char continueToPlayMenu[][100] = {
        "Voui continuare a giocare",
        "[1] - Si",
        "[2] - No"
    };

    int playerNumbers[10]; // Number of the player
    int playerBetTypes[5]; // The bets of the player (singolo, ambo, terna, quaterna, cinquina)
    int wheels[10][5]; // The 2d array for store all the wheels
    int numberOfWheels; // How many wheels the player chooses to player on
    int whatWheel = 0; // number of the wheel that the player wants to play on
    int counterOfPlayedNumbers = 0; // The number of the numbers the player played
    double amount; // How much money the player has bet
    double price = 0; // How much money the player wins

    int continueToPlay;
    char _pause;

    printf("\n\n");
}

void printMenu(char menu[][100]) {
    int lenght = sizeof(menu) / sizeof(menu[0]);

    for (int i = 0; i < lenght; i++) {
        printf("%s\n", menu[i]);
    }
}