 #include "matrix.h"

int main (){
Matrix m1(2,2);
Matrix m2(2,2);
Matrix m3(2,2);
for (int i=0 ; i < m1.getRows() ; i++){
	      for (int j=0 ; j < m1.getCols() ; j++){
	     	 double temp;
	            std::cin >>  temp;
	        m1.setElement(i,j,temp);
	        m2.setElement(i,j,2);
	           
 		}
 }

  m1. print();
  //m1.add (m1,m2);
 // m2.print();
  m1.transpose();
  m1. print();
 // m1.pow(3, m2);
 // m. print();
  
     //cout << "Enter string and number:\n" << endl;
    

return 0;


}

