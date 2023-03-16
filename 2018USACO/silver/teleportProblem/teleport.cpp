#include <iostream>
#include <algorithm>
using namespace::std;
#include <vector>
#include <string>
#define pb push_back
typedef long long ll;
#define FOR(i, b) for(int i = 0; i < b; i++)
#define F0R(i, a, b) for(int i = a; i <= b; i++)
struct chnge{ 
    ll ind; string kind; //index & type of change
    bool operator<(const chnge& rhs) const{ return ind < rhs.ind; } };  
int N, a, b, d, to0, ascend = 0, descend = 0;
ll rnge, max_dist = 0, max_save = 0, save = 0, dist;

int main() {
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);

    //feed in data
    cin>>N;
    vector<chnge> chnges;  //in slope
    FOR(i, N){
        cin>>a>>b;
        d = abs(b - a);      //default tract dist
        max_dist += d;       
        to0 = abs(a);        //dist to travel to 0 from a_i
        rnge = d - to0;  //+/- dist from b_i where we can profit from teleport
        if(rnge < 0) continue;

        chnges.pb({min(b-rnge, b+rnge), "begin"});
        chnges.pb({b, "peak"});
        chnges.pb({max(b-rnge, b+rnge), "end"});
    }
    sort(chnges.begin(), chnges.end());
    
    FOR(i, chnges.size() - 1){
        if(chnges[i].kind == "begin") ascend++;
        else if(chnges[i].kind == "end") descend--;           //same practically as ascend++
        if(chnges[i].kind == "peak") { descend++; ascend--; } //same practically as ascend-=2

        if(chnges[i+1].ind - chnges[i].ind == 0) continue;  //same index, only process last 
        dist = chnges[i+1].ind - chnges[i].ind; 

        save += dist * (ascend - descend);     //aka slope
        max_save = max(save, max_save);
    } 
    cout<<max_dist - max_save<<endl;
}



