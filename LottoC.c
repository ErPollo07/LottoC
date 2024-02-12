#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

void ClrSrc() {
    system("@cls||clear");
}

int lenghtOfArrayOfString(char array[][100]) {
    int lunghezza = 0;

    // Continua a contare finché la stringa non è vuota
    while (array[lunghezza] != NULL && array[lunghezza][0] != '\0') {
        lunghezza++;
    }

    return lunghezza;
}

void printMenu(char menu[][100]) {
    printf("================\n");
    printf("%s", menu[0]);
    printf("\n================\n");

    int lenghtOfMenu = lenghtOfArrayOfString(menu);

    for (int i = 1; i < lenghtOfMenu; i++) {
        printf("%s\n", menu[i]);
    }
}


void PrintLottoWord() {
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

    printf("\n");

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

int randomValue(int minValue, int maxValue) {
    return rand() % (maxValue - minValue + 1) + minValue;
}

/// @brief Funzione per generare casualmente numeri nelle ruote del lotto senza ripetizioni
/// @param numbers 
void ExtractedWheel(int *numbers) {
    int minValue = 1, maxValue = 10;
    int wheelSize = 5;

    srand(time(NULL)); // Inizializza il seme del generatore casuale

    for (int i = 0; i < wheelSize; i++) {
        numbers[i] = randomValue(minValue, maxValue);

        // Controllo se il numero si ripete
        for (int k = 0; k < i; k++) {
            if (numbers[i] == numbers[k]) {
                i--; // Riavvia la generazione del numero
                break;
            }
        }
    }
}

/*
!   PLAYER FUNCTIONS
*/

/*
Take player numbers
param *playerNumbers pointer to the array of playerNumbers
*/
void TakePlayerNumbers(int *playerNumbers, int playerNumbersLenght) {
    int numbersChecker[90] = {};
    int correctInserction, continueToInsert = 1;
    int number;


    printf("Inserisci i numeri su cui si vuole scommettere.\nSe non vuoi inserire altri numeri inserire 0.");

    for (int i = 0; i < playerNumbersLenght && continueToInsert; i++) {
        do {
            correctInserction = 1;

            // Ask the player to insert a number
            printf("\nInserisci un numero (inserire 0 per smettere di inserire): ");
            scanf("%d", &number);

            /* ERROR MESSAGE */
            // Check if the number is different from 0
            if (number != 0) {
                // Check if the number is in the correct interval
                if (number < 0 || number > 90) {
                    printf("Devi inserire un numero tra 1 e 90");
                    correctInserction = 0;
                }
                // check if the number is already insert
                else if (numbersChecker[number - 1]) {
                    printf("Numero gia inserito.");
                    correctInserction = 0;
                }
                // if the number is in the right interval and isn't already insert
                else {
                    numbersChecker[number - 1] = 1; // set the variable of the number to 1 (true),
                    // so it means that is already insert
                    playerNumbers[i] = number; // put the number in the right place
                }
            }
            /* END ERROR MESSAGE */
            else
                continueToInsert = 0;
        } while(!correctInserction);
    }
}

void TakePlayerBetTypes(int *playerBetTypes, int lenght, int playedNumbers, char menuOptions[][100]) {
    int betChecker[5] = {};
    int userBet;
    int continueToInsert = 1, correctInserction;

    printMenu(menuOptions);

    for (int i = 0; i < lenght && continueToInsert; i++) {
        do {
            correctInserction = 1;

            printf("\nInserisci scelta (inserisci 0 per smettere di inserire): ");
            scanf("%d", &userBet);

            // Check if the number is different from 0
            if (userBet != 0) {
                // check if the number it's available in the list of bet
                // if it's not available, tell him that isn't a correct number
                if (userBet < 0 || userBet > 5) {
                    printf("Devi inserire un numero tra 1 e 5");
                    correctInserction = 0;
                }
                // if the player inserts a bet which is already insert
                // tell him that the number is already insert
                else if (betChecker[userBet - 1]) {
                    printf("Numero gia inserito.");
                    correctInserction = 0;
                }
                // if the player inserts a number, which is bigger than the numbers of numbers that he plays,
                // Tell him that the number he can't afford the bet type
                else if (userBet > playedNumbers) {
                    printf(
                            "La quantita' dei numeri che hai inserito e' troppo piccola per porter scegliere questa opzione."
                    );
                    correctInserction = 0;
                }
                // if the number is in the correct interval, isn't already insert and is minor then the count of played numbers
                else {
                    betChecker[userBet - 1] = 1; // set the variable of the number to true,
                    // so it means that is already insert
                    playerBetTypes[userBet - 1] = userBet; // put the number in the right place
                }
            }
            /* END ERROR MESSAGE */
            else
                continueToInsert = 0;
        } while (!correctInserction);
    }
}

int RetrivePlayedNumbers(int *playerNumbers, int lenght) {
    int playedNumbers = 0;
    
    for (int i = 0; i < lenght && playerNumbers[i] != 0; i++) {
        playedNumbers++;
    }

    return playedNumbers;
}

/*
!   WINNING FUNCTIONS
*/

int factorial(int input) {
    if (input <= 1) {
        return 1;
    }

    int result = 1;

    for (int inputMultiplier = 2; inputMultiplier <= input; inputMultiplier++) {
        result *= inputMultiplier;
    }

    return result;
}

int retriveWinAmount(int betType, int userWins) {
    return factorial(userWins) / (factorial(betType) * factorial(userWins - betType));
}

double winningPrize(double amount, int numberOfWheels, int counterOfPlayedNumbers, int betType) {
    double winning;

    // 2d array for prizes if the player inserts 1 euro
    // The raw represent the played numbers of the player
    // The column represents the bet types
    double prizes[10][5] = {
            {11.23},
            {5.62, 250.00},
            {3.74, 83.33, 4500.00},
            {2.81, 41.67, 1125.00, 120000.00},
            {2.25, 25.00, 450.00,  24000.00, 6000000.00},
            {1.87, 16.67, 225.00,  8000.00,  1000000.00},
            {1.60, 11.90, 128.57,  3428.57,  285714.29},
            {1.40, 8.93,  80.36,   1714.29,  107142.86},
            {1.25, 6.94,  53.57,   952.38,   47619.05},
            {1.12, 5.56,  37.50,   571.43,   23809.52}
    };

    // Calculate the winning
    winning = prizes[counterOfPlayedNumbers - 1][betType - 1] * amount / numberOfWheels;

    return winning;
}

/// @brief This function calculate how many numbers the player guess on a wheel
/// @param playerNumbers array of the player numbers
/// @param lenghtPlayerNumbers the lenght of the array of player numbers
/// @param wheelNumbers array of the wheel numbers
/// @param lenghtWheelNumbers the lenght of the array of wheel numbers
/// @return how many numbers the player guess on a wheel
int returnBetFromWheel(int playerNumbers[], int lenghtPlayerNumbers, int wheelNumbers[], int lenghtWheelNumbers) {
    int betTypeOfWheel = 0;
    
    // For every number in playerNumbers check if in the array of the wheel there is another number that is equal to it.
    // If there is then update the bet counter
    for (int i = 0; i < lenghtPlayerNumbers; i++) {
        for (int j = 0; j < lenghtWheelNumbers; j++) {
            if (playerNumbers[i] == wheelNumbers[j])
                betTypeOfWheel++; // update the bet counter
        }
    }

    return betTypeOfWheel;
}

double calculationWinningPrice(int playerNumbers[], int lenghtPlayerNumbers, int wheel[], int lenghtWheelNumbers, int playerBetTypes[],
                                double amount, int numberOfWheels, int counterOfPlayedNumbers) {
    int betFromWheel = returnBetFromWheel(playerNumbers, lenghtPlayerNumbers, wheel, lenghtWheelNumbers);
    int howManyBet;
    double price = 0;

    // if I don't guess anything return 0 (the initial value of the variable price)
    if (betFromWheel == 0)
        return price;

    for (int i = betFromWheel; i >= 1; i--) {
        // Example to explain this if:
        // I have guessed 4 numbers, but I have bet on ambo.
        // So because guessed 4 numbers, I have done 6 ambo.
        // This for return the winning of the 6 ambo.
        if (playerBetTypes[i - 1] != 0) {
            howManyBet = retriveWinAmount(i, betFromWheel);
            price += winningPrize(amount, numberOfWheels, counterOfPlayedNumbers, i) * howManyBet;
        }
    }

    return price;
}



void PrintWheel(int *array, int lenght) {
    for (int i = 0; i < lenght; i++) {
        printf("%d ", array[i]);
    }
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

    int playerNumbers[10] = {}; // Number of the player
    int playerBetTypes[5] = {}; // The bets of the player (singolo, ambo, terna, quaterna, cinquina)
    int wheels[10][5]; // The 2d array for store all the wheels
    int numberOfWheels; // How many wheels the player chooses to player on
    int whatWheel = 0; // number of the wheel that the player wants to play on
    int counterOfPlayedNumbers = 0; // The number of the numbers the player played
    double amount; // How much money the player has bet
    double price = 0; // How much money the player wins

    int continueToPlay;
    char _pause;

    ClrSrc();
    PrintLottoWord();

    printMenu(introductionMenu);

    printf("\nPremi invio per iniziare a giocare");
    scanf("%c", &_pause);

    ClrSrc();
    PrintLottoWord();

    printf("Step 1\n\tInserire l'importo\n\n");
    // Ask the player to insert the amount of money he wants to bet
    amount = takeAmount();

    ClrSrc();
    PrintLottoWord();

    printf("Step 2\n\tScegliere su quante ruote giocare\n");
    // Ask the player how many wheels he what to bet on
    numberOfWheels = takeNumberOfWheels(numberOfWheelMenu);

    // if the player wants to play on one wheel
    //   1. then I make him choose which wheel
    //   2. generate the wheel numbers
    if (numberOfWheels <= 1) {
        ClrSrc();
        PrintLottoWord();
        printf("Step 2.1\n\tScegliere su quale ruota giocare\n\n");
        whatWheel = takeSpecificWheel(specificWheelsMenu);

        ExtractedWheel(wheels[whatWheel - 1]);
    }
    // else
    //   generate the wheel numbers for all the wheels
    else {
        for (int i = 0; i < numberOfWheels; i++)
            ExtractedWheel(wheels[i]);
    }

    ClrSrc();
    PrintLottoWord();
    printf("Step 3\n\tInserire i propri numeri\n\n");

    TakePlayerNumbers(playerNumbers, sizeof(playerNumbers) / sizeof(playerNumbers[0]));

    counterOfPlayedNumbers = RetrivePlayedNumbers(playerNumbers, sizeof(playerNumbers) / sizeof(playerNumbers[0]));

    ClrSrc();
    PrintLottoWord();
    printf("Step 4\n\tInserire su cosa si vuole scommettere\n\n");

    TakePlayerBetTypes(playerBetTypes, sizeof(playerBetTypes) / sizeof(playerBetTypes[0]), counterOfPlayedNumbers, betTypeMenu);

    // Calcualate the lenght of wheel[whatWheel] arrays
    // I can reuse this becouse the lenght is the same for all the wheels
    int _lenghtWheelNums = sizeof(wheels[0]) / sizeof(wheels[0][0]); 

    /* CALCULATION OF THE WINNIG PRIZE */
    // if the player chooses to play on all the wheels, whatWheel will be 0 so calculate the winning prize for all the wheel    
    if (whatWheel == 0) {
        printf("Ecco le ruote: \n");
        for (int i = 0; i < numberOfWheels; i++) {
            PrintWheel(wheels[i], sizeof(wheels[i]) / sizeof(wheels[i][0]));
            printf("\n");
            price += calculationWinningPrice(playerNumbers, counterOfPlayedNumbers, wheels[i], _lenghtWheelNums, playerBetTypes, amount, numberOfWheels, counterOfPlayedNumbers);
        }
    }
    // if the player chooses to play on a specific wheel, the whatWheel number will be a number so calculate the prize for that specific wheel
    else {
        
        
        // Print the wheel which the player choose
        printf("\n\nEcco la ruota che hai scelto: ");
        PrintWheel(wheels[whatWheel - 1], sizeof(wheels[whatWheel - 1]) / sizeof(wheels[whatWheel - 1][0]));

        // Calculate the price
        price += calculationWinningPrice(playerNumbers, counterOfPlayedNumbers, wheels[whatWheel - 1], _lenghtWheelNums, playerBetTypes, amount, numberOfWheels, counterOfPlayedNumbers);
    }
    /* END CALCULATION OF THE WINNIG PRIZE */

    printf("\n\nEcco i tuoi numeri: ");
    PrintWheel(playerNumbers, sizeof(playerNumbers) / sizeof(playerNumbers[0]));

    printf("\n\nHai vinto: %.2f euro\n", price);

    printf("\n\n");
}