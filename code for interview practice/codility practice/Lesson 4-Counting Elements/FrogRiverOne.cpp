/******************************************************************************
	Find the earliest time when a frog can jump to the other side of a river.
	for example 
	A {1,3,1,4,2,3,5,4} X=5 ==> return index 6
	
	
*******************************************************************************/
#include <iostream>
using namespace std;
#include <vector>
# include <set>
int solution( int X,vector<int> &A);
void printVec(vector<int> &A);
int main()
{
    vector<int> A {1,3,1,4,2,3,5,4};
    int res=solution(5,A);
    std::cout << res << std::endl;
    return 0;
}


int solution(int X,vector<int> &A)
{
    // printVec(A);
    set<int> s;
    for (size_t i = 0; i < A.size(); i++)
    {
        s.insert(A[i]);
        if (s.size() == X) return i;
    }
    return -1;
   
    
}




void printVec(vector<int> &A)
{
    for (auto val :A)
    {
        std::cout << val << " ";
    }
     std::cout << '\n';
   
}
 
 //###############################################################3
void printMap(map<int,int> &mymap)
{
    std::cout << "mymap contains:\n";
    for (auto it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
}