#ifndef PERSON_H
#define PERSON_H
#include "Character.h"

class Person: public Character {


public:
Person(int x, int y);
void draw();
void advance();
bool isCorner();
static bool isGoodPlace(int x, int y);
~Person();
};
#endif
