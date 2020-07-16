/******************************************************************************

Rotate an array to the right by a K given number of steps]
for example A =[3, 8, 9, 7, 6] K=3

[3, 8, 9, 7, 6] -> [6, 3, 8, 9, 7]
    [6, 3, 8, 9, 7] -> [7, 6, 3, 8, 9]
    [7, 6, 3, 8, 9] -> [9, 7, 6, 3, 8]

*******************************************************************************/
#include <iostream>
using namespace std;
#include <vector>
#include <set>

void printVec(vector<int> &A);
vector<int> solution(vector<int> &A, int K);

int main()
{
    
    vector<int> A {3, 8, 9, 7, 6};
    
    vector<int> res=solution(A,3);
    std::cout << "before rotation" << std::endl;
    printVec(A);
    std::cout << "after K rotation " << std::endl;
    printVec(res);

    return 0;
}

vector<int> solution(vector<int> &A, int K) {
    // printVec(A);
    if (A.size() == 0) return A;
    K = K % A.size();
    if (K == 0) return A;
    
    vector<int> res(A.size());
    
    const int size1 = int(A.size() - K);
    
    for (int i = 0; i < size1; i++) {
        res[i + K] = A[i];
    }
    
    for (int i = size1; i < int(A.size()); i++) {
        res[i - size1] = A[i];
    }
    
    return res;
    
    
}


void printVec(vector<int> &A)
{
    for (auto val :A)
    {
        std::cout << val << " ";
    }
     std::cout << '\n';
    // for ( auto i=0; i<A.size(); i++){
    //     std::cout << i<<","<<A[i] << std::endl;
    // }
}

