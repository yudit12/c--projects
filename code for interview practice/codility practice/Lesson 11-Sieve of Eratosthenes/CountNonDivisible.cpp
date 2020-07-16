// /******************************************************************************

//  CountNonDivisible

// Calculate the number of elements of an array that are not divisors of each element.
// for example :
// A {3,1,2,3,6}
// For the following elements:

// A[0] = 3, the non-divisors are: 2, 6,
// A[1] = 1, the non-divisors are: 3, 2, 3, 6,
// A[2] = 2, the non-divisors are: 3, 3, 6,
// A[3] = 3, the non-divisors are: 2, 6,
// A[4] = 6, there aren't any non-divisors.

// the func wil return -->  [2, 4, 3, 2, 0]
// *******************************************************************************/
// #include <iostream>
// #include<vector>
// #include <map>
// #include <algorithm>
// #include <set>
// using namespace std;

// void printVector (vector < int >&A);
// vector<int> solution(vector<int> &A);
// int main()
// {
//     vector<int>  A {3,1,2,3,6};
//     vector<int> res= solution(A);
//     printVector(res);
//     return 0;
// }

// vector<int> solution(vector<int> &A)
// {
//     // vector<int>  res {3,1,2,3,6};
//     int N = int(A.size());
//     map<int, int> divisors;
//     for ( auto i: A) {
// 		divisors[i]++;
// 	}
// 	 // Go through and calculate the number of divisors that are missing
// 	// We know that there are at least N nondivisors present if none
// 	vector<int> track((2*N)+1, N);
//     printVector(track);
//     // Generate divisors list
// 	// This is the Sieve of Eratosthenes method
//     for (const auto &d: divisors) {
// 		for (int i=1; i*d.first <= 2*N; i++) {
// 			track[i*d.first] -= d.second;
// 		}
// 	}
	
// 	// Look up nondivisors
//     vector<int> nondivisors(N, 0);
// 	for (int i=0; i<N; i++) {
//         nondivisors[i] = track[A[i]];
// 	}
    
//     return nondivisors;
// }




// void printVector (vector < int >&A)
// {
//     for (int x:A)
//         cout << x << " ";
//       cout << endl;

// }


