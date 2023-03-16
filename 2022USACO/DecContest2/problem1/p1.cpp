#include <iostream>
#include <vector>
#include <tuple>

using namespace::std;
#define FOR(i, b) for(int i = 0; i < b; i++)
#define rz resize
#define pb push_back
typedef long long ll;
typedef vector<ll> vint;
typedef vector<vint> v2d;
vint hay, sums;
v2d nbors;
vector<tuple<ll, ll, ll>> ord;
ll N, avg = 0;

void sum(int i, int par){
    sums[i] = hay[i]-avg;
    for(int n : nbors[i]){
        if(n == par) continue;
        sum(n, i);
        sums[i] += sums[n];
    }
}

void distr(int i, int par){ //distribute hay bales to child subtrees
    for(int n : nbors[i]){ //child -> node
        if(n == par) continue;
        if(sums[n] >= 0) distr(n, i); 
        if(sums[n] > 0) ord.pb({n+1, i+1, sums[n]});
    }   
    for(int n : nbors[i]){ //node -> child
        if(n == par) continue;
        if(sums[n] < 0){ ord.pb({i+1, n+1, -sums[n]});
                         distr(n, i); }
    }   
}

int main() {
   // freopen("p1.in", "r", stdin);
    //freopen("p1.out", "w", stdout);
    cin>>N;
    hay.rz(N); nbors.rz(N); sums.rz(N);
    FOR(i, N){ cin>>hay[i]; avg += hay[i]; }
    avg /= N;
    FOR(i, N-1){
        ll a, b; cin>>a>>b; a--; b--;
        nbors[a].pb(b); nbors[b].pb(a);
    }
    sum(0, 0);
    distr(0, 0);
    cout<<ord.size()<<endl;
    for(auto [a, b, c] : ord) cout<<a<<" "<<b<<" "<<c<<endl;
}
