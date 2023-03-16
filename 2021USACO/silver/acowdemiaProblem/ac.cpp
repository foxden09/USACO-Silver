#include <iostream>
#include <algorithm>
using namespace::std;
#include <vector>
#define FOR(i, b) for(int i = 0; i < b; i++)
int N, K, L; 
vector<int> cites;

//see if h index is possible
bool h_poss(int h){
    int i = lower_bound(cites.begin(), cites.end(), h) - cites.begin(); i--;
    int myL = 0, pprs =  N-i-1, leftover = K;

    while(i >= 0 && myL < L){
        int dist = abs(h - cites[i]);
        if(dist > K) break;

        if(leftover > dist) leftover -= dist;
        else{
            dist -= leftover; 
            myL++; if(myL >= L && dist > 0) break; 
            leftover = K - dist; 
        }
        pprs++; i--;  
    }
    return pprs >= h;
}


int main() {
    //freopen("acowdemia.in", "r", stdin);
    //freopen("acowdemia.out", "w", stdout);

    //feed in data
    cin>>N>>K>>L;
    cites.resize(N);
    FOR(i, N) cin>>cites[i];
    sort(cites.begin(), cites.end());

    //find highest h index
    int low = 0, high = N; 
    h_poss(3);
    while(low < high){
        int mid = (low + high + 1)/2;

        if(h_poss(mid)) low = mid;
        else high = mid - 1;
    }
    cout<<low<<endl;
}
