/******************************************************************************
Count the number of passing cars on the road. 
 count all possible (P,Q) =(0,1)
 for example A {0,1,0,1,1}
 We have five pairs of passing cars: (0, 1), (0, 3), (0, 4), (2, 3), (2, 4).
  so we return =>5
	
	
*******************************************************************************/


#include <iostream>
using namespace std;
#include <vector>
# include <set>
#include <unordered_map> 
int solution( vector<int> &A);
void printVec(vector<int> &A);
void printMap(unordered_map<int,int> &mymap);
int main()
{
    
    
    vector<int> A {0,1,0,1,1};
    int res=solution(A);
    std::cout << res << std::endl;
    return 0;
}


int solution(vector<int> &A)
{
    // vector<int> pre_sum(A.size(),0);
    vector<int> pre_sum;
    // printVec(A);
    int s=0;
    for(size_t i=0;i<A.size();i++)
    {
        s+=A[i];
        // pre_sum[i]=s;// if use declared vector A(N,0)
       pre_sum.push_back(s);
        
    }
    // printVec(pre_sum);
    int res=0;
    for(int i=A.size()-1;i>=0;i--)
    {
        if(A[i]==0)
        {
            res+=pre_sum[A.size()-1]-pre_sum[i];
            if (res>1e9) return -1;//1000,000,000 
        }
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
   
}
 
 //###############################################################3
void printMap(unordered_map<int,int> &mymap)
{
    std::cout << "mymap contains:\n";
    for (auto it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
}