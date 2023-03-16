#include <iostream>
#include <climits>
#include <iomanip> 
#include <algorithm>
#include <cmath>
using namespace::std;
#include <vector>
typedef long long ll;
typedef pair<ll, ll> mypair; 
#define FOR(i, b) for(int i = 0; i < b; i++)

int main() {
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);
    int N, M; cin>>N>>M;

    //feed in and sort intervals
    vector<mypair> invals (M); 
    FOR(i, M) cin>>invals[i].first>>invals[i].second;
    sort(invals.begin(), invals.end());
 
    //fit to interval with lower bound
    double jump = (double) (invals[M-1].second - invals[0].first) / (N - 1);
    double my_i = invals[0].first;

    ll max_d = LLONG_MAX, prevs = 0;
    FOR(i, N){
        mypair pair_i = {0, (ll) round(my_i)};
        auto closest = lower_bound(invals.begin(), invals.end(), pair_i);
        int fitted = max(closest->first, pair_i.second);
       
        if(closest->first == closest->second) invals.erase(closest);     //visited
        else closest->first++;
    
        //std::cout << std::fixed << std::setprecision(3) << my_i;
        cout<<" "<<fitted<<endl;
        my_i += jump;
        
        if(i == 0) { prevs = fitted; continue; }
        max_d = min(max_d, fitted - prevs);
        prevs = fitted;
    };
    for(mypair sss : invals) cout<<sss.first<<" "<<sss.second<<endl;
    cout<<max_d<<endl;
}

//! lower boudn  check prev
//! lower bound no greater than
//!round last to last
//! if N < M