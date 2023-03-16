#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <string>
#include <cmath>

using namespace::std;
#define FOR(i, b) for(int i = 0; i < b; i++)
typedef long long ll;
typedef vector<ll> vint;
typedef vector<vint> v2d;
vint hay; 
struct dat{ ll ix;
    bool operator<(const dat& rhs)const{ return hay[ix] < hay[rhs.ix]; }}; 

int main(){
    freopen("p1.in", "r", stdin);
    freopen("p1.out", "w", stdout);
    ll N; cin>>N;
    ll avg = 0;
    hay.resize(N);
    FOR(i, N){ cin>>hay[i]; avg += hay[i]; } avg /= N;

    vector<set<ll>> nbors(N); 
    FOR(i, N-1){
        ll a, b; cin>>a>>b; a--; b--;
        nbors[a].insert(b);
        nbors[b].insert(a); 
    }
   // FOR(i, N) cout<<hay[i]<<" "; cout<<endl;
    vint debt (N), visited (N); 
    priority_queue<dat> q, q1; 
    FOR(i, N){ if(nbors[i].size() == 1){ q.push(dat{i}); } }
    vector<string> s, e; 

    while(!q.empty()){
        ll i = q.top().ix; q.pop(); 
        if(visited[i] || hay[i] == avg) continue; visited[i] = true;

        ll par = *nbors[i].begin(), diff = abs(hay[i]-avg);
        if(hay[i] < avg){ //needs more
            hay[par] -= diff;
            hay[i] += diff;

            string ord = ""+to_string(par+1)+" "+to_string(i+1)+" "+to_string(diff); 
            if(hay[par] < 0) e.push_back(ord);
            else s.push_back(ord);
        }
        else if(hay[i] > avg){
            hay[par] += diff;
            hay[i] -= diff;

            string ord = ""+to_string(i+1)+" "+to_string(par+1)+" "+to_string(diff); 
            s.push_back(ord);
        }
        nbors[par].erase(i);
        if(hay[par] != avg) q1.push(dat{par});
        if(q.empty()) q = q1;
    }

    std::cout<<s.size()+e.size()<<endl;
    for(string me : s) std::cout<<me<<endl;
    for(int i = e.size()-1; i >= 0; i--) std::cout<<e[i]<<endl;
}