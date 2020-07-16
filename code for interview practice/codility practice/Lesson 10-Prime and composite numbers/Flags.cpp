// /******************************************************************************

// Find the maximum number of flags that can be set on mountain peaks.

// for example given 
// vector < int >A {1,5,3,4,3,4,1,2,3,4,6,2};
// has exactly four peaks: elements 1, 3, 5 and 10.

// two flags, you can set them on peaks 1 and 5;
// three flags, you can set them on peaks 1, 5 and 10;
// four flags, you can set only three flags, on peaks 1, 5 and 10.
// You can therefore set a maximum of three flags in this case.  return --> 3

// *******************************************************************************/
// #include <iostream>
// #include<vector>
// #include <algorithm>
// #include <cmath>
// using namespace std;


// vector<int> next_peak(vector < int >&A);
// vector<int> create_peaks(vector < int >&A);
// int flag(vector < int >&A);
// int solution (vector < int >&A);
// void printVector (vector < int >&A);

// int main()
// {
//     vector < int >A {1,5,3,4,3,4,1,2,3,4,6,2};
//     int res =solution(A);
//     std::cout <<res  << std::endl;
//     // vector < int >  B=next_peak(A);
//     // printVector(B);
// }

// int solution (vector < int >&A)
// {
//     // printVector(A);
//      int result=flag(A);
//      return result;
// }



// vector<int> create_peaks(vector < int >&A)
// {
    
//     int N =int(A.size());
//     vector < int > peaks (N,0);
//     for (int i=1; i<N;i++)
//     {
//         if( A[i]>max(A[i-1],A[i+1]))
//         {
//             peaks[i]=1;
//         }
//     }
//     return peaks;
// }


// vector<int> next_peak(vector < int >&A)
// {
//     int N =int(A.size());
//     vector < int >peaks=create_peaks(A);
//     // printVector(peaks);
//     vector < int > next (N,0);
//     next[N-1]=-1;
//     // printVector(next);
    
//     for (int i=N-2; i>=0;i--)
//     {
//         // std::cout << A[i] << std::endl;
//         if (peaks[i]==1) next[i]=i;
//         else next[i]=next[i+1];
        
//     }
//     // printVector(next);
//     return next;
// }

// int flag(vector < int >&A)
// {
//     int N=int(A.size());
//     vector<int> next= next_peak(A);
//     // printVector(next);
//     int i=1;
//     int result=0;
//     while((i-1)*i<=N){
//         int pos=0;
//         int num=0;
//         while(pos<N and num<i)
//         {
//             pos=next[pos];
//             if (pos==-1) break;
//             num++;
//             pos+=i;
//         }
//         result= max(result,num);
//         i++;
//     }
//     return result;
 
// }

// void printVector (vector < int >&A)
// {
// for (int x:A)
//     cout << x << " ";
//   cout << endl;

// }