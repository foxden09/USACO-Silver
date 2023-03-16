#include <iostream>

using namespace::std;
#include <vector>
#define FOR(i, b) for(int i = 0; i < b; i++)
typedef vector<int> vint;
vint father;

//find nodes root father
int finds(int node){
    if(father[node] != node){
        father[node] = finds(father[node]);
    }
    return father[node];
}

//unite fathers
void unites(int pas1, int pas2){
    int root1 = finds(pas1);
    int root2 = finds(pas2);
    father[root1] = root2;
}


int main() {
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    int N, M; 
    cin>>N>>M;

    //init disjoint set
    FOR(i, N) father.push_back(i);

    //feed in data & create disjoint set
    FOR(i, M){
        int pas1, pas2; char diet; 
        cin>>diet>>pas1>>pas2;
        pas1--; pas2--;

        unites(pas1, pas2);
    }

    //count # of root fathers & calc ans
    cout<<1;
    FOR(i, N){
        if(father[i] == i) cout<<0;
    }
    cout<<endl;
}
