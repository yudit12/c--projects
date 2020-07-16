# include "Simulator.h"
#include "Person.h"
#include "Dog.h"
#include <cstdlib>
// static Characters
int Simulator:: _rows;
int Simulator:: _cols;


//----------------------------------------------------------------------------------------------------------------------------------------
// Constructor that  initializes the attributes 
//Creating waypoints of  two people and three dogs in the right location in the baord

Simulator:: Simulator(int rows, int cols){
_rows =rows;
_cols= cols;
Character::_rows = rows;
Character::_cols = cols;


for(int i = 0; i < 3; i++) {
	int x = 0;
        int y = 0;
	while(!Dog::isGoodPlace(x,y)) {
		x = rand() % cols;
		y = rand() % rows;
	}
	_dq.enqueue(new Dog(x,y));
}
 

for(int i=0; i<2; i++){
	int x1 = 0;
        int y1 = 0;
	while (!Person::isGoodPlace(x1,y1)){
		x1 = rand() % cols;
		y1 = rand() % rows;
	
	}
	_pq.enqueue(new Person(x1,y1));

}



}
//----------------------------------------------------------------------------------------------------------------------------------------
//A method that draws the people and dogs, and displays them on the screen
void Simulator:: run(){
	initscr(); // as usual 

      start_color(); //  start using colors 
      init_pair(1, COLOR_BLACK, COLOR_WHITE);// color board
      init_pair(2, COLOR_BLACK, COLOR_RED);// color person
       init_pair(3, COLOR_BLACK, COLOR_GREEN);// color dog
       /*Dog d(10,10);
        Person p(10,10);
        d.advance();
 	d.draw();
 	p.advance();
 	p.draw();*/
	do {
	clear();
 	for(int i = 0; i < 3; i++) {
	
		Dog* temp = _dq.dequeue();
		temp -> advance();
		temp -> draw();
		_dq.enqueue(temp);
	}
	
	for(int i=0; i<2;i++){
		Person* temp1 =_pq.dequeue();
		temp1 -> advance();
		temp1 -> draw();
		_pq.enqueue(temp1);
	}
	
 	
 	drawBoard();
 	refresh(); // show all changes.  
	}
	while(std::cin.get() != (char)27); 
      endwin(); // as usual
}

//--------------------------------------------------------------------------------------------------------------------------------------
// method that print the board -The field in which is allowed to move

void Simulator:: drawBoard(){
	
	attron(COLOR_PAIR(1));
	
	for(int i=0;i<=_rows;i++){
		move(i,0);
		addstr(" ");
		move(i,_cols);
		addstr(" ");
	
	}
	
	for(int i=0;i<=_cols;i++){
		move(0,i);
		addstr(" ");
		move(_rows,i);
		addstr(" ");
	
	} 

}
//-------------------------------------------------------------------------------------------------------------------------------------------
//empty distructor because   we don't allocate memory to the queue and the node person or dog we delete allready in the class queueDog/ queuPerson
Simulator::~Simulator()
{
  

}

//-------------------------------------------------------------------------------------------------------------------------------------------
