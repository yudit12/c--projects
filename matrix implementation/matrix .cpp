#include "matrix.h"
using  namespace  std;

 //-----------------------------------------------------------------------------------------------------------------------------------
 //  destroy this matrix.
Matrix::~Matrix(){

for(int i=0;i<rows; i++)
	delete(_array[i]);
	
	delete (_array);
	
}

//----------------------------------------------------------------------------------------------
//counstractor that allocating the pointer array of rows and for each cell in this array  allocating new array of columns
Matrix:: Matrix(int rows, int cols){
this->rows=rows;
this->colls=cols;

_array = new (double*)[rows];// allocating the rows
for(int i=0;i<rows; i++)
	_array[i]=new double [colls];// allocating the columns

}


//-------------------------------------------------------------------------------------------------------------
// get mehod that apply the user access to rows
int Matrix:: getRows(){
	return rows;
}


//-------------------------------------------------------------------------------------------------------------
// // get mehod that apply the user access to colls
int Matrix:: getCols(){
	return colls;
}

//-------------------------------------------------------------------------------------------------------------------
// method that initializes the matrix,each cell to a zero,
void  Matrix::initMatrix(){

	for (int i=0 ; i < rows ; i++)
	      for (int j=0 ; j < colls ; j++)
	             _array[i][j] = 0;
}


//-------------------------------------------------------------------------------------------------------------------------
// metod thatput value into matrix cell 
// i- which row j- which colum 
// in case entred ilegal cell the system will exit(1)

 void Matrix:: setElement(int i, int j, double data){
 	if(i>rows || j>colls){
 		exit(1);
 	}
 	_array[i][j]=data;
 
 }
 
 //-------------------------------------------------------------------------------------------------------------------------
// metod that get value of wanted matrix cell
// i- which row j- which colum 
// in case entred ilegal cell the system will exit(1)

 
 double  Matrix:: getElement(int i, int j){
 	if(i>rows || j>colls){
 		exit (1);
 	}
 return _array[i][j];
 
 }
 
 
 //--------------------------------------------------------------------------------------------------------------------------------
 //method will connect values of two matrices and returns the result in a new matrix.
//his method wiil check that is possible to connect this two matrices;
 
 void Matrix:: add(Matrix& other, Matrix& result){
 	
 	if( colls!=other.colls || colls!=result.colls){
 		exit(1);
 	}
 	if(rows!=other.rows || rows!=result.rows){
 		exit(1);
 	}
 	
 	for (int i=0 ; i < rows ; i++)
	      for (int j=0 ; j < colls ; j++){
	      //result._array[i][j]=_array[i][j]+ other._array[i][j];
	      result.setElement(i,j,getElement(i,j)+other.getElement(i,j));
	      }
	         
 }
 
 
 //---------------------------------------------------------------------------------------------------------------------------------------
 // method performs the multiplication of the matrix  by given power 
//for example, if given that the power is 3 the method will multiply the matrix herself three times.

  void Matrix:: pow(int power, Matrix& result) {
  	if(result.rows !=rows ||result.colls!=colls){
  		exit(1);
  	}
  	else if (result.rows !=result.colls){
  		result.initMatrix();
  	}
  	
  	else {
  		for (int i=0 ; i < rows ; i++){ 
  			for(int k=0;k<colls;k++){
  				double temp = 0;
  		
	     			for (int j=0 ; j < colls ; j++){ 
	     				temp += getElement(i,j)*getElement(j,k);
	     				
	     			}
	      			result.setElement(i,k,temp);
	      		}
	      
	      	}
	}
}
	
//---------------------------------------------------------------------------------------------------------------------------
// method that print the matrix	
	
	void Matrix::print()
{
	for (int i=0 ; i < rows ; i++)
	{
	           for (int j=0 ; j < colls ; j++)
	  	  cout <<_array[i][j] << ", ";
	           cout << "\b\b \n";
	}
}



//---------------------------------------------------------------------------------------------------------------------------------
// method that replace between the matrix's rows and columns
// by crateing new array that his rows equal to  original cols ans the cols equal to the original rows
// entring the data of the upside cell  destroy the original array  ans saving the new information in the original array/
void Matrix:: transpose(){

// create new ** array
double **tempArr = new double*[colls];// allocating the rows
for(int i=0;i<colls; i++)
	tempArr[i]=new double [rows];// allocating the columns


for(int i=0;i<rows;i++){
	for(int j=0;j<colls;j++){
	tempArr[j][i]=_array[i][j];
	


	}

}
for(int i=0;i<rows; i++)
	delete(_array[i]);
	
	delete (_array);


_array = tempArr;
int temp =rows;
rows=colls;
colls=temp;
}
	      	
  
  
 
 
 

