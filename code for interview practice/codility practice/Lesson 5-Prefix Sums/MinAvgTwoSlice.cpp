// /******************************************************************************
// Find the minimal average of any slice containing at least two elements.
//  for example :
//  A {4,2,2,5,1,5,8}
//  contains the following example slices:

// slice (1, 2), whose average is (2 + 2) / 2 = 2;
// slice (3, 4), whose average is (5 + 1) / 2 = 3;
// slice (1, 4), whose average is (2 + 2 + 5 + 1) / 4 = 2.5.

//  return  starting position of the slice with the minimal average-->  here return 1


// *******************************************************************************/
// #include <iostream>
// #include <string>
// #include <stack> 
// #include<vector>
// using namespace std;

// int solution(vector<int> &A);
// void printVec( vector<int> &A );
// int main ()
// {
//     vector<int> A {4,2,2,5,1,5,8};
//     int res= solution(A) ;
//     std::cout << res << std::endl;

//   return 0; 
// }

// // int solution(vector<int> &A) {
// //      vector<int> pre_sum(A.size());
// //      int pre_s = 0;
    
// //      for (size_t i = 0; i < A.size(); i++) {
// //             pre_s += A[i];
// //             pre_sum[i] = pre_s;
// //         }
    
// //      int start = 0;
// //      int end = 1;
// //      int min_start = start;
// //      double min_avg = double(pre_sum[end] - pre_sum[start] + A[start]) / (end - start + 1);
    
// //      for (size_t i = 1; i < A.size(); i++)
// //      {
// //          double avg = double(pre_sum[i] - pre_sum[start] + A[start]) / (i - start + 1);
    
// //          if (avg < min_avg) {
// //                     min_avg = avg;
// //                     min_start = start;
// //                 }
    
// //          if (A[i] < min_avg) {
// //                     start = i;
// //                 }
    
// //         }
    
// //      return min_start;
// // }



// int solution(vector<int> &A)
// {
//     int N=A.size();
//     double min_avg_value = (A[0] + A[1])/2.; //  # The mininal average
//     int min_avg_pos = 0;     //# The begin position of the first slice with mininal average
//     for (int index=0; index<N-2;index++) 
//     {
//         //# Try the next 2-element slice
//         if((A[index] + A[index+1]) / 2. < min_avg_value)
//         {
//             min_avg_value = (A[index] + A[index+1]) / 2.;
//             min_avg_pos = index;
            
//         }
//         //# Try the next 3-element slice
//         if ((A[index] + A[index+1] + A[index+2]) / 3. < min_avg_value)
//         {
//             min_avg_value = (A[index] + A[index+1] + A[index+2]) / 3.;
//             min_avg_pos = index  ;
//         }
             
        
//     }
//     // # Try the last 2-element slice
//     if ((A[N-1]+A[N-2])/2. < min_avg_value)
//         // min_avg_value = (A[N-1]+A[N-2])/2.;
//         min_avg_pos = N-2;
//     return min_avg_pos;
    
// }





// void printVec( vector<int> &A )
// {
//     for(auto val :A)
//     {
//         std::cout << val <<",";
//     }
//     std::cout << " " << std::endl;

// }