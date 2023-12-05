#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <ncurses.h>

//any prototypes here
void randString (char seed[]);
void base(int t);
void triangle(int t);
void circle(int t);
void xselect(int t);
void square(int t);

int main() {
	//add variables here
	time_t seconds;
	char name; //name is just a placeholder for the scoreboard, the variable name can be changed later
	char seed[100], guess; //guess is just used to compare the user's guess to the correct answer
	int score = 0; //use to keep track of the current score
	int round = 0; //use to keep track of the current round, initialized for turn 1
	int playing = 1; //used to keep track of whether the player has incorrectly guessed, 0 will represent a loss in the while loop
	
	
	//welcome to the game
	printf("Welcome to the Memory game.\nTo start the game press \"g\"\n");
	printf("In the game various shapes will appear with a circle around it\n");
	printf("You must remember the shapes that are circled and repeat the order\n");
	printf("Use w for up, s for down, d for right, a for left\n\n");
	printf("Highscore Table:\nRank  Score  Name\n");
	
	//read and print txt file here
	
	//ask to begin game and countdouwn
	
	//randomize the seed string
	randString(seed);
	printf("Seed = %s\n", seed); //remove this later
	
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
				break;
			}
			else{
				score++;
				printf("Score: %d\n\n", score);
			}
			
		}
		
	}
	
	
	//add code to check if scoreboard needs to be updated
	
	printf("Congratulation, you made it on the highscore table\nPlease enter your name (Only 3 capital letters):\n");
	scanf(" %s", name);
	
	//code to make sure the name is only three letters and all capital
	
	//add code here for updating and displaying the scoreboard here
	
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