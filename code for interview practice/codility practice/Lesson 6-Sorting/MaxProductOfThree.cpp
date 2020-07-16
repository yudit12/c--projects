// /******************************************************************************
// Maximze A[P] * A[Q] * A[R] for any triplet (P, Q, R).

// for example 
// A {-3,1,2,-2,5,6}; 
// return 60

// the idea to sort the array and get the larger val there positive value multiply the 3 last one ( from the right)
// or the 2 negitive with one positive from the left

// *******************************************************************************/
// #include <iostream>
// #include <string>
// #include<vector>
// #include <algorithm>
// #include <string.h>
// #include <errno.h>
// using namespace std;

// int solution(vector<int> &A);
// void printVec( vector<int> &A );
// int main ()
// {
// //   vector<int> A {4,2,2,5,1,5,8};
//     vector<int> A {-3,1,2,-2,5,6};

    
//     int res=  solution(A) ;
//     std::cout << res << std::endl;

//   return 0; 
// }

// // int solution(vector<int> &A)
// // {

// //     sort(A.begin(), A.end());
// //     int N = int(A.size());
// //     int m1 = A[N - 1] * A[N- 2] * A[N - 3];
// //     if ((A[N - 1] < 0) || (A[0] > 0)) return m1;
    
// //     int m2 = A[0] * A[1] * A[N- 1];
    
// //     return max(m1, m2);
// // }



// int solution(vector<int> &A) {
//     sort(A.begin(), A.end());
//     int N= A.size();
//     long left = A[0]*A[1]*A[N-1];
//     long right = A[N-1]*A[N-2]*A[N-3];
//     int res = (left > right) ? left : right;
//     return res;
//     // return left > right ? left : right;
//     // return MAX(left, right);
// }

// void printVec( vector<int> &A )
// {
//     for(auto val :A)
//     {
//         std::cout << val <<",";
//     }
//     std::cout << " " << std::endl;

// }