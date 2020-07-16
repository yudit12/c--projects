/******************************************************************************

Find missing element in a given permutation.
 for example given A{ 2,1,3,5} ---> missing num is 4
 
 !!! shouldnt use dividtion -> bad for performance!!!!! 

*******************************************************************************/
#include <iostream>
using namespace std;
#include <vector>
#include <set>
#include <math.h>     

int solution(vector<int> &A);
int main()
{
    vector<int> A {2,3,1,5};
    int res =solution(A);
    std::cout <<res  << std::endl;
    return 0;
}


int solution(vector<int> &A) {
int res = 0;

for (int i = 0; i < int(A.size()); i++)
{
    res += (i + 1 - A[i]);
}

res += int(A.size() + 1);

return res;
}







// /* correct answer but  bad performance -60% */
// int solution(vector<int> &A)
// {
//     int current_sum=0;
//     double actual_sum= A.size()+1;
//     actual_sum = actual_sum*(actual_sum+1)/2;
//     // std::cout <<actual_sum  << std::endl;
//     for (auto val : A)
//     {
//         current_sum+=val;    
//     }
//     std::cout <<current_sum  << std::endl;
//     int missing= actual_sum - current_sum;
//     return missing;
    
// }
