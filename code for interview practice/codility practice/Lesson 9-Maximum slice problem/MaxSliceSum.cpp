// /******************************************************************************
// Find a maximum sum of a compact subsequence of array elements.
// for example :
// A {3,2,-6,4,0}

// the function should return 5 because:

// (3, 4) is a slice of A that has sum 4,
// (2, 2) is a slice of A that has sum −6,
// (0, 1) is a slice of A that has sum 5,
// no other slice of A has sum greater than (0, 1).


// *******************************************************************************/
// #include <iostream>
// #include<vector>
// #include <unordered_map>
// #include <algorithm>
// using namespace std;

// void printVector(std::vector<int> &A);
// int solution(vector<int> &A);
// int main()
// {
//     // vector<int> A {3,2,-6,4,0}; 
//     vector<int> A {-2,1,1};
//     int res=solution(A);
//     std::cout << res << std::endl;
  
// }
// int solution(vector<int> &A)
// {
 
//     int sum=A[0], tmp=0;
//     for(int i=0;i<A.size();i++)
//     {
//         tmp+=A[i];
//         if(tmp>sum) sum =tmp;
//         if (tmp<0) tmp=0;
     
//     }
//     return sum ;

// }

// /*

// int solution(vector<int> &A)
// {
  
//   double max = *std::max_element(A.begin(), A.end());
    
//     if ( max < 0) {
//         return max;
//     }
    
//     long long int maxEnding = 0;
//     long long int maxSlice = 0;

//     // OK, it is a positive number, so use the pattern described in Lesson 9
//     const int N = A.size();
//     for (int i=0; i<N; i++) {
//         // Slice not allowed to be empty
//         maxEnding = std::max((long long int)0, maxEnding+A[i]);
//         maxSlice = std::max(maxSlice, maxEnding);
//     }
    
//     return maxSlice;
    

// }


// */










// void printVector(std::vector<int>  &A)
// {
//     for (int x : A)
//         cout << x << " ";
//     cout <<endl;
    
// }