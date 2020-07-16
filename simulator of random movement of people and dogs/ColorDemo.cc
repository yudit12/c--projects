// a demonstration of color display using ncurses.

// to compile : g++ ColorDemo.cc -lncurses -o demo
// to execute : demo 

#include <iostream> 
#include <curses.h>

using namespace std;
int main() {
      initscr(); // as usual 

      start_color(); //  start using colors 

      init_pair(1, COLOR_GREEN, COLOR_BLACK); // prepare a color pair:
                                              // background : BLACK
                                              // displayed text : GREEN  
                                              // the pair handle number : 1   

      init_pair(3, COLOR_CYAN, COLOR_BLACK);  // another pair. its handle is 3

      init_pair(17, COLOR_MAGENTA, COLOR_BLACK); // and yet another 

      move(1,1);
      addstr("normal state\n"); // as usual 
      
      attron(COLOR_PAIR(1));    // use the pair of handle number 1  
      move(5,5);
      addstr("writing in green\n");

      attrset(A_REVERSE);
      attron(COLOR_PAIR(1)); // after reversing the display, pair needs
                             // to be activate again.  
      addstr("reverse in green\n");

      attrset(0);
      addstr("back to normal\n"); // because the display was reversed,
                                  // and the color pair was not activate again
                                  // the display is in normal mode.  
      attron(COLOR_PAIR(3));
      addstr("CYAN\n");
      
      attron(COLOR_PAIR(17));
      addstr("MAGENTA\n");
      attroff(COLOR_PAIR(17)); // stop using the pair, back to normal.  

      addstr("back to normal, press any key..\n");
      
      refresh(); // as usual - show all changes.  

      cin.get(); // wait for a key stroke. 
      endwin(); // as usual 
}
/*
  available colors:
  
         COLOR_BLACK   
         COLOR_RED     
         COLOR_GREEN   
         COLOR_YELLOW  
         COLOR_BLUE    
         COLOR_MAGENTA 
         COLOR_CYAN    
         COLOR_WHITE   

for more information, try:

http://www.tldp.org/HOWTO/NCURSES-Programming-HOWTO/color.html


*/
