#include <iostream>
#include <vector>

using namespace::std;
#define FOR(i, b) for(int i = 0; i < b; i++)
const int maxn = 5000005;
int maxp_mod4[4] = {2, 1, 2, 3}, min_turns[maxn] = {0, 1};
bool comp[maxn];

int main() {
    //freopen("p2.in", "r", stdin);
    //freopen("p2.out", "w", stdout);
    for(int p = 2; p < maxn; p++){ //sieve of erthanos
        if(!comp[p]){
            for(int n = p; n < maxn; n+=p) comp[n] = true;
            maxp_mod4[p%4] = p;
        }
        min_turns[p] = (p-maxp_mod4[p%4])/2+1;
    }

    int T; cin>>T;
    vector<bool> winner (T); //0-John 1-Nhoj
    FOR(t, T){  
        int N, c, ans = 1e9; cin>>N;
        FOR(i, N){
            cin>>c;
            if(min_turns[c]/2 < ans/2){
                ans = min_turns[c];
                winner[t] = c%4==0; 
            }
        }
        if(!(ans & 1)) cout<<"Farmer Nhoj"<<endl;
        else cout<<"Farmer John"<<endl;
    }
}