/******************************************************************************
Calculate the values of counters after applying all alternating operations:
increase counter by 1; set value of all counters to current maximum.
for example A  {3,4,4,6,1,4,4}  N=5
 (0, 0, 1, 0, 0)
(0, 0, 1, 1, 0)
(0, 0, 1, 2, 0)
(2, 2, 2, 2, 2)
(3, 2, 2, 2, 2)
(3, 2, 2, 3, 2)
(3, 2, 2, 4, 2)

return ==>(3, 2, 2, 4, 2)

*******************************************************************************/
#include <iostream>
using namespace std;
#include <vector>
# include <set>
#include <map>
void printMap(map<int,int> &mymap);
vector<int> solution( int N,vector<int> &A);
void printVec(vector<int> &A);
int main()
{
    vector<int> A {3,4,4,6,1,4,4};
    vector<int> res=solution(5,A);
    printVec(res);
    // std::cout << res << std::endl;
    return 0;
}


vector<int> solution(int N,vector<int> &A)
{
    vector<int> res(N, 0);
    // printVec(res);
    int base = 0;
    int maximum = 0;
    for (int i = 0; i < int(A.size()); i++)
     {
        //  std::cout << A[i] - 1 << std::endl;
         if (A[i] != N + 1)
            {
            res[A[i] - 1] = max(base, res[A[i] - 1]) + 1;
            maximum = max(maximum, res[A[i] - 1]);
            // printVec(res);
            }
            else
            {
                base = maximum;
            }
    }
 
    for (int i = 0; i < N; i++)
    {
         if (res[i] < base)
         {
            res[i] = base;
        }
    }
     return res;
  
    
}



void printVec(vector<int> &A)
{
    for (auto val :A)
    {
        std::cout << val << " ";
    }
     std::cout << '\n';
   
}
 
