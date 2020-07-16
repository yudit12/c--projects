#include "Character.h"
#include <cstdlib>

int Character::_rows;
int Character::_cols;
//-------------------------------------------------------------------------------------------------------------------------------------
Character::Character(int x, int y){
 this->x=x;
 this->y=y;
 newDir();
 

}

//------------------------------------------------------------------------------------------------------------------------------------
//Method defines the posibole direction

void Character:: newDir(){
// %9 return opteion between 0-8 +1 return opteion between 1-9
	dir = rand() % 9 +1;// return num between zero--->big num
	numOfSteps= steps;


}
//---------------------------------------------------------------------------------------------------------------------------------------
// Method represents progress in different directions
void Character:: advance(){

switch (dir){
	case up://8
	 y--;
	break;
	case down://2
	 y++;
	break;
	case rightSide://6
	x++;
	break;
	case leftSide://4
	 x--;
	break;
	case upRight: //9
		x++;
		y--;
	break;
	case upLeft: //7
		x--;
		y--;
	break;
	case downRight://3
		x++;
		y++;
	break;
	case downLeft://1
		x--;
		y++;
	break;
	default:

	 // noMove=5
	break;
}

}

//------------------------------------------------------------------------------------------------------------------------------------
// A method that alters to the opposite direction of leftwall
  void Character:: ExtremeCase_leftwall(){
  	switch (dir){
	
			case leftSide://4
				dir=rightSide;//6
			break;
			case upLeft: //7
				dir=upRight;//9
			break;
			case downLeft://1
				dir=downRight;//3
			break;
		
			default:
			break;
			}
		
  
  }

//--------------------------------------------------------------------------------------------------------------------------------
// A method that alters to the opposite direction of wallup
 void Character:: ExtremeCase_wallUp(){
 	switch (dir){
				case up://8
					dir=down ;//2
				break;
				case upRight: //9
					dir=downRight;//3
				break;
				case upLeft: //7
					dir=downLeft;//1
				break;
	
				default:
				break;
	
	
				}
		
 }
 
 //-------------------------------------------------------------------------------------------------------------------------------------
  // A method that alters to the opposite direction of wallright
 void Character:: ExtremeCase_wallright(){
 	switch (dir){
		case rightSide: //6
			dir=leftSide;//4
		break;
		case upRight: //9
			dir=upLeft ;//7
		break;
	
		case downRight://3
			dir=downLeft;//1
		break;

		default:
		break;
		}
		
 }
 //------------------------------------------------------------------------------------------------------------------------------------
 // A method that alters to the opposite direction of walldown
 void Character:: ExtremeCase_walldown(){
 	switch (dir){
	
		case down://2
		 	dir=up;//8
		break;
	
		case downRight://3
			dir=upRight;//9
		break;
		case downLeft://1
			dir=upLeft;//7
		break;
		default:
		break;
		}
		
 }

//-------------------------------------------------------------------------------------------------------------------------------
//A method that changes direction if it in the corner (to the opposit direction)  and returns true, if not returns false
 bool Character:: ExtremeCase_isCorner_upLeft(){
 	switch (dir){
			case up://8
				dir=down;//2
			return true;// made the change
			case leftSide: //4
				dir=rightSide;//6
			return true;// made the change
			case upLeft: //7
				dir=downRight;//3
			return true;// made the change
	
			default:
			break;
			}
			return false;
		

 }
 
 //----------------------------------------------------------------------------------------------------------------------------------
//A method that changes direction if it in the corner (to the opposit direction)  and returns true, if not returns false
  bool Character:: ExtremeCase_isCorner_downLeft(){
 	switch (dir){
			case down://2
				dir=up;//8
			return true;// made the change
			case leftSide: //4
				dir=rightSide;//6
			return true;// made the change
			case downLeft: //1
				dir=upRight;//9
			return true;// made the change
	
			default:
			break;
		}
		return false;
		

 }
 
 //-------------------------------------------------------------------------------------------------------------------------------------
 //A method that changes direction if it in the corner (to the opposit direction)  and returns true, if not returns false
  bool Character:: ExtremeCase_isCorner_upRight(){
 	switch (dir){
			case up://8
				dir=down;//2
			return true;// made the change
			case rightSide: //6
				dir=leftSide;//4
			return true;// made the change
			case upRight: //9
				dir=downRight;//3
			return true;// made the change
	
			default:
			break;
			}
			return false;

 }
 
 //---------------------------------------------------------------------------------------------------------------
//A method that changes direction if it in the corner (to the opposit direction)  and returns true, if not returns false
 bool Character:: ExtremeCase_isCorner_downRight(){
 	switch (dir){
			case down://2
				dir=up;//8
			return true;
			case rightSide: //6
				dir=leftSide;//4
			return true;
			case downRight: //3
				dir=upLeft;//7
			return true;
	
			default:
			break;
		}
		return false;

 }
 
 
//-----------------------------------------------------------------------------------------------------------------------------------
//empty distructor because there is anything to destroy-  we don't allocate memory
Character:: ~Character(){
 
  
 }
 //------------------------------------------------------------------------------------------------------------------------------