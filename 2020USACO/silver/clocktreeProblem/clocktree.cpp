#include <iostream>

using namespace::std;
#include <vector>
#define FOR(i, b) for(int i = 0; i < b; i++)
#define F0R(i, a, b) for(int i = a; i <= b; i++)
int N, A, B, full = 0;
bool found = 0;
vector<int> clocks;
vector<vector<int>> nbors;
//! if clock 12 that means all but one neighbor needs to be blocked
void dfs(int i){
    clocks[i]++; 
    if(clocks[i] == 12) full++; 
    /*if(clocks[i] == 12) {
        int blocked = 0;
        for(int nbor : nbors[i]) { if(clocks[nbor] == 12) blocked++; }
        if(blocked < nbors[i].size()-1) { clocks[i]--; return; }
        full++;  
    } */
    if(full == N || found == 1) { cout<<"HI"<<endl; found = 1; clocks[i]--; return; }

    /*int tot = 0;
    for(int nbor : nbors[i]) tot += 12 - clocks[nbor]; //cout<<tot<<" "<<clocks[i]<<" "<<12-clocks[i]<<endl;
    if(tot < 12 - clocks[i]) { clocks[i]--; return; }*/
    for(int nbor : nbors[i]) { if(clocks[nbor] < 12) dfs(nbor); }
    if(clocks[i] == 12) full--;
    clocks[i]--;
}

int main() {
    freopen("clocktree.in", "r", stdin);
    freopen("clocktree.out", "w", stdout);
    
    //feed in data
    cin>>N;
    clocks.resize(N+1); nbors.resize(N+1);
    FOR(i, N) cin>>clocks[i+1];
    FOR(i, N-1){
        cin>>A>>B;
        nbors[A].push_back(B); nbors[B].push_back(A);
    }

    //loop over starting points
    int ans = 0;
    F0R(i, 1, N){
        full = 0; found = 0;
        if(clocks[i] == 12) full = 1;
        for(int nbor : nbors[i]) { if(clocks[nbor] < 12) dfs(nbor); }
        if(found) ans++; 
    }
    cout<<ans<<endl;
}
