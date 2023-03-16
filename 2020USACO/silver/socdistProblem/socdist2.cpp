#include <iostream>
#include <algorithm>
using namespace::std;
#include <vector>
#include <cmath>
typedef unsigned long long ll;
typedef pair<ll, ll> mypair; 
#define FOR(i, b) for(ll i = 0; i < b; i++)
ll N, M; 

//see if D works
bool validate(int D, vector<mypair>& invals){
    ll gap = 0, cows = 0;
    FOR(i, M){
        //check if gap big enough
        ll width = invals[i].second - invals[i].first;
        if(i != 0) gap += invals[i].first - invals[i - 1].second;

        if(gap < D){    
            ll takes = min(width, D - gap);
            gap += takes;
            width -= takes;
            if(gap < D) continue;
        } 
        else gap = 0;

        //calc max cows can get from ith interval
        cows += width / D + 1;
        gap += width % D;
        
        if(cows >= N) return 1; //! N-1
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
    /*ll low = 1, high = invals.back().second - invals[0].first;

    while(low < high){
        int mid = (low + high + 1)/2;
        
        if(validate(mid, invals)) low = mid;
        else high = mid - 1;
    }*/
    cout<<validate(85, invals)<<endl;
}