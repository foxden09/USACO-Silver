#include <iostream>
#include <algorithm>
using namespace::std;
#include <vector>
typedef unsigned long long ll;
typedef pair<ll, ll> mypair; 
#define FOR(i, b) for(ll i = 0; i < b; i++)
ll N, M; 

//see if D works
bool validate(int D, vector<mypair>& invals){
    ll pos = 0, cows = 0;

    FOR(i, M){
        if(pos <= invals[i].first) pos = invals[i].first;   //all in interval valid
        else if(pos > invals[i].second) continue;           //skip interval
        //else some in interval valid
    
        ll addcows = (invals[i].second - pos) / D + 1;
        cows += addcows;
        if(cows >= N) return 1;
        pos += addcows * D;
    }
    return 0;
}

 
int main() {
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);
    cin>>N>>M;

    //feed in and sort intervals
    vector<mypair> invals (M); 
    FOR(i, M) cin>>invals[i].first>>invals[i].second;
    sort(invals.begin(), invals.end());
    
    //find largest possible value of D
    ll low = 1, high = invals.back().second - invals[0].first;

    while(low < high){
        int mid = (low + high + 1)/2;
        
        if(validate(mid, invals)) low = mid;
        else high = mid - 1;
    }
    cout<<low<<endl;
}