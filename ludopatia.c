#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>


int printDice(int roll) {
  switch (roll){

    case 1:
    printf("\n _____________");
    printf("\n|             |");
    printf("\n|             |");
    printf("\n|      \033[1;31m.\033[0m      |");
    printf("\n|             |");
    printf("\n|             |");
    printf("\n|_____________|");
    break;

    case 2:
    printf("\n _____________");
    printf("\n|  \033[1;31m        .\033[0m  |");
    printf("\n|             |");
    printf("\n|             |");
    printf("\n|             |");
    printf("\n|  \033[1;31m.       \033[0m   |");
    printf("\n|_____________|");
    break;
    
    case 3:
    printf("\n _____________");
    printf("\n|  \033[1;31m        .\033[0m  |");
    printf("\n|             |");
    printf("\n|      \033[1;31m.\033[0m      |");
    printf("\n|             |");
    printf("\n|  \033[1;31m.       \033[0m   |");
    printf("\n|_____________|");
    break;

    case 4:
    printf("\n _____________");
    printf("\n|  \033[1;31m.       .\033[0m  |");
    printf("\n|             |");
    printf("\n|             |");
    printf("\n|             |");
    printf("\n|  \033[1;31m.       .\033[0m  |");
    printf("\n|_____________|");
    break;

    case 5:
    printf("\n _____________");
    printf("\n|  \033[1;31m.       .\033[0m  |");
    printf("\n|             |");
    printf("\n|      \033[1;31m.\033[0m      |");
    printf("\n|             |");
    printf("\n|  \033[1;31m.       .\033[0m  |");
    printf("\n|_____________|");
    break;

    case 6:
    printf("\n _____________");
    printf("\n|             |");
    printf("\n|  \033[1;31m.   .   .\033[0m  |");
    printf("\n|             |");
    printf("\n|             |");
    printf("\n|  \033[1;31m.   .   .\033[0m  |");
    printf("\n|_____________|");
    break;
  }
}
int main() {
  char input; 
  srand(time(NULL)); // Number seed 
  int myNumber = (rand() % 6 + 1); // Random number to guess
  int tries = 0; // Tries

  // Start menu
  printf("\nWelcome to the LUDOPATIA GENERATOR!");
  printf("\n----------------------------------------------------------------");
  printf("\nRoll the dice, guess my number & win a PALMADITA IN THE ESPALDA!");
  printf("\n\nMy number: %d",myNumber);
 
  // Guessing loop
  while (1) {
    tries++; 

    printf("\n\nENTER to roll | Q to quit ");
    input = getchar();

    //'Q'
    if (input == 'q' || input == 'Q') {
      break;
    }

    // 'ENTER'
    // Roll
    system("cls");
    printf("Rolling");
    for(int i = 0; i < 3; i++){
      printf(".");
      fflush(stdout);
      usleep(500000);
    }
    int roll = (rand() % 6 + 1); // Random number 1-6


    // Prints dices
    system("cls");   
    printDice(roll);

    // Number
    printf("\n\nYour guess: %d",roll);
    printf("\nMy number: %d",myNumber);

    // Number of tries
    printf("\n\nNumber of tries: %d", tries);

    // Guessed
    if (roll == myNumber){
      usleep(500000);
      printf("\n\nOMG \033[032mYOU WIN\033[0m, *PALMADITA IN THE ESPALDA*");
      sleep(3.5);
      break;
    }

    // Not guessed
    else{
       usleep(500000);
       printf("\n\nMu mal, \033[31mYOU FAILED\033[0m, gamble more >:C");
    }
  }
  
  return 0;
}