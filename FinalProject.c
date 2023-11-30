//SE 185: Final Project Template//
/////////////////////////
/*
Team xx (please insert your team number instead of xx)
Team member 1 "Name" | "Percentage of Contribution to The Project"
Team member 2 "Name" | "Percentage of Contribution to The Project"
Team member 3 "Name" | "Percentage of Contribution to The Project"
Team member 4 "Name" | "Percentage of Contribution to The Project"
*/
////////////////////
#include<stdio.h>
#include<time.h>
#include<unistd.h>

// Define necessary constants
#define MAX_SCORES 10
#define MAX_NAME_LENGTH 3  // Assuming initials are of length 3

// Define a struct to represent a highscore entry
struct Highscore {
    int score;
    char initials[MAX_NAME_LENGTH + 1];  // +1 for the null terminator
};

// Global highscore array
struct Highscore highscores[MAX_SCORES];

// Function to display the highscore table
void displayHighscores() {
    printf("\nHighscore Table:\nRank  Score  Name\n");
    for (int i = 0; i < MAX_SCORES; i++) {
        printf("%-6d%-6d%s\n", i + 1, highscores[i].score, highscores[i].initials);
    }
}

// Function to update highscores based on the user's score
void updateHighscores(int userScore) {
    for (int i = 0; i < MAX_SCORES; i++) {
        if (userScore > highscores[i].score) {
            printf("\nCongratulations! You've earned a spot on the highscore table!\n");
            printf("Enter your initials (3 characters): ");
            scanf("%s", highscores[i].initials);
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

    // add variables here
    time_t seconds;
    char answer;
    char seed[100];

    // welcome to the game
    printf("Welcome to the Memory game.\nTo start the game press 'g'\n");
    printf("In the game various shapes will appear with a circle around it\n");
    printf("You must remember the shapes that are circled and repeat the order\n");
    printf("Use w for up, s for down, d for right, a for left\n");

    // display highscore table
    displayHighscores();

    printf("What would you like to do?\n");
    printf("'g' for a game\n");

    // if statement and countdown
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
