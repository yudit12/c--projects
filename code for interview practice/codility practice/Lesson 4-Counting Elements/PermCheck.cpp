/******************************************************************************

Check whether array A is a permutation -
sequence containing each element from 1 to N once, and only once.
for example 
A{ 4,1,3,2} -->  permutation return 1
A{4,3,2}--> not permutation return 0

*******************************************************************************/
#include <iostream>
using namespace std;
#include <vector>
# include <set>
int solution(vector<int> &A);
void printVec(vector<int> &A);
int main()
{
    vector<int> A {4,1,1,2};
    int res=solution(A);
    std::cout << res << std::endl;
    return 0;
}


int solution(vector<int> &A)
{
    // printVec(A);
    set<int> s;
    int maximum = 1;
    for (auto i: A)
    {
    // std::cout << i << std::endl;
    // std::cout <<"find(i)" <<*s.find(i) << std::endl;
    // std::cout <<"end()" <<*s.end() << std::endl;
    if (s.find(i) == s.end())
    {
        s.insert(i);
    }
    else
    {
        return false;
    }
        maximum = max(i, maximum);
    }
    // std::cout << "######" << std::endl;
    return (maximum == s.size());
  
}

void printVec(vector<int> &A)
{
    for (auto val :A)
    {
        std::cout << val << " ";
    }
     std::cout << '\n';
   
}
 
