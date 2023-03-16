#include <iostream>
#include <algorithm>
using namespace::std;
#include <string>
#include <vector>
typedef pair<int, int> myp; 
#define FOR(i, b) for(int i = 0; i < b; i++)
#define F0R(i, a, b) for(int i = a; i < b; i++)

int main() {
    //freopen("paint.in", "r", stdin);
    //freopen("paint.out", "w", stdout);
    
    //feed in data
    string fence; 
    int N, Q, a, b, pend; 
    cin>>N>>Q>>fence; 
    fence.append(" ");
    
    //mark groups
    vector<bool> visited(N);
    vector<myp> grps; 
    FOR(i, N){
        if(visited[i]) continue;
        F0R(j, i, N){
            if(fence[j] == fence[i]) { visited[j] = 1; pend = j; }
            else if(fence[j] < fence[i]) break;
        }
        grps.push_back({i, pend});
    }

    //perform queries
    FOR(i, Q){
        int counts = 0;    
        int ans = grps.size(); 
        cin>>a>>b; a--; b--;  //if(i != 1) continue; 
        //int ind = lower_bound(grps.begin(), grps.end(), myp{a, -1}) - grps.begin(); 
        F0R(j, 0, grps.size()){
           // cout<<grps[j].first<<" "<<grps[j].second<<" "<<endl;
            if(grps[j].first >= a && grps[j].second <= b) ans--;  //cout<<counts<<endl;
            if(grps[j].first < a && grps[j].second > b) ans++;
            if(grps[j].first > b) break; 
        }
        cout<<ans<<endl;
    }
}