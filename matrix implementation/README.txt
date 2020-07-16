


In this exercise, we implement class that represents a mathematical matrix
The matrix will be using two-dimensional array dynamically allocated
 The matrix support Several basic services:
 1) constructor that initializes the matrix
 1) constructor that create the wanted matrix
 2) constructor that is destroying the matrix.
 3) get method allows to get the values of wanted cell in the matrix
 4) set method allows you to insert a value for a particular cell in the matrix.
 5) add method will connect values of two matrices and returns the result in a new matrix.
	this method wiil check that is possible to connect this two matrices;
 6) pow method performs the multiplication of the matrix  by given power 
	 For example, if given that the power is 3 the method will multiply the matrix herself three times.
 7) transpose method that replace between the matrix's rows and columns
 8) method that initializes the matrix,each cell to a zero, 
    in case this is not a quadratic matrix ( means that rows!=columns)
 9) print method that print the wonted matrix
 
 
 
** the set and get method willcheck that when we want to insert  data or get data of particular cell the user enter valid cell, if not the system wil exit(1) 


how the user  should to compile the program?.
 we create The file that unites all the files together called makefile
this file concerned to compile all the files together.
after saving each file when we write in the terminal "make"  all file will pass compiling.


how start runing the progrm?
you should write in the terminal ./ex3.
after,for printing start entering the wante matrix cell  



The files are divided to files with extension ".h" and files with extension ".cpp"

in files with extension ".h" we :import the needed liberys to use of method
								 create  wanted class
								 declarations to methods that implementation  in the file with extension ".cpp" with the same name.
								 
in files with extension ".cpp" we	: import the file. h with the same name and implementate all  method that relate to the file

in this programe  the files are: ex3.cpp , ex3.h, main.cpp and makefile
in main.cpp we check all the matrix method and entring the need data for iinitializes the matrix

needed inpot :
if you use me main you should enter value for each cell in the matrix (accroding to  the num of thr matrix cells

needed outpot :
printed matrix ( depend on  runing method of the metrix)


 
	

