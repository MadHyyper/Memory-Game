//SE 185: Final Project Template//
/////////////////////////
/*
Team xx (please insert your team number instead of xx)
Team member 1 "Eleena Rath" 
Team member 2 "Conner Houdek"  
Team member 3 "Mallory Flynn" 
Team member 4 "Malak Mansour" 
*/
////////////////////
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <ncurses.h>
#include <string.h>

#define MAX_SCORES 10
#define MAX_NAME_LENGTH 3 

// Define a struct to represent a highscore entry
struct Highscore {
    int score;
    char initials[MAX_NAME_LENGTH + 1];  // +1 for the null terminator
};

// Global highscore array
struct Highscore highscores[MAX_SCORES];


//any prototypes here
void randString (char seed[]);
void base(int t);
void triangle(int t);
void circle(int t);
void xselect(int t);
void square(int t);
void updateHighscores(int userScore);
void displayHighscores();
void saveHighscoresToFile();
void loadHighscoresFromFile();



int main() {
	//add variables here
	time_t seconds;
	char name; //name is just a placeholder for the scoreboard, the variable name can be changed later
	char seed[100], guess, answer; //guess is just used to compare the user's guess to the correct answer
	int score = 0; //use to keep track of the current score
	int round = 0; //use to keep track of the current round, initialized for turn 1
	int playing = 1; //used to keep track of whether the player has incorrectly guessed, 0 will represent a loss in the while loop
	
	
	//welcome to the game
	printf("Welcome to the Memory game.\nTo start the game press \"g\"\n");
	printf("In the game various shapes will appear with a circle around it\n");
	printf("You must remember the shapes that are circled and repeat the order\n");
	printf("Use w for up, s for down, d for right, a for left\n\n");
	//printf("Highscore Table:\nRank  Score  Name\n");
	
	//read and print txt file here
	 for (int i = 0; i < MAX_SCORES; i++) {
        highscores[i].score = 0;
        highscores[i].initials[0] = '\0';
    }
	loadHighscoresFromFile();
	displayHighscores();
	
	//ask to begin game and countdouwn
	printf("What would you like to do?\n");
    printf("'g' for a game\n");
	//initialize countdown
	 scanf(" %c", &answer);
    if (answer == 'g') {
        time(&seconds);
        for (int seconds = 3; seconds > 0; seconds--) {
            printf("%d...\n", seconds);
            sleep(1);
		}
	}
	else{
		printf("Oh, okay then. Goodbye");
		exit(0);
	}
	
	//randomize the seed string
	randString(seed);
	
	while (playing == 1){
		round++;
		printf("Turn: %d\nScore: %d\n", round, score);
		sleep(2);
		
		//display the screen here, create a for loop for flashing the different game screens depending on seed[i]
		initscr();
		base(1);
		clear();
		for (int i = 0; i < round; i++){
			if (seed[i] == 'w'){
				triangle(1);//triangle select screen for __ seconds
				clear();
				base(1);//base screen for __ seconds
				clear();
			}
			else if(seed[i] == 'd'){
				circle(1);//diamond select screen for __ seconds
				clear();
				base(1);//base screen for __ seconds
				clear();
			}
			else if(seed[i] == 's'){
				xselect(1);//x select screen for __ seconds
				clear();
				base(1);//base screen for __ seconds
				clear();
			}
			else if(seed[i] == 'a'){
				square(1);//square select screen for __ seconds
				clear();//base screen for __ seconds
				base(1);
				clear();
			}
		}
		endwin();	
		
		
		printf("Okay, what was the order?(use w,a,s,d)\n");
		for (int i = 0; i < round; i++){
			printf("%d time: ", i + 1);
			scanf(" %c", &guess);
			
			if (guess != seed[i]){
				printf("Nope the correct answer was %c.\n", seed[i]);
				printf("Sorry, you lose, at least you got to turn %d.\n", round);
				printf("Your final score was %d. Try again and get even higher!\n", score);
				playing = 0;
				highscores[11].score = score;
				break;
			}
			else{
				score++;
				printf("Score: %d\n\n", score);
			}
			
		}
		
	}
	
	
	//code to check if scoreboard needs to be updated
	updateHighscores(score);
	displayHighscores(); //displays high score to screen
	saveHighscoresToFile(); //saves the highscores to the txt file
	
	return 0;
}

	//random number function 
void randString (char seed[]){
	srand(time(NULL));
	for(int i = 0; i < 100; i++){
		
		int random = (rand() % 4);
		if(random == 0) {
			seed[i] = 'w';
			//printf("triangle");	//press w
		} else if (random == 1) {
			seed[i] = 'd';
			//printf("circle\n"); //press d
		} else if (random == 2) {
			seed[i] = 's';
			//printf("X\n"); //press s
		} else if (random == 3) {
			seed[i] = 'a';
			//printf("square\n");//press a
		}
	}
	
}

void displayHighscores() {
    printf("\nHighscore Table:\nRank  Score  Name\n");
    for (int i = 0; i < MAX_SCORES; i++) {
        printf("%-6d%-6d%s\n", i + 1, highscores[i].score, highscores[i].initials);
    }
}

void updateHighscores(int userScore) {
	if (userScore > highscores[9].score){
		highscores[9].score = userScore;
		printf("\nCongratulations! You've earned a spot on the highscore table!\n");
		while (1){
        printf("Enter your initials (3 characters): ");
        scanf("%s", highscores[9].initials);
		if (strlen(highscores[9].initials) == 3) {
                    int validInput = 1;
                    for (int j = 0; j < 3; j++) {
                        if (!isupper(highscores[9].initials[j])) {
                            validInput = 0;
                            break;
                        }
                    }

                    if (validInput) {
                        break;  // Exit the loop if the input is valid
                    }
                }
		}
	}
	struct Highscore temp;
    for (int i = 9; i > 0; i--) {
        if (highscores[i].score > highscores[i-1].score) {
			temp = highscores[i-1];
			highscores [i-1] = highscores[i];
			highscores[i] = temp;
		}
    }
}

void base(int t){
	printw("	       ^\n");
	printw("	      ^^^\n");
	printw("	     ^^^^^\n");
	printw("	    ^^^^^^^\n");
	printw("	   ^^^^^^^^^\n");
	printw("	  ^^^^^^^^^^^\n");

	
	printw("\n\n");
		
	printw("HHHHHHH			   00\n");
	printw("H     H			  0  0\n");
	printw("H     H			 0    0\n");
	printw("H     H			0      0\n");
	printw("H     H			0      0\n");
	printw("H     H			 0    0\n");
	printw("HHHHHHH			  0  0\n");
	printw("     			   00\n");
	
	printw("\n\n");
	
	printw("	    X     X\n");
	printw(" 	     X   X\n");
	printw("  	      X X\n");
	printw("   	       X\n");
	printw("  	      X X\n");
	printw(" 	     X   X\n");
	printw("	    X     X\n");
	
	printw("\n\n");
	refresh();
	sleep(t);
}
	
void triangle(int t){	
	//triangle selected
	
	printw("	 ...............\n");
	printw("	 .      ^      .\n");
	printw("	 .     ^^^     .\n");
	printw("	 .    ^^^^^    .\n");
	printw("	 .   ^^^^^^^   .\n");
	printw("	 .  ^^^^^^^^^  .\n");
	printw("	 . ^^^^^^^^^^^ .\n");
	printw("	 ...............\n");

	printw("\n");
	printw("\n");
		
		
	printw("HHHHHHH			   00\n");
	printw("H     H			  0  0\n");
	printw("H     H			 0    0\n");
	printw("H     H			0      0\n");
	printw("H     H			0      0\n");
	printw("H     H			 0    0\n");
	printw("HHHHHHH			  0  0\n");
	printw("     			   00\n");
	
	printw("\n");
	printw("\n");
	
	printw("	    X     X\n");
	printw(" 	     X   X\n");
	printw("  	      X X\n");
	printw("   	       X\n");
	printw("  	      X X\n");
	printw(" 	     X   X\n");
	printw("	    X     X\n");
	
	printw("\n");
	printw("\n");
	refresh();
	sleep(t);
	
}
void xselect(int t){
	
	// x selected
	
	printw("	       ^\n");
	printw("	      ^^^\n");
	printw("	     ^^^^^\n");
	printw("	    ^^^^^^^\n");
	printw("	   ^^^^^^^^^\n");
	printw("	  ^^^^^^^^^^^\n");

	
	printw("\n\n");
		
	printw("HHHHHHH			   00\n");
	printw("H     H			  0  0\n");
	printw("H     H			 0    0\n");
	printw("H     H			0      0\n");
	printw("H     H			0      0\n");
	printw("H     H			 0    0\n");
	printw("HHHHHHH			  0  0\n");
	printw("     			   00\n");
	
	printw("\n\n");
	
	printw("	   ...........\n");
	printw("	   . X     X .\n");
	printw(" 	   .  X   X  .\n");
	printw("  	   .   X X   .\n");
	printw("   	   .    X    .\n");
	printw("  	   .   X X   .\n");
	printw(" 	   .  X   X  .\n");
	printw("	   . X     X .\n");
	printw("	   ...........\n");
	
	printw("\n\n");
	refresh();
	sleep(t);
}
	
void circle(int t){	
	//circle selected 
	
	printw("	       ^\n");
	printw("	      ^^^\n");
	printw("	     ^^^^^\n");
	printw("	    ^^^^^^^\n");
	printw("	   ^^^^^^^^^\n");
	printw("	  ^^^^^^^^^^^\n");

	
	printw("\n\n");
	printw("		  ............\n");	
	printw("HHHHHHH		  .    00    .\n");
	printw("H     H		  .   0  0   .\n");
	printw("H     H		  .  0    0  .\n");
	printw("H     H		  . 0      0 .\n");
	printw("H     H		  . 0      0 .\n");
	printw("H     H		  .  0    0  .\n");
	printw("HHHHHHH		  .   0  0   .\n");
	printw("     		  .    00    .\n");
	printw("               	  ............");
	
	printw("\n\n");
	
	printw("	    X     X\n");
	printw(" 	     X   X\n");
	printw("  	      X X\n");
	printw("   	       X\n");
	printw("  	      X X\n");
	printw(" 	     X   X\n");
	printw("	    X     X\n");
	
	printw("\n\n");
	refresh();
	sleep(t);
}

void square(int t){	
	//square selected
	
	printw("	       ^\n");
	printw("	      ^^^\n");
	printw("	     ^^^^^\n");
	printw("	    ^^^^^^^\n");
	printw("	   ^^^^^^^^^\n");
	printw("	  ^^^^^^^^^^^\n");

	
	printw("\n\n");
	
	printw("...........\n");
	printw(". HHHHHHH .		  00\n");
	printw(". H     H .		 0  0\n");
	printw(". H     H .		0    0\n");
	printw(". H     H .	       0      0\n");
	printw(". H     H .	       0      0\n");
	printw(". H     H .		0    0\n");
	printw(". HHHHHHH .		 0  0\n");
	printw("...........       	  00\n");
	
	printw("\n\n");
	
	printw("	    X     X\n");
	printw(" 	     X   X\n");
	printw("  	      X X\n");
	printw("   	       X\n");
	printw("  	      X X\n");
	printw(" 	     X   X\n");
	printw("	    X     X\n");
	
	printw("\n\n");
	refresh();
	sleep(t);
}
void saveHighscoresToFile() {
    FILE *file = fopen("highscores.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    for (int i = 0; i < MAX_SCORES; i++) {
        fprintf(file, "%d %s\n", highscores[i].score, highscores[i].initials);
    }

    fclose(file);
}

void loadHighscoresFromFile() {
    FILE *file = fopen("highscores.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    for (int i = 0; i < MAX_SCORES; i++) {
        if (fscanf(file, "%d %s", &highscores[i].score, highscores[i].initials) != 2) {
            break;  // Stop reading if there are no more valid entries
        }
    }

    fclose(file);
}
