// /******************************************************************************
// check if string  properly nested

//  string s= "{[()()]}" is properly nested --> return 1
//  but "([)()]" is not --> return 0
// string S consists only of the following characters: "(", "{", "[", "]", "}" and/or ")"

// *******************************************************************************/
// #include <iostream>
// #include <string>
// #include<vector>
// #include <algorithm>
// #include <set>
// #include <stack>
// using namespace std;


// class my_stack : public std::stack<char>
// {
//   public :
//     auto begin() { return c.begin(); }
//     auto end() { return c.end(); }
// };
// int solution(string &S);
// void printStack( my_stack &s);


// int main()
// {
//     string s ="{[([])]}";
//     // string s="[)";
//     int res=solution(s);
//     std::cout << res << std::endl;
//     return 0;
// }


// int solution(string &S)

// {
//     my_stack myStack;
//     for(int i=0; i<S.size(); i++){
//         // printStack(myStack);
//         char ch = S[i];
//         switch(ch){
//          case '(': myStack.push(ch);break;
//          case '[': myStack.push(ch);break;
//          case '{': myStack.push(ch);break;
//          case ')': 
//             if(myStack.empty() || myStack.top()!='(') return 0;
//             else myStack.pop();
//             break;
//         case ']': 
//             if(myStack.empty() || myStack.top()!='[') return 0;
//             else myStack.pop();
//             break;
//         case '}': 
//             if(myStack.empty() || myStack.top()!='{')  return 0;
//             else myStack.pop();
//             break;
//         }
//     }
    
//     return myStack.empty()?1:0;

// }

// void printStack( my_stack &s)
// {
//     std::vector<char> v(s.size());
//     std::copy(s.begin(), s.end(), v.begin() );
//     for (auto val : v)
//         std::cout << val << " ";
//     std::cout << "\n";
// }