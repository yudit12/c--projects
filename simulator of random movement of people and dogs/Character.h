#ifndef CHARACTER_H
#define CHARACTER_H
#include <curses.h>
#define steps 17
// direction
#define up 8
#define down 2
#define leftSide 4
#define rightSide 6
#define upRight 9
#define upLeft 7
#define downRight 3
#define downLeft 1
# define noMove 5

class Character{

protected:
int x;
int y;
int dir;//direction
int numOfSteps;
void advance();
void newDir();
void  ExtremeCase_leftwall();
void  ExtremeCase_wallUp();
void  ExtremeCase_wallright();
void  ExtremeCase_walldown();

bool  ExtremeCase_isCorner_upLeft();
bool  ExtremeCase_isCorner_downLeft();
bool  ExtremeCase_isCorner_upRight();
bool  ExtremeCase_isCorner_downRight();
public:


static int _rows, _cols;
 Character(int x, int y);
 ~Character();

};
#endif