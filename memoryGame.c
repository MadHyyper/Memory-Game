#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main() {
	//add variables here
	time_t seconds;
	char answer;
	char seed[100];
	
	//welcome to the game
	printf("Welcome to the Memory game.\nTo start the game press 'g'\n");
	printf("In the game various shapes will appear with a circle around it\n");
	printf("You must remember the shapes that are circled and repeat the order\n");
	printf("Use w for up, s for down, d for right, a for left\n\n");
	printf("Highscore Table:\nRank  Score  Name\n");
	
	//read and print txt file here
	
	printf("What would you like to do?\n");
	printf("'g' for a game\n");

	//if statement and countdown
	scanf(" %c", &answer);
	if(answer == 'g') {
		time(&seconds);
		for(int seconds = 4; seconds > 1; seconds--) {
			printf("%ld...\n", seconds - 1);
			sleep(1);
		}
	} else { 
		printf("\nInvalid input. Please press 'g' to start the game.\n");
	}
	
	return 0;
}