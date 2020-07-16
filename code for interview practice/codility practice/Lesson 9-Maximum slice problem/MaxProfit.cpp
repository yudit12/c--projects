// /******************************************************************************
// Given a log of stock prices compute the maximum possible earning.
// for example :
// given A {23171,21011,21123,21366,21013,21367}
// function should return 356 (because A[5] − A[1] = 21367 − 21011)

// *******************************************************************************/



// #include <iostream>
// #include<vector>
// #include <unordered_map>
// using namespace std;


// void printVec( vector<int> &A );
// int solution(vector<int> &A);
// int main()
// {
  
//   vector<int> A {23171,21011,21123,21366,21013,21367};
//   int res =solution(A);
//   std::cout << res<<std::endl;
//   return 0;  
// }

// int solution(vector<int> &A)
// {
//     if (A.size() == 0) return 0;
//     // printVec(A);
//     int min_val = A[0];
//     vector<int> vmin(A.size());
//     for (size_t i = 0; i < A.size(); i++)
//     {
//         min_val = min(min_val, A[i]);        
//         vmin[i] = min_val;
//     }
    
//     vector<int> vmax(A.size());
//     int max_val = A[int(A.size()) - 1];
//     for (int i = int(A.size()) - 1; i >= 0; i--)
//     {
//         max_val = max(max_val, A[i]);
//         vmax[i] = max_val;
//     }
    
//     int max_profit = 0;
//     for (size_t i = 0; i < A.size(); i++) {
//         max_profit = max(vmax[i] - vmin[i], max_profit);
//     }
    
//     return max_profit; 
   
// }




// void printVec( vector<int> &A )
// {
//     for(auto val :A)
//     {
//         std::cout << val <<",";
//     }
//     std::cout << " " << std::endl;

// }

