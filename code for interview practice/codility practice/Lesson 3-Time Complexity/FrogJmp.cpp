/******************************************************************************
time complexity section:

Count minimal number of jumps from position X to Y.

*******************************************************************************/
#include <iostream>
using namespace std;
#include <vector>
#include <set>
#include <math.h>     

int solution(int X, int Y, int D);
int main()
{
    int X=10;
    int Y=85;
    int D=30;
    int res=solution( X,  Y,  D);
    std::cout << res << std::endl;

    return 0;
}


int solution(int X, int Y, int D) {
 
//  return (Y - X + (D - 1)) / D; 
    return ceil(ceil(Y-X )/D) ;
}
