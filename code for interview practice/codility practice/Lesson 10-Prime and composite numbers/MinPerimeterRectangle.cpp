// /******************************************************************************
//  N is area of some rectangle.
//  the goal is to find the minimal perimeter of any rectangle whose area equals N
 
// For example, given integer N = 30, rectangles of area 30 are:

// (1, 30), with a perimeter of 62,
// (2, 15), with a perimeter of 34,
// (3, 10), with a perimeter of 26,
// (5, 6), with a perimeter of 22.

// the function will return 22


// *******************************************************************************/
// #include <iostream>
// #include<vector>
// #include <algorithm>
// #include <cmath>
// using namespace std;



// int solution(int N);

// int main()
// {
//     int N =30;
    
//     int res=solution(N);
//     std::cout << res << std::endl;
    
// }

// int solution(int N)
// {
//     int end = sqrt(N);
//     while(N%end!=0) end--;
    
//     std::cout << end+N/end << std::endl;
//     return 2*(end+N/end);
// }