// /******************************************************************************
//  A string S consisting of N characters is called properly nested if
//  For example, given S = "(()(())())", 
//  the function should return 1 and given S = "())", 
//  the function should return 0, as explained above.
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
// int solution(string &S);
// void printStack( my_stack &s);
// void printVec( vector<int> &A );

// int main()
// {
//     string S ="(()(())())";
//     int res= solution(S);
//     std::cout << res << std::endl;
//     return 0;
// }

// int solution(string &S) {
//     // write your code in C++11
//     stack<char> myStack;
//     for(int i=0; i<S.size(); i++){
//         char ch = S[i];
//         switch(ch){
//          case '(': myStack.push(ch);break;
//          case ')': 
//             if(myStack.empty() || myStack.top()!='(')
//                 return 0;
//             else myStack.pop();
//             break;
//         }
//     }   
//     return myStack.empty()?1:0;
// }



// void printStack( my_stack &s)
// {
//     std::vector<int> v(s.size());
//     std::copy(s.begin(), s.end(), v.begin() );
//     for (auto val : v)
//         std::cout << val << " ";
//     std::cout << "\n";
// }