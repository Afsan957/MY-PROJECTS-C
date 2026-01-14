#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int balance = 1000; 
    int bet, guess, secretNumber;
    srand(time(0));

    printf("Welcome to the C Casino! \n");
    printf("You have %d credits.\n", balance);

    while (balance > 0) {
        printf("\nEnter bet amount: ");
        scanf("%d", &bet);

       
        if (bet > balance) {
            printf("Insufficient balance! Your current balance is %d\n", balance);
            continue; 
        }

        if (bet <= 0) {
            printf("Please bet a positive amount!\n");
            continue;
        }

        secretNumber = (rand() % 10) + 1;

        printf("Guess a number between 1 and 10: ");
        scanf("%d", &guess);
        if (guess == secretNumber) {
            printf("Congratulations! You guessed right. \n");
            balance = balance + bet;
        } else {
            printf("Sorry, you lost. The number was %d. \n", secretNumber);
            balance = balance - bet;
        }

        printf("Your new balance is: %d\n", balance);

        if (balance == 0) {
            printf("\nGame Over! You've run out of credits. \n");
        }
    }

    return 0;
}