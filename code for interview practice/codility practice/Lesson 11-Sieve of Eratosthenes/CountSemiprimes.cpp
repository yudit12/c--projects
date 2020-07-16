// /******************************************************************************
// CountSemiprimes
// Count the semiprime numbers in the given range [a..b]
// semiprime is a natural number that is the product of two 
// (not necessarily distinct) prime numbers

// for example :
// prime = 2, 3, 5, 7, 11 and 13... (positive integer X  divisors: 1 and X)
// semiprimes are 4, 6, 9, 10, 14, 15, 21, 22, 25, 26...
// N=26
// vector<int> P {1,4,16};
// vector<int> Q {26,10,20};
// The number of semiprimes within each of these ranges is as follows:

// (1, 26) is 10,
// (4, 10) is 4,
// (16, 20) is 0.
//  the func will return [10,4,0]

// *******************************************************************************/
// #include <iostream>
// #include<vector>
// #include <algorithm>
// #include <set>
// using namespace std;

// void printVector (vector < int >&A);
// vector<int> solution(int N, vector<int> &P, vector<int> &Q);
// int main()
// {
//     vector<int> P {1,4,16};
//     vector<int> Q {26,10,20};
//     vector<int> res= solution(26,P,Q);
//     printVector(res);
//     return 0;
// }



// vector<int> solution(int N, vector<int> &P, vector<int> &Q)
// {
//     vector<int> prime;
//     vector<int> semiprime;
//     set<int> mySet;
//     mySet.insert(2);
//     prime.push_back(2);
//     for(int i=3; i<= N; i++)
//     {
//         int j;
//         for(j=0; j<int(prime.size());j++){
//             if(i%prime[j]==0){
//                 if(mySet.count(i/prime[j])!=0)
//                     semiprime.push_back(i);
//                 break;
//             }
//         }
//         if (j==int(prime.size()))
//         {
//             prime.push_back(i);
//             mySet.insert(i);
//         }
//     }
//     // printVector(semiprime);
//     vector<int> res;
//     for(int i=0; i<int(P.size()); i++)
//     {
//         int begin = P[i];
//         int end = Q[i];
//         vector<int>::iterator lower,upper;
//         lower = lower_bound(semiprime.begin(),semiprime.end(),begin);
//         upper=upper_bound(semiprime.begin(),semiprime.end(),end);
//         // std::cout <<"upper="<< (upper-semiprime.begin())<< " lower=" <<  (lower-semiprime.begin()) << std::endl;
//         res.push_back(upper-lower);
//     }
    
//     return res;
    

// }


// void printVector (vector < int >&A)
// {
//     for (int x:A)
//         cout << x << " ";
//       cout << endl;

// }


