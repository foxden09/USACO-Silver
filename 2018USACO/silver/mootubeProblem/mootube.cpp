#include <iostream>
using namespace::std;
#include <vector>
#define FOR(i, b) for(int i = 0; i < b; i++)
#define F0R(i, a, b) for(int i = a; i <= b; i++)
struct edge{ int ind, r; };   //index of nbor & relevance
vector<vector<edge>> netwrk; 
int N, Q, p_i, q_i, r_i, k_i, v_i, rec;
 
void dfs(int i, int p){  //curr index, previous index
    for(edge nbor : netwrk[i]){
        if(nbor.ind == p || nbor.r < k_i) continue;
        rec++; 
        dfs(nbor.ind, i); 
    }
}

int main() {
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);

    //feed in data
    cin>>N>>Q;
    netwrk.resize(N+1);
    FOR(i, N-1){
        cin>>p_i>>q_i>>r_i;
        netwrk[p_i].push_back({q_i, r_i});
        netwrk[q_i].push_back({p_i, r_i});
    }

    //perform queries
    FOR(i, Q){
        rec = 0;
        cin>>k_i>>v_i;
        dfs(v_i, -1); 
        cout<<rec<<endl;
    }
}   
