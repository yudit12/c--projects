// /******************************************************************************
//  return how many fish stay a live 
//  A represent the fish size 
//  B the  moving direction 
//  0 represents a fish flowing upstream,
// 1 represents a fish flowing downstream.

// the biger fish eats the small one 

// for example :
// A {4,3,2,1,5};
// B {0,1,0,0,0};
// remind only 2 fish

// Initially all the fish are alive and all except fish number 1 are moving upstream.
// Fish number 1 meets fish number 2 and eats it, then it meets fish number 3 and eats it too.
// Finally, it meets fish number 4 and is eaten by it. The remaining two fish, number 0 and 4,
// never meet and therefore stay alive.
  

// *******************************************************************************/
// #include <iostream>
// #include <string>
// #include<vector>
// #include <algorithm>
// #include <set>
// #include <stack>
// using namespace std;


// class my_stack : public std::stack<int>
// {
//   public :
//     auto begin() { return c.begin(); }
//     auto end() { return c.end(); }
// };
// int solution(vector<int> &A, vector<int> &B);
// void printStack( my_stack &s);
// void printVec( vector<int> &A );

// int main()
// {
//     vector <int> A {4,3,2,1,5};
//     vector<int> B {0,1,0,0,0};
//     int res =solution(A,B);
//     std::cout << res << std::endl;
//     return 0;
// }




// int solution(vector<int> &A, vector<int> &B)
// {
//     int cnt=0;
//     my_stack myStack;
//     for (int i=0;i<A.size();i++)
//     {
//         if(B[i]==1)
//         {
//             myStack.push(A[i]);
//         }
//         else
//         {
//             while(!myStack.empty())
//             {
//                 if(myStack.top()<A[i]) myStack.pop();
//                 else break;
//             }
//             if (myStack.empty()) cnt++;
//         }
//     }
//     return cnt+myStack.size();
// }

// void printVec( vector<int> &A )
// {
//     for(auto val :A)
//     {
//         std::cout << val <<",";
//     }
//     std::cout << " " << std::endl;

// }

// void printStack( my_stack &s)
// {
//     std::vector<int> v(s.size());
//     std::copy(s.begin(), s.end(), v.begin() );
//     for (auto val : v)
//         std::cout << val << " ";
//     std::cout << "\n";
// }