#include <iostream>

using namespace::std;
#include <vector>
#include <string>
#define pb push_back
#define FOR(i, b) for(int i = 0; i < b; i++)
#define F0R(i, a, b) for(int i = a; i <= b; i++)
int N, M, X, Y, A, B, happys = 0, is_happy = -1;
char want, C;
string cows; 
vector< vector<int> > roads;

void dfs(int i, int p){  //current cow, previous cow
    if(cows[i-1] == want) happys++;
    if(i == B) { is_happy = happys > 0; return; }
    for(int nbor : roads[i]){
        if(is_happy != -1) return;
        if(nbor != p) dfs(nbor, i);
    }
    if(cows[i-1] == want) happys--;
}

int main() {
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);

    //feed in data
    cin>>N>>M>>cows;
    roads.resize(N+1);
    FOR(i, N-1){
        cin>>X>>Y; 
        roads[X].pb(Y); roads[Y].pb(X); 
    }

    //answer query
    FOR(i, M){
        cin>>A>>B>>C;
        want = C;
        dfs(A, 0);
        cout<<is_happy<<endl;
        happys = 0; is_happy = -1;
    } cout<<endl;
}
