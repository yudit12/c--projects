/******************************************************************************
Find longest sequence of zeros in binary representation of an integer. between two 1's 
*******************************************************************************/
#include <iostream>
using namespace std;
int solution(int N);
int main()
{
    int N=32;
    int res= solution( N);
    std::cout << res << std::endl;

    return 0;
}

int solution(int N) {
    int zeros = -1;
    int max_gap = 0;
    
    while (N > 0) {
        if ((N & 1) == 1) {// if the last bit is 1, the result of x & 1 is 1; otherwise, it is 0. This is a bitwise AND operation.
                zeros = 0;
            } 
        else if (zeros != -1) {
                zeros++;
        if (max_gap < zeros) {
                    max_gap = zeros;
                }
            }
        
        N = N >> 1;  // N = N >> 1; //= N/ 2^1
    }
    
    return max_gap;
}

