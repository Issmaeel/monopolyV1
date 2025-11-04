// This code is a simple simulation of player assortment and card shuffling in a Monopoly game.
// It allows users to input the number of players and their names, and then shuffle and display
// chance and community cards.


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random_in_range(int min, int max) {
    // printf("Your card is \n");
    return rand() % (max - min + 1) + min;
}

int player_Assortment() {

    // Player count sequence, unsolved!!
    int players;
    int playersNames[] = { 1, 2, 3, 4, 5, 6 };
    int size = sizeof(playersNames) / sizeof(playersNames[0]);

    for (int i = 0; i < size; i++) {
        printf("%d, ", playersNames[i]);
    }

    srand((unsigned int)time(NULL));

    // Starting Sequence
    int start;
    printf("\nWould you like to start? Press '1' to start - ");
    scanf_s("%d", &start);
    // printf("%d\n", start);

    // If the game does not start
    if (start != 1) {
        printf("The game has ended, thank you for playing!");
        // exit(0); // Exit does not work!!!!
    }

    printf("Alright, let's start! \n");
    printf("How many players are playing? (2 - 6 players) - ");
    scanf_s("%d", &players);
    printf("%d\n", players);

    if (players >= 2 && players <= 6) {
        printf("What would you like to name you players? Give them a NUMBER please. Thank you! \n");
        for (int i = 0; i < players; i++) {
            int temp;
            printf("Player %d: ", i + 1);
            scanf_s("%d", &temp);
            // printf("\n");
            // printf("%d", temp);
            playersNames[i] = temp;
        }

    }
    else if (players == 0) {
        printf("No one is playing the game!");
        exit(0);
    }
    else if (players == 1) {
        printf("Too little players are playing the game");
        exit(0);
    }
    else {
        printf("Too many players are playing the game");
        exit(0);
    }

    for (int i = 0; i < players; i++) {
        printf("%d, ", playersNames[i]);
    }
}

int shuffle_Chance(){
    // Chance Cards

    int chanceCards[] = { 1, 2, 3, 4, 5, 6 };

    int sizechanceCards = sizeof(chanceCards) / sizeof(chanceCards[0]);

    for (int i = 0; i < sizechanceCards; i++) {
        int r = random_in_range(0, sizechanceCards-1);
        int temp = chanceCards[r];
        chanceCards[r] = chanceCards[i];
        chanceCards[i] = temp;
    }
    for (int i = 0; i < 6; i++) {
        printf("%d ", chanceCards[i]);
    }
    return 1;
}

int shuffle_Community(){
    // Community Cards

    int communityCards[] = { 1, 2, 3, 4, 5, 6 };

    int sizeCommunityCards = sizeof(communityCards) / sizeof(communityCards[0]);

    for (int i = 0; i < sizeCommunityCards; i++) {
        int r = random_in_range(0, sizeCommunityCards-1);
        int temp = communityCards[r];
        communityCards[r] = communityCards[i];
        communityCards[i] = temp;
    }

    for (int i = 0; i < 6; i++) {
        printf("%d ", communityCards[i]);
    }
    return 1;
}

int main() {
    srand((unsigned int)time(NULL));

    player_Assortment();

    int num;
    printf("\n---------------\n");
    printf("Which card would you like to pull?\nFor community card, press 1\nFor chance card, press 0\n-> ");
    scanf_s("%d", &num);

    if (num == 1) {
        shuffle_Community();
    }
    else if (num == 0) {
        shuffle_Chance();
    }
    else {
        printf("Invalid choice.\n");
    }

    printf("\n\nPress 0 to exit the game - ");
    scanf_s("%d", &num);

    return 0;
}