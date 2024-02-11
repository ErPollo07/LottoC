#include <stdio.h>
#include <string.h>
#include <unistd.h>

void ClrSrc() {
    system("@cls||clear");
}


void printMenu(char menu[][100]) {
    printf("================\n");
    printf(menu[0]);
    printf("\n================\n");

    int lenghtOfMenu = lenghtOfArrayOfString(menu);

    for (int i = 1; i < lenghtOfMenu; i++) {
        printf("%s\n", menu[i]);
    }
}

int lenghtOfArrayOfString(char array[][100]) {
    int lunghezza = 0;

    // Continua a contare finché la stringa non è vuota
    while (array[lunghezza] != NULL && array[lunghezza][0] != '\0') {
        lunghezza++;
    }

    return lunghezza;
}

void printLottoWord() {
    printf("          ..:---::.         .:----:..         .:----:.         ..:----:.         .::---:..\n"
           "        :-=+++++++=-:.   .:=++++++++=-.    .-=++++++++=-.    :-=++++++++=:.   .:==+++++++=-:\n"
           "      .=++-:.   .:-=+=:.:=+=-..   .:=++-..-++=:..  ..:=+=-..=++=:.   .:-=+=: :=+=-:.   .:-++=.\n"
           "     :++-. =*=     .-++=++-. :-::--. .=+==+=:.-++++++-.:=+=++=..=++++++:.-++=++-.         .=++:\n"
           "    .=+-.  +**       -+++: .===+==+*=..=++=.  -++**++-  .+++=. .=+***++:  -+++:   .-=+=:.  .=+=.\n"
           "    :++.   +**       .++= .+=++=-+*-*+ :++=     -**-     =++:     =**.    .+++.   +*****=   :++:\n"
           "    -++.   +**        ++= .*-*=..-++== :++=     -**-     =++:     =**.     =++    ******=   .++-\n"
           "    :++-   +**:::.   :+++..+*==+-=*-+. -++=.    -**-    .=++-     =**.    :+++:   -****+:   -++:\n"
           "     =++:  +******  :=+++=..-++++===. -++++=.   :**:   .=++++:    =**.   .=+++=.           :++-\n"
           "     .-++-..:::::..-++=:=+=-..::.. .:=++-:=+=:. .--. .:=+=:-++-:. .-: ..-=+=:=+=-..     .:-++-.\n"
           "       :=+++=====+++=:. .:=++======+++-.  .-+++======++=-.  :=+++======++=:. .:=++======+++=:\n"
           "         .:--====-:..     .:--====--:.      .:--====--:.      .:--====--..     .:--====--:.\n");

           printf("\n\n");
}

double takeAmount() {
    double amount;

    

    do {
        printf("\nInserisci importo: ");
        scanf("%lf", &amount);

        // if the player inserts a number out of range, tell him that is a not vvalid number
        if (amount < 0 || amount > 200)
            printf("L'importo deve essere compreso tra 0 e 200.\n");
    } while(amount < 0 || amount > 200);

    return amount;
}

/*
!    WHEEL METHODS
*/

int takeNumberOfWheels(char menuOption[][100]) {
    int choice;
    int numberOfWheels;
    int correctInserction;

    printMenu(menuOption);

    do {
        correctInserction = 1;

        printf("\nInserisci la tua scelta: ");
        scanf("%d", &choice);

        // If the user types a wrong choice, tell him that it's wrong
        if (choice != 1 && choice != 2) {
            printf("Puoi scegliere solo 1 o 2\n");
            correctInserction = 0;
        }
    } while (!correctInserction);

    // if the choice is 2
    if (choice == 2)
        numberOfWheels = 10; // set the number of wheels to ten
    // if the player wnats to bet on 1 wheel, the choice is 1, so set the nummberOfWheel equal to choice
    else
        numberOfWheels = choice;

    return numberOfWheels;
}

int takeSpecificWheel(char menuOption[][100]) {
    int specificWheel;
    int correctInserction;

    printMenu(menuOption);

    do {
        correctInserction = 1;

        printf("\nInserisci la tua scelta: ");
        scanf("%d", &specificWheel);

        // If the user types a wrong choice, tell him that it's wrong
        if (specificWheel < 1 || specificWheel > 10) {
            printf("Devi scegire 1 ruota o 10\n");
            correctInserction = 0;
        }
    } while (!correctInserction);

    return specificWheel;
}

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

    ClrSrc();
    printLottoWord();

    printMenu(introductionMenu);

    printf("\nPremi invio per iniziare a giocare");
    scanf("%c", &_pause);

    ClrSrc();
    printLottoWord();

    printf("Step 1\n\tInserire l'importo\n\n");
    // Ask the player to insert the amount of money he wants to bet
    amount = takeAmount();

    ClrSrc();
    printLottoWord();

    printf("Step 2\n\tScegliere su quante ruote giocare\n\n");
    // Ask the player how many wheels he what to bet on
    numberOfWheels = takeNumberOfWheels(numberOfWheelMenu);

    // if the player wants to play on one wheel
    //   1. then I make him choose which wheel
    //   2. generate the wheel numbers
    if (numberOfWheels <= 1) {
        ClrSrc();
        printLottoWord();
        printf("Step 2.1\n\tScegliere su quale ruota giocare\n\n");
        whatWheel = takeSpecificWheel(specificWheelsMenu);

        wheels[whatWheel] = extractedWheel();
    }
    else {
        for (int i = 0; i < numberOfWheels; i++)
            wheels[i] = extractedWheel();
    }

    printf("\n\n");
}