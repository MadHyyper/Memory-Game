// Included libraries
#include <stdio.h>
#include <curses.h>

/* Useful ncurses functions:
    - initscr()
    - printw()
    - refresh()
    - getch()
    - endwin()
*/

// Main function
int main(){
    // Setup ncurses environment
    // initialize screen
    initscr();
    // print to screen
    printw("Hello World!");
    // refresh screen
    refresh();
    // pause screen output
    getch();
    // end ncurses window
    endwin();

    return 0;
}