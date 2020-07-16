/******************************************************************************
Find the minimal positive integer not occurring in a given sequence.
for example 
A  {1, 3, 6, 4, 1, 2}==> return 5
A {-1,-3}; ==> return 1
	
 good example of map 
https://www.geeksforgeeks.org/traversing-a-map-or-unordered_map-in-cpp-stl/ 
	
*******************************************************************************/


#include <iostream>
using namespace std;
#include <vector>
# include <set>
#include <unordered_map> 
int solution( vector<int> &A);
void printVec(vector<int> &A);
void printMap(unordered_map<int,int> &mymap);
int main()
{
    // vector<int> A  {1, 3, 6, 4, 1, 2};
     vector<int> A {-1,-3};
    //  vector<int> A {1,3,4};
    int res=solution(A);
    std::cout << res << std::endl;
    return 0;
}


int solution(vector<int> &A)
{
    // printVec(A);
    unordered_map<int, int> map;
 
    for (int i = 0; i < int(A.size()); i++) {
        if (A[i] > 0)
        {
            map[A[i]] = i;    
        }
    }
    
    for (int i = 1; i < int(map.size() + 1); i++)
    {
        if (map.find(i) == map.end()) return i;
        // std::cout << map.find(i)->first<<" "  <<map.find(i)->second<<  std::endl;
    }
    
    return map.size()+1;
    
   
    
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
void printMap(unordered_map<int,int> &mymap)
{
    std::cout << "mymap contains:\n";
    for (auto it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
}