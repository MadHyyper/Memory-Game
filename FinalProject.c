//SE 185: Final Project Template//
/////////////////////////
/*
Team xx (please insert your team number instead of xx)
Team member 1 "Mansour, Malak" | "Percentage of Contribution to The Project" 25%
Team member 2 "Houdek, Conner" | "Percentage of Contribution to The Project" 25%
Team member 3 "Flynn, Mallory" | "Percentage of Contribution to The Project" 25%
Team member 4 "Rath, Eleena" | "Percentage of Contribution to The Project" 25%
*/
////////////////////
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define MAX_SCORES 10
#define MAX_NAME_LENGTH 3

struct Highscore {
    int score;
    char initials[MAX_NAME_LENGTH + 1];
};

struct Highscore highscores[MAX_SCORES];

void displayHighscores() {
    printf("\nHighscore Table:\nRank  Score  Name\n");
    for (int i = 0; i < MAX_SCORES; i++) {
        printf("%-6d%-6d%s\n", i + 1, highscores[i].score, highscores[i].initials);
    }
}

void updateHighscores(int userScore) {
    for (int i = 0; i < MAX_SCORES; i++) {
        if (userScore > highscores[i].score) {
            printf("\nCongratulations! You've earned a spot on the highscore table!\n");

            // Use a loop to ensure the user inputs exactly 3 uppercase letters
            while (1) {
                printf("Enter your initials (3 uppercase letters): ");
                scanf("%3s", highscores[i].initials);

                // Check if the input has exactly 3 characters and if they are all uppercase
                if (strlen(highscores[i].initials) == 3) {
                    int validInput = 1;
                    for (int j = 0; j < 3; j++) {
                        if (!isupper(highscores[i].initials[j])) {
                            validInput = 0;
                            break;
                        }
                    }

                    if (validInput) {
                        break;  // Exit the loop if the input is valid
                    }
                }

                printf("Invalid input. Please enter exactly 3 uppercase letters.\n");
            }

            highscores[i].score = userScore;

            // Sort the highscores in descending order
            for (int j = i; j > 0 && highscores[j].score > highscores[j - 1].score; j--) {
                // Swap entries
                struct Highscore temp = highscores[j];
                highscores[j] = highscores[j - 1];
                highscores[j - 1] = temp;
            }
            break;
        }
    }
}

int main() {
    // Initialize highscores with default values
    for (int i = 0; i < MAX_SCORES; i++) {
        highscores[i].score = 0;
        highscores[i].initials[0] = '\0';
    }

    time_t seconds;
    char answer;

    printf("Welcome to the Memory game.\nTo start the game press 'g'\n");
    printf("In the game various shapes will appear with a circle around it\n");
    printf("You must remember the shapes that are circled and repeat the order\n");
    printf("Use w for up, s for down, d for right, a for left\n");

    displayHighscores();

    printf("What would you like to do?\n");
    printf("'g' for a game\n");

    scanf(" %c", &answer);
    if (answer == 'g') {
        time(&seconds);
        for (int seconds = 3; seconds > 0; seconds--) {
            printf("%d...\n", seconds);
            sleep(1);
        }

        // Call function to start the game (not implemented here)
        // int userScore = startGame();
        int userScore = 5;  // Placeholder for user's score
        printf("Your score: %d\n", userScore);

        // Call function to update highscores
        updateHighscores(userScore);

        // Display updated highscore table
        displayHighscores();
    } else {
        printf("\nInvalid input. Please press 'g' to start the game.\n");
    }

    return 0;
}

