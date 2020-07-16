// /******************************************************************************
// Compute the number of intersections in a sequence of discs.
//  here we will do the concept  of two line intersections
//  A {1,5,2,1,4,0}  A[i]= R (i,0)
//  1) create  array  of left point (i-R)
//     create array of right point (i-R)
// 2 ) sort the arrays 
// 3) move a longe each left point if equal or smaller(<=) the right point  ==> there is open disk 
//     if there all ready open disk  ad the num of them to the intresection val 
//     if left point  > then right point  close one disk  and move to the next val in right array 
 
//  when finsh  pass all val in left array it oky that   we didnt pass all right point
 
// ** good video explanation:
// https://www.youtube.com/watch?v=HV8tzIiidSw

// ******************************************************************************/
// #include <iostream>
// #include <string>
// #include<vector>
// #include <algorithm>
// #include <errno.h>
// #include <set>
// using namespace std;

// int solution(vector<int> &A);
// int main()
// {
//     vector<int> A {1,5,2,1,4,0};
//     int res = solution(A);
//     std::cout << res << std::endl;

//     return 0;
    
// }  


// int solution(vector<int> &A) {
//     // write your code in C++11
//     int N = A.size();
//     if (N <2)
//         return 0;
//     vector<long> left;// begin
//     vector<long> right;// end
//     for(int i=0; i<N; i++){
//         left.push_back(i-static_cast<long>(A[i]));// i-R
//         right.push_back(i+static_cast<long>(A[i]));//i+R
//     }
//     sort(left.begin(),left.end());
//     sort(right.begin(),right.end());
//     int res = 0;
//     int upper_index =0, lower_index=0;
//     for(upper_index =0; upper_index<N; upper_index++){
//         while(lower_index<N && left[lower_index]<= right[upper_index])
//             lower_index++;
//         res += lower_index-upper_index-1;
//         if (res >1e7)// 10,000,000
//             return -1;
//     }
//     return res;
// }
    

