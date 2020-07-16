// /******************************************************************************
// Compute number of integers divisible by k in range [a..b]==> complexity O(1)
// int A=1;
// int B=5;
// int K =2; 
// return 2

// *******************************************************************************/
// #include <iostream>
// #include <string>
// #include <stack> 
// #include<vector>

// #include <string.h>
// #include <errno.h>
// using namespace std;

// int solution(int A, int B, int K);
// void printVec( vector<int> &A );
// int main ()
// {
//     // vector<int> A {4,2,2,5,1,5,8};
//     int A=1;
//     int B=5;
//     int K =2;
//     // std::cout << 1/3 << std::endl;
//     int res= solution( A,  B,  K) ;
//     std::cout << res << std::endl;

//   return 0; 
// }

// // int solution(int A, int B, int K)
// // {

// //  if (A % K != 0) A = (A / K + 1) * K;

// //  if (B < A) return 0;

// //  return (B - A) / K + 1;
// // }

// int solution(int A, int B, int K)
// {
//     if(B < A || K <= 0)
//     {
//         // fprintf(stderr,"%s","Invalid input" );
//         printf ("Invalid input: %s\n",strerror(errno));
//         exit(1);
//     }
//     if (A%K==0)
//     {
//         return (B-A)/K+1;
//     }
//     else
//     {
//         return (B - (A - A%K))/K;   
//     }

// }



// void printVec( vector<int> &A )
// {
//     for(auto val :A)
//     {
//         std::cout << val <<",";
//     }
//     std::cout << " " << std::endl;

// }
