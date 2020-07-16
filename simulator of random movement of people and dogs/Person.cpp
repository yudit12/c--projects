# include "Person.h"
//--------------------------------------------------------------------------------------------------------------------------------
//constructor that initialize from his father
Person::Person(int x, int y): Character(x,y){
// aba distructor doing all work	
	
}

//---------------------------------------------------------------------------------------------------------------------------------
// method that traw an person by corrected coordinates 
void Person:: draw(){
attron(COLOR_PAIR(2));//use the color
move (y,x);// print head
addstr(" ");
for(int i = 1; i <=3; i++){
	move(y+i,x);//print belly
	addstr(" ");
	move(y+1,x-i);//print lef hand
	addstr(" ");
	move(y+1,x+i);//print right hand
	addstr(" ");
	move(y+3+i,x-i);// print left leg
	addstr(" ");
	move (y+3+i,x+i);//print right leg
	addstr(" ");
	
	

}

}
//-------------------------------------------------------------------------------------------------------------------------------------
//  method that determines and change the direction, if its needed,  of the movement on the screen
// by checking extreme point on the board
void Person:: advance(){
	if(numOfSteps == 0){// new direction
	 	newDir();
	 }
	if(!isCorner()){
	// Extreme cases	
		if(x==4) {// left wall
			ExtremeCase_leftwall();
		


		}
		if( y==1){// wall up
			 ExtremeCase_wallUp();
				
		
		}
	
		 if(x==_cols-4){// wall right
			ExtremeCase_wallright();
			

	
		}
	
		 if( y==_rows-7){//wall down 
			ExtremeCase_walldown();
			}

		}
		Character:: advance();
		numOfSteps--;
	
		}


//---------------------------------------------------------------------------------------------------------------------------------------
//method that check few more extreme cases of  corner's limit
//if true - it proplem corner and we change direction
//false -not problem corner
bool Person:: isCorner(){
	if(x==4 && y==1){// up left corner
		return ExtremeCase_isCorner_upLeft();// father method
	}
	
	
	else if(x==4 && y==_rows-7){// down left corner
		return ExtremeCase_isCorner_downLeft();
		}
	
	else if(x==_cols-4 && y==1){//up right corner
		return ExtremeCase_isCorner_upRight();
	}
	
	else if(x==_cols-4 && y==_rows-7){//down right corner
		return  ExtremeCase_isCorner_downRight();
		}
	return false;
	}
	

//---------------------------------------------------------------------------------------------------------------------------------
// method that checks that th coordinate are not drawed on out of the limit
bool Person::isGoodPlace(int x, int y){
	if(x<4 || y< 1 || x>_cols-4 || y>_rows-7)
		return false;
	return true;
}
//---------------------------------------------------------------------------------------------------------------------------------

//empty distructor because there is nothing to destroy-  we don't allocate memory	
Person:: ~Person(){

}
//------------------------------------------------------------------------------------------------------------------------
	
	






