#include <iostream>
#include <stdlib.h> 
#include <cmath>


class  Matrix{


private:
 double **_array;
 int rows;
 int colls;
 
 
 public:
  Matrix();// empty cunstrctur
 ~Matrix();// destroy this matrix.
 
 // init matrix each cell to zero
 void  initMatrix();
 // get rows
 int getRows ();
 //get colls
 int getCols();
 // construct a 'rows X cols' matrix.
 Matrix(int rows, int cols);
 
 // set the (i,j) element to be 'data'
 void setElement(int i, int j, double data);
 
 // return the (i,j) element
 double getElement(int i, int j);
 
 // add 'this' to 'other' and put the result in 'result'
 void add(Matrix& other, Matrix& result);
// add 'this'^power and put the result in 'result'
 void pow(int power, Matrix& result);
 // transpose 'this'
 void transpose();
 // print the contents of this matrix on the screen.
 void print();
 
 

};
