// /******************************************************************************
// Compute number of distinct values in an array.

// for example 
// A  {2,1,1,2,3,1}; 
// return 3

// ******************************************************************************/
// #include <iostream>
// #include <string>
// #include<vector>
// #include <algorithm>
// #include <string.h>
// #include <errno.h>
// #include <set>
// using namespace std;

// int solution(vector<int> &A);
// void printVec( vector<int> &A );
// int main ()
// {
// //   vector<int> A {4,2,2,5,1,5,8};
//     vector<int> A {2,1,1,2,3,1};

    
//     int res=  solution(A) ;
//     std::cout << res << std::endl;

//   return 0; 
// }




// int solution(vector<int> &A)
// {
//     set<int> s;
//     for (auto i: A)
//     {
//         s.insert(i);
//     }
 
//  return int(s.size());
  
// }

// void printVec( vector<int> &A )
// {
//     for(auto val :A)
//     {
//         std::cout << val <<",";
//     }
//     std::cout << " " << std::endl;

// }