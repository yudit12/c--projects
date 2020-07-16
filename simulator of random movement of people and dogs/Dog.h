# ifndef DOG_H
# define DOG_H
# include "Character.h"


class Dog : public Character{

public:
Dog(int x, int y);
void draw();
void advance();
bool isCorner();
static bool isGoodPlace(int x, int y);
~Dog();

};
#endif