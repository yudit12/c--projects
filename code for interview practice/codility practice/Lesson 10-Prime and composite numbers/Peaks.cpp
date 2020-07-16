// /******************************************************************************
//  A peak is an array element which is larger than its neighbors. More precisely,
//  it is an index P such that 0 < P < N − 1,  A[P − 1] < A[P] and A[P] > A[P + 1].
// for example 
// A {1,2,3,4,3,4,1,2,3,4,6,2};
// has exactly three peaks  at i= 3, 5, 10.

// Array A can be divided into blocks as follows:

// one block (1, 2, 3, 4, 3, 4, 1, 2, 3, 4, 6, 2).
// This block contains three peaks.
// two blocks (1, 2, 3, 4, 3, 4) and (1, 2, 3, 4, 6, 2). Every block has a peak.
// three blocks (1, 2, 3, 4), (3, 4, 1, 2), (3, 4, 6, 2). Every block has a peak. Notice in
// However, array A cannot be divided into four blocks,
// (1, 2, 3), (4, 3, 4), (1, 2, 3) and (4, 6, 2), 
// because the (1, 2, 3) blocks do not contain a peak. 

// *******************************************************************************/
// #include <iostream>
// #include<vector>
// #include <algorithm>
// #include <cmath>
// using namespace std;


// void printVector (vector < int >&A);
// int solution (vector < int >&A);


// int main ()
// {
//   vector < int >A {1,2,3,4,3,4,1,2,3,4,6,2};
//     // vector < int >A {1,2,1,2,1};


//   int res = solution (A);
//   std::cout << res << std::endl;

// }


// int solution (vector < int >&A)
// {
//     printVector(A);
//     int s = int(A.size());
//     // std::cout << s << std::endl;
//     if (s < 3) return 0;
    
//     int i = 1;
//     vector<int> factors;
    
//     while (i * i < s) {
//     if (s % i == 0) {
//             factors.push_back(i);
//             factors.push_back(s / i);
//         }
//         i++;
//     }
    
//     if (i * i == s) {
//         factors.push_back(i);    
//     }
//     printVector(factors);
    
//     sort(factors.begin(), factors.end());
//     printVector(factors);
    
//     vector<int> peaks(s, 0);
//     int peak_num = 0;
//     for (int j = 1; j < s - 1; j++)
//     {
//         if ((A[j] > A[j - 1]) && (A[j] > A[j + 1]))
//         {
//             peaks[j] = 1;
//             peak_num++;
//         }
//     }
//     printVector(peaks);
//     // std::cout << peak_num << std::endl;
//     if (peak_num == 0) return 0;
//     if (peak_num == 1) return 1;
//     vector<int> pre_sum_peaks;
//     int ss = 0;
//     for (auto j: peaks)
//     {
//         ss += j;
//         pre_sum_peaks.push_back(ss);
//     }
//     printVector(pre_sum_peaks);
//     for (int j = 1; j < int(factors.size()); j++)
//     {
//         bool no_peak = false;
//         for (int k = 0; k < s; k += factors[j]) {
//         int start_s = (k == 0) ? 0 : pre_sum_peaks[k - 1];
//         if (pre_sum_peaks[k + factors[j] - 1] - start_s == 0)
//         {
//             no_peak = true;
//             break;    
//         }
//     }
//         if (!no_peak) return s / factors[j];            
//     }
//     return 0;
 

// }


// /*

// int solution(vector<int> &A) {
//     // write your code in C++14 (g++ 6.2.0)
//     int N = A.size();
//     if (N < 3) return 0;
    
//     //find peaks
//     //max number of peaks (N+1)/2
//     int peaks[(N+1)/2];
//     int p = 0;
//     peaks[p] = -1; //mark end
    
//     for (int i = 1; i < N-1; i++) {
//         if (A[i] > A[i-1] && A[i] > A[i+1]) {
//             peaks[p] = i;
//             ++p;
//             peaks[p] = -1;//mark end
//             ++i; // next number cannot be a peak
//         }
//     }
//     if (peaks[0] == -1) {
//         return 0; // no peaks
//     }
//     if (peaks[0] != -1 && peaks[1] == -1) {
//         return 1; // only one peak
//     }
    
//     for (int k = 2 ; k <=N/2; k++ ) { //k is number of element in each block
//         if (N%k != 0) {
//             continue;
//         }
        
//         int peaks_in_block = -1; //find peak in each N/k block
//         for(p = 0; peaks[p] > -1; p++) {
//             if ((peaks[p])/k > peaks_in_block + 1) {
//                 break;// peak missing in next block
//             } else if (peaks[p]/k == peaks_in_block + 1) {
//                 ++peaks_in_block; //found at least a peak in next block.
//             }
//         }
//         if (peaks_in_block + 1 == N/k) { // all blocks has at least one peak
//             return N/k;
//         }
//     }
//     return 1; // if we are here array at least has one peak.
// }

// */


// void printVector (vector < int >&A)
// {
// for (int x:A)
//     cout << x << " ";
//   cout << endl;

// }
