#include <iostream>
#include <algorithm>
using namespace::std;
#include <set>
#include <vector>
#define FOR(i, b) for(int i = 0; i < b; i++)
int N, K, L; 
vector<int> cites;
multiset<int> space; 

//see if h index is possible
bool h_poss(int h){
    int i = upper_bound(cites.begin(), cites.end(), h) - cites.begin(), s; i--;
    int myL = 0, pprs =  N-i-1;

    while(i >= 0 && myL < L && myL + pprs < h){
        int dist = abs(h - cites[i]);

        if(dist > K) break;
        auto mys = space.lower_bound(dist); 
        if(mys == space.end()) { space.insert(K); s = K; }  //take a new portion
        else s = *mys;

        space.erase(s);  
        if(s - dist != 0) space.insert(s - dist);
        else myL++;

        pprs++; i--;
    }//! clear multiset
    return pprs >= h;
}


int main() {
    freopen("acowdemia.in", "r", stdin);
    freopen("acowdemia.out", "w", stdout);

    //feed in data
    cin>>N>>K>>L;
    cites.resize(N);
    FOR(i, N) cin>>cites[i];
    sort(cites.begin(), cites.end());

    //find highest h index
    cout<<h_poss(4);
    /*int low = 0, high = N; 
    while(low < high){
        int mid = (low + high + 1)/2;
        
        if(h_poss(mid)) low = mid;
        else high = mid - 1;
    }
    cout<<low<<endl;*/
}
