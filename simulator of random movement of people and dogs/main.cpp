#include <iostream>
#include <stdlib.h> 
#include "Simulator.h" 

int main (int argc, char** argv){
	if (argc!=3){
		std:: cerr<<"usage: " << argv[0]<< " <Rows Num>, <cols Num>, \n";
		return 1;
	}
	
	int rows =atoi (argv[1]),cols= atoi(argv[2]);
	if(rows<10 || cols <10){
	std:: cerr<< "Board too small\n";
	return 1;
	}
	
	Simulator sim (rows, cols);
	sim.run();
	
}