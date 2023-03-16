#include <iostream>
#include <algorithm>
using namespace::std;
#include <vector>
#define FOR(i, a, b) for(int i = a; i < b; i++)
typedef pair<int, int> coor;
typedef vector<coor> myvec; 

bool cmp_coor(const coor& lhs, const coor& rhs){
    if(lhs.first == rhs.first) return lhs.second > rhs.second;
    return lhs.first < rhs.first; 
}

int main() {
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);
    int N; cin>>N;

    //convert peaks to base intervals 
    int x, y;
    myvec bases, merged;    
    FOR(i, 0, N){
        cin>>x>>y;
        bases.push_back({x - y, x + y});
    }
    sort(bases.begin(), bases.end(), cmp_coor); 

    //merge base intervals
    merged.push_back(bases[0]);
    FOR(i, 1, N){
        if(bases[i].second <= merged.back().second) continue;   //contained within 
        merged.push_back(bases[i]);
    }

    cout<<merged.size()<<endl;  //count visible mountains
}
