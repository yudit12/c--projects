// /******************************************************************************
// Determine whether a triangle can be built from a given set of edges.
//  ( P,Q,R)  the conditions are: 
// A[P] + A[Q] > A[R],
// A[Q] + A[R] > A[P],
// A[R] + A[P] > A[Q].
//  for example :
//  A  {10,2,5,1,8,20}; return 1 because (0,2,4)
//  A {10,50,5,1} return 0

// ******************************************************************************/
// #include <iostream>
// #include <string>
// #include<vector>
// #include <algorithm>
// #include <string.h>
// #include <errno.h>
// #include <set>
// using namespace std;

// bool is_triangle(int64_t P, int64_t Q, int64_t R);
// int solution(vector<int> &A);
// void printVec( vector<int> &A );
// int main ()
// {
// // vector<int> A {4,2,2,5,1,5,8};
//     // vector<int> A {2,1,1,2,3,1};
//     vector<int> A {10,50,5,1};
    

    
//     int res=  solution(A) ;
//     std::cout << res << std::endl;

//   return 0; 
// }


// bool is_triangle(int64_t P, int64_t Q, int64_t R)
// {
//  return (P + Q > R) &&
//           (Q + R > P) &&
//           (R + P > Q);
// }

// int solution(vector<int> &A) {
 
//     if (A.size() < 3) return 0;
//     sort(A.begin(), A.end());
//     int res = 0;
//     for (int i = 0; i < int(A.size() - 2); i++)
//     {
//         if (is_triangle(A[i], A[i + 1], A[i + 2])) return 1;    
//     }
//     return 0;
// }



// void printVec( vector<int> &A )
// {
//     for(auto val :A)
//     {
//         std::cout << val <<",";
//     }
//     std::cout << " " << std::endl;

// }