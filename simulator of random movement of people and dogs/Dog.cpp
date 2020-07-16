# include "Dog.h"
//--------------------------------------------------------------------------------------------------------------------------
//constructor that initialize from his father
Dog::Dog(int x, int y): Character(x,y){
// aba distructor doing all work	
	
}
//-----------------------------------------------------------------------------------------------------------------------------------
// method that traw dog by corrected coordinates 
void Dog:: draw(){

attron(COLOR_PAIR(3));//use the color
move (y,x);
addstr(" ");
move (y+1,x);
addstr(" ");
move(y+2,x-1);
addstr(" ");
move(y+2,x);
addstr(" ");
move(y+2,x+1);
addstr(" ");
move(y+2,x+2);
addstr(" ");
move(y+2,x+3);
addstr(" ");
move(y+2,x+4);
addstr(" ");
move(y+3,x+1);
addstr(" ");
move(y+4,x+1);
addstr(" ");
move(y+3,x+3);
addstr(" ");
move(y+4,x+3);
addstr(" ");



}
//---------------------------------------------------------------------------------------------------------------------------------
//  method that determines and change the direction, if its needed,  of the movement on the screen
// by checking extreme point on the board
//
void Dog:: advance(){
	if(numOfSteps == 0){// new direction
	 	newDir();
	 }
	 

	if(!isCorner()){
// Extreme cases	
	if(x==2) {// left wall
		ExtremeCase_leftwall();
			}
		


	}
	if( y==1){// wall up
		ExtremeCase_wallUp();
					
	}
	
	 if(x==_cols-5){// wall right
		
		ExtremeCase_wallright();

	
	}
	
	 if( y==_rows-5){//wall down 
		ExtremeCase_walldown();
	}
	Character:: advance();
	numOfSteps--;
	
	
	
}
//-------------------------------------------------------------------------------------------------------------------------------
//method that check few more extreme cases of  corner's limit
//if true - it problem corner so change direction
//false -not problem corner
bool Dog:: isCorner(){
	if(x==2&& y==1){// up left corner
		return ExtremeCase_isCorner_upLeft();// father method
		
	}
	if(x==2 && y==_rows-5){// down left corner
	
		return ExtremeCase_isCorner_downLeft();
	}
	
	if(x==_cols-5 && y==1){//up right corner
		
		return ExtremeCase_isCorner_upRight();
	}
	
	if(x==_cols-5 && y==_rows-5){// down right corner
	
		return ExtremeCase_isCorner_downRight();
	
	}
	return false;
}
//---------------------------------------------------------------------------------------------------------------------------------------
// method that checks that th coordinate are not drawed on out of the limit
bool Dog::isGoodPlace(int x, int y){
	if(x<2 || y<1 || x>_cols-5 || y>_rows-5)
		return false; // if bad plase
	return true;
}

//--------------------------------------------------------------------------------------------------------------------------------------
//empty distructor because there is nothing to destroy-  we don't allocate memory
Dog::~Dog(){

}
//------------------------------------------------------------------------------------------------------------------------------