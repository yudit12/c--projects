// /******************************************************************************
// Find the index S such that the leaders of the sequences
// A[0], A[1], ..., A[S] and A[S + 1], A[S + 2], ..., A[N - 1] are the same.

// for example A {4,3,4,4,4,2}
// we can find two equi leaders:

// 0, because sequences: (4) and (3, 4, 4, 4, 2) have the same leader, whose value is 4.
// 2, because sequences: (4, 3, 4) and (4, 4, 2) have the same leader, whose value is 4.
// The goal is to count the number of equi leaders.
// function should return 2

 

// *******************************************************************************/

// #include <iostream>
// #include <algorithm>
// #include<vector>
// #include <unordered_map>
// using namespace std;


// void printVec(vector<int> &A );
// int solution(vector<int> &A);
// void printMap(unordered_map<int,int> &mymap);
// int main()
// {
//     vector<int> A {4,3,4,4,4,2};
//     int res= solution(A);
//     std::cout << res << std::endl;
//     return 0;
// }

// int solution(vector<int> &A)
// {
//     int num=0,cnt=0;
//     for(int i=0; i< A.size(); i++){
//           if(cnt==0)
//           {
//             num=A[i];
//             cnt++;
//           }
//           else
//           {
//             if(A[i]==num) cnt++;
//             else cnt--;
//           }
//     }
//     int fre = count(A.begin(),A.end(),num);
//     // std::cout << fre << std::endl;
//     int cur = 0,res=0;
//     for(int i=0; i<A.size(); i++){
//           if(A[i]==num)
//             cur++;
//             if(2*cur>i+1 && (fre-cur)*2>A.size()-i-1)
//                 res++;
//     }
//     return res; 
    

// }

// void printVec( vector<int> &A )
// {
//     for(auto val :A)
//     {
//         std::cout << val <<",";
//     }
//     std::cout << " " << std::endl;

// }



// void printMap(unordered_map<int,int> &mymap)
// {
//     std::cout << "mymap contains:\n";
//     for (auto it=mymap.begin(); it!=mymap.end(); ++it)
//         std::cout << it->first << " => " << it->second << '\n';
// }















