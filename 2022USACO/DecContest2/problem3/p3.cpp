#include <iostream>
#include <vector>

using namespace::std;
#define FOR(i, b) for(int i = 0; i < b; i++)
typedef vector<int> vint;

int rnge(int i, vint& r){
    return max(r[i], max(r[i-1], r[i+1]))-min(r[i], min(r[i+1], r[i-1]));
}

int main() {
    freopen("p3.in", "r", stdin);
    freopen("p3.out", "w", stdout);
    int N; cin>>N;
    vint r (N), btwn2, btwn3, isPlus (N-1); 
    isPlus[0] = true; r[0] = 1;
    FOR(i, N) for(int j = 0; j < N-i; j++){
        int rij; cin>>rij;
        if(j == 1) btwn2.push_back(rij);
        if(j == 2) btwn3.push_back(rij);
    }
    if(N > 1) r[1] = r[0]+btwn2[0]; //set first two

    for(int i = 1; i < N-1; i++){ //++ -- or +- -+
        if(!isPlus[i-1]){
            r[i+1] = r[i]-btwn2[i]; isPlus[i] = false;
            if(rnge(i, r) != btwn3[i-1]){
                r[i+1] = r[i]+btwn2[i]; 
                isPlus[i] = true;
            }
        }
        if(isPlus[i-1]){
            r[i+1] = r[i]+btwn2[i]; isPlus[i] = true;
            if(rnge(i, r) != btwn3[i-1]){
                r[i+1] = r[i]-btwn2[i]; 
                isPlus[i] = false;
            }
        }
    }
    FOR(i, N-1) cout<<r[i]<<" "; 
    cout<<r[N-1]<<endl;
}