// /******************************************************************************
//  positive integer D is a factor of a positive integer N if there exists an integer M such that N = D * M.
// For example, 6 is a factor of 24, because M = 4 satisfies the above condition (24 = 6 * 4).

// For example, given N = 24, the function should return 8,
// because 24 has 8 factors, namely 1, 2, 3, 4, 6, 8, 12, 24. There are no other factors of 24.

// *******************************************************************************/
// #include <iostream>
// #include<vector>
// #include <algorithm>
// #include <cmath>
// using namespace std;



// int solution(int N);
// int main()
// {
//     int N =24;
//     int res = solution(N);
//     std::cout << res << std::endl;
//     return 0;
// }


// int solution(int N)
// {
//     int count=0;
//     for(int i=1; i<sqrt(N);i++)
//         if(N%i==0)
//         {
//              count++;
//         }
           
//     int t = sqrt(N);
   
//     if(t*t==N)
//         return 2*count+1;
//     return 2*count;
// }

// /*

// // correct but not efficient 
// int solution(int N)
// {
//     std::cout << N << std::endl;
//     int count=0;
//     for(int i=1;i<=N;i++)
//     {
//       if(N%i==0)count++; 
//     }
//     std::cout << count << std::endl;
// }
//  */










