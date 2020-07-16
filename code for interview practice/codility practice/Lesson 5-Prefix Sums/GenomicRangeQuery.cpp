/******************************************************************************
Find the minimal nucleotide from a range of sequence DNA
for example :
S = CAGCCTA
 A C G T = [1,2 ,3, 4] Respectively
p[2,5,0] Q[4,5,6]
range of 4-2 includde GCC  impact of  3 and 2 min 2
range of 5 include T impact of 4 min 4
range of 0-6 include all impact  0f 1-4 min 1

so return [ 2,4,1] 
	
*******************************************************************************/


#include <iostream>
using namespace std;
#include <vector>
# include <set>
#include <unordered_map> 
#include <string>
vector<int> solution(string &S, vector<int> &P, vector<int> &Q);
void printVec(vector<int> &A);
void printMap(unordered_map<int,int> &mymap);
int main()
{
    
    
    string S ="CAGCCTA";
    vector<int> P {2,5,0};
    vector<int> Q {4,5,6};
    vector<int> res=solution(S,P,Q);
    printVec(res);
    return 0;
}


vector<int> solution(string &S, vector<int> &P, vector<int> &Q)
{
    vector<int> pre_sum_A;
    vector<int> pre_sum_C;
    vector<int> pre_sum_G;
    
    int cnt_A = 0;
    int cnt_C = 0;
    int cnt_G = 0;
    
    for (size_t i = 0; i < S.size(); i++)
    {
        if (S[i] == 'A') cnt_A++;
        else if (S[i] == 'C') cnt_C++;
        else if (S[i] == 'G') cnt_G++;
        pre_sum_A.push_back(cnt_A);
        pre_sum_C.push_back(cnt_C);
        pre_sum_G.push_back(cnt_G);
        
    }
    // printVec(pre_sum_A);
    // printVec(pre_sum_C);
    // printVec( pre_sum_G);
    
    vector<int> result(P.size());
    for (int i = 0; i < int(P.size()); i++)
    {
        int A = (S[P[i]] == 'A') ? 1 : 0;
        int C = (S[P[i]] == 'C') ? 1 : 0;
        int G = (S[P[i]] == 'G') ? 1 : 0;
        if (pre_sum_A[Q[i]] - pre_sum_A[P[i]] + A > 0) result[i] = 1;
        else if (pre_sum_C[Q[i]] - pre_sum_C[P[i]] + C > 0) result[i] = 2;
        else if (pre_sum_G[Q[i]] - pre_sum_G[P[i]] + G > 0) result[i] = 3;
        else result[i] = 4;
    }
    
    return result;
    
   
    
    
   
    
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