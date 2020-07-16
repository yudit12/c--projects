// /******************************************************************************
// Find an index of an array such that its value occurs at more than half of indices in the array.
//  returns index of any element of array A in which the dominator of A occurs.
//  The function should return −1 if array A does not have a dominator.
// for example:
// A {3,4,3,2,3,-1,3,3}
// may return 0, 2, 4, 6 or 7, as explained above.
// our return 7
 

// *******************************************************************************/

// #include <iostream>
// #include<vector>
// #include <unordered_map>
// using namespace std;


// void printVec(vector<int> &A );
// int solution(vector<int> &A);
// void printMap(unordered_map<int,int> &mymap);
// int main()
// {
//     vector<int> A {3,4,3,2,3,-1,3,3};
//     int res= solution(A);
//     std::cout << res << std::endl;
//     return 0;
// }

// int solution(vector<int> &A)
// {
//     unordered_map<int, int> um;
//     for(size_t i=0;i<A.size();i++)
//     {
//         if (um.find(A[i])!=um.end())
//         {
//          um[A[i]]++;
//         }
//         else
//         {
//          um[A[i]]=1;
//         }
//         if(um[A[i]]>A.size()/2) return i;
    
//   printMap(um); 
//     // std::cout << um.find(i)->first<<"->"<< um[i] << std::endl; 
//     }
    

//     return -1;

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















