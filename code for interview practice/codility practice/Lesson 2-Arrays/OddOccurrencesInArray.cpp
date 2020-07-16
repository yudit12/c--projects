4/******************************************************************************

Find value that occurs in odd number of elements.
 for example  A ={3,7,3} --> return 7

*******************************************************************************/
#include <iostream>
using namespace std;
#include <vector>
#include <set>
#include<bits/stdc++.h> 
int solution(vector<int> &A);
int main()
{
    
//       // declaration of set container 
//     set<int> myset{1, 2, 3, 4, 5}; 
      
//     // using begin() to print set 
//     for (auto it=myset.begin(); it != myset.end(); ++it) 
//         cout << ' ' << *it; 
//   std::cout <<"\n"<< std::endl;
//     for (auto i: myset)
//         cout << ' ' << i; 
    

        
        
 //   vector<int> A {1, 2, 5, 4, 6, 8, 9, 2, 1, 4, 5, 8, 9}; 
    vector<int> A {9,3,9,3,9,7,9};
    int res=solution(A);
    std::cout << res << std::endl;

    return 0;
}
// vector<int> A {9,3,9,3,9,7,9};
// O^2 solution 
int solution(vector<int> &A) {
    set<int> s;
     
    for (auto i: A) {
    if (s.find(i) == s.end()) {
            // std::cout << *s.find(i) << std::endl;
            // std::cout << *s.end() << std::endl;
            s.insert(i);
            // std::cout << "####" << std::endl;
        } else {
            // std::cout << *s.find(i) << std::endl;
            // std::cout << *s.end() << std::endl;
            s.erase(i);
            // std::cout << "GGG" << std::endl;
        }
    
   
    }
   
    
    return *s.begin();
}

/*

use XOR opertion : 
n ^ n = 0

n ^ 0 = n

*/
int solution(vector<int> &A) {
	 int odd1 = 0;
	//  for(int i=0; i < A.size(); i++) 
	//  {
	//     odd1 ^= A[i];
	//  }
	//#### alternative writing ####///
	for (auto val : A)
	{
		odd1^=val;
	}
	 return odd1;
}




