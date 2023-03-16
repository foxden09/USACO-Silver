#include <iostream>
#include<algorithm>

using namespace::std;
#include<vector>
#define REP(i, a, b) for(int i = a; i < b; i++)
#define ll unsigned long long

struct Reststop{
    int x_i, c_i;
    bool operator<(const Reststop& rhs) const{ return c_i > rhs.c_i; }
};

int L, N, rf, rb; 

int main() {
    freopen("reststops.in", "r", stdin); 
    freopen("reststops.out", "w", stdout); 
    cin>>L>>N>>rf>>rb;  
    vector<Reststop> stops (N), tastyStops(N);
    vector<int> maxTasty, locateTasty; //what is the tastiest stop and for how long on trail is it tastiest
    
    //feed in stops
    REP(i, 0, N){
        cin>>stops[i].x_i>>stops[i].c_i;
    }
    tastyStops = stops;
    sort(tastyStops.begin(), tastyStops.end());

    //reverse index sorted tastiness array
    int meters = 0;
    REP(i, 0, N){
        if(meters >= L) break;
        if(meters < tastyStops[i].x_i){
            maxTasty.push_back(tastyStops[i].c_i);
            locateTasty.push_back(tastyStops[i].x_i - meters);
            meters = tastyStops[i].x_i;
        }
    }
    
    //simulate bessie eating at tastiest stops
    ll maxTaste = 0;
    REP(i, 0, maxTasty.size()){
        ll dist = locateTasty[i];
        ll johnTime = dist * rf;
        ll bessTime = dist * rb;
        maxTaste += (johnTime - bessTime) * (ll) maxTasty[i]; 
    }
    
    cout<<maxTaste<<endl;
}