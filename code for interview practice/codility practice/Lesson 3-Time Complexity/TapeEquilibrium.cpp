/******************************************************************************

Minimize the value |(A[0] + ... + A[P-1]) - (A[P] + ... + A[N-1])|
for example 
A={3,1,2,4,3}


P = 1, difference = |3 − 10| = 7
P = 2, difference = |4 − 9| = 5
P = 3, difference = |6 − 7| = 1
P = 4, difference = |10 − 3| = 7

==> min difference =1
*******************************************************************************/
#include <iostream>
using namespace std;
#include <vector>
#include <limits>
void printVec(vector<int> &A);

int solution(vector<int> &A);
int main()
{
    vector<int> A {3,1,2,4,3};
    int res =solution(A);
    std::cout << res << std::endl;
    return 0;
}


int solution(vector<int> &A)
{
    // printVec(A);
    vector<int> pre_sum;
    int s = 0;
    for (auto i: A)
    {
        s += i;
        pre_sum.push_back(s);
    }
    // printVec(pre_sum);
    
    int min_abs_diff = numeric_limits<int>::max();
    // int min_abs_diff= pre_sum[pre_sum.size()-1];
    
    for (size_t i = 1; i < pre_sum.size(); i++)
    {
        
        int abs_diff = abs(pre_sum[i - 1] * 2 - pre_sum[pre_sum.size() - 1]);
        // std::cout << abs_diff << std::endl;
        min_abs_diff = min(min_abs_diff, abs_diff);
    }
    
    return min_abs_diff;
}
 
 
 
 
 
 
void printVec(vector<int> &A)
{
    for (auto val :A)
    {
        std::cout << val << " ";
    }
     std::cout << '\n';
   
}
 
