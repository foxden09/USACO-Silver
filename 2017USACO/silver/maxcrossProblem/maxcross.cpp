#include <iostream>
#include <algorithm>

using namespace::std;
#include <vector>
#define REP(i, a, b) for(int i = a; i < b; i++)
using vint = vector<int>;
using vbool = vector<bool>;

int N, K, B;

//calculates prefix sums
void calcPSum(vint &pSum, vbool &crosswalks){
    REP(i, 0, crosswalks.size()){
        pSum[i+1] = pSum[i] + crosswalks[i];
    }
}

int main() {
    freopen("maxcross.in", "r", stdin); 
    freopen("maxcross.out", "w", stdout); 
    cin>>N>>K>>B;
    vbool crosswalks(N, 0);  //0 - ok || 1 - not ok
    
    //mark where bad crosses are
    int badCross;
    REP(i, 0, B){
        cin>>badCross;
        crosswalks[badCross-1] = 1;
    }

    //create prefix sum vector
    vint pSum(N+1);
    calcPSum(pSum, crosswalks);

    //check every subset of K length in crosswalks to find one w/ minimum bad crosses
    int minCrosses = K;
    REP(i, 0, N-K+1){
        int runningBad = pSum[i+K] - pSum[i];
        minCrosses = min(minCrosses, runningBad);
    }
    cout<<minCrosses<<endl;
}