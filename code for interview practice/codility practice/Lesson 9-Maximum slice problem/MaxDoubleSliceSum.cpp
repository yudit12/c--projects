/******************************************************************************

Find the maximal sum of any double slice..
A triplet (X, Y, Z), such that 0 ≤ X < Y < Z < N, is called a double slice.

The sum of double slice (X, Y, Z) is the total of A[X + 1] + A[X + 2] + ... + A[Y − 1] +
A[Y + 1] + A[Y + 2] + ... + A[Z − 1].

for example 
given A {3,2,6,-1,4,5,-1,2}; 
there is 
double slice (0, 3, 6), sum is 2 + 6 + 4 + 5 = 17,
double slice (0, 3, 7), sum is 2 + 6 + 4 + 5 − 1 = 16,
double slice (3, 4, 5), sum is 0.

 the function will return 17 



*******************************************************************************/
#include <iostream>
#include<vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

void printVector(std::vector<int> &A);
int solution(vector<int> &A);
int main()
{
    vector<int> A {3,2,6,-1,4,5,-1,2}; 
    // vector<int> A {3,2,-6,4,0}; 
    int res=solution(A);
    std::cout << res << std::endl;
  
}

int solution(vector<int> &A)
{
    printVector(A);
    vector<int> PosP(A.size()-1);
    vector<int> NegP(A.size()-1);
    int tmp=0;
    PosP[0]=0;
    for(int i=1; i<A.size()-1; i++)
    {
        tmp+= A[i];
        if(tmp<0) tmp=0;
        PosP[i]=tmp;
    }
    printVector(PosP);
    tmp =0;
    NegP[A.size()-2]=0;
    for(int i=A.size()-2; i>0; i--)
    {
        tmp+= A[i];
        if(tmp<0)tmp=0;
        NegP[i-1]=tmp;
        
    }
    printVector(NegP);
     int sum=0;
    for(int i =1; i< A.size()-1; i++)
    {
        if(PosP[i-1]+NegP[i]>sum)
            sum= PosP[i-1]+NegP[i];
            // std::cout << sum << std::endl;
    }
     return sum;
    
   

}




void printVector(std::vector<int>  &A)
{
    for (int x : A)
        cout << x << " ";
    cout <<endl;
    
}