#include <iostream>
#include <algorithm>

using namespace::std;
#include <vector>
#define REP(i, a, b) for(int i = a; i < b; i++)
typedef vector<int> vint;
typedef vector<bool> vbool;

void calcPSum(vint &pSum, vbool &crosswalks){
    REP(i, 0, crosswalks.size()){
        pSum[i+1] = pSum[i] + crosswalks[i];
    }
}

int main() {
    freopen("maxcross.in", "r", stdin); 
    freopen("maxcross.out", "w", stdout); 
    int N, K, B;
    cin>>N>>K>>B;
    vbool crosswalks(N, 0);  

    int badCross;
    REP(i, 0, B){
        cin>>badCross;
        crosswalks[badCross] = 1;
    }

    vint pSum(N);
    calcPSum(pSum, crosswalks);

    int minCrosses = K;
    REP(i, 0, N-K){
        int runningBad = pSum[i+K] - pSum[i];
        minCrosses = min(minCrosses, runningBad);
    }
    cout<<minCrosses<<endl;
}