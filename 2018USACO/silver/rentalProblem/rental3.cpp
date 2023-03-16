#include <iostream>
#include <algorithm>
using namespace::std;
#include <vector>
#define FOR(i, b) for(int i = 0; i < b; i++)
#define RFOR(i, b) for(int i = b; i > 0; i--)
typedef long long ll;
typedef vector<int> vint;
typedef vector<ll> vll;
int N, M, R;

struct store{
    int rate, gall;
    bool operator<(const store& rhs)const { return rate < rhs.rate; }
};

//create profit arr of selling cow to store
void calc_store(vector<store>& stores, vll& profit, vint& cows){
    int s = 0, c = 0; 
    while(c < N && s < M){
        int mincap = min(stores[s].gall, cows[c]);      
        profit[c + 1] += (ll) stores[s].rate * mincap; 

        cows[c] -= mincap;      
        stores[s].gall -= mincap;

        if(cows[c] == 0) c++;          //go to next cow
        if(stores[s].gall == 0) s++;   //go to next store
    }
    FOR(i, N) profit[i + 1] += profit[i];
}


int main() {
    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);
    cin>>N>>M>>R;

    //feed in data  
    vint cows (N), rents (R);
    vector<store> stores(M);   //p cents per gallon | max gallon

    FOR(i, N) cin>>cows[i];
    FOR(i, M) cin>>stores[i].gall>>stores[i].rate;
    FOR(i, R) cin>>rents[i];

    sort(cows.rbegin(), cows.rend());
    sort(stores.rbegin(), stores.rend());
    sort(rents.rbegin(), rents.rend());

    //give milkiest cow to store
    vll profit (N + 1);  
    calc_store(stores, profit, cows);

    //greedily choose whether rent or store is better for cow i
    ll max_sell = profit[N], r = 0;
 
    RFOR(i, N){
        int st = profit[i] - profit[i-1];   //profit from sell to (st)ore
    
        if(rents[r] > st){
            max_sell += rents[r] - st;
            r++;
        }
        if(r == R) break;
    }
    cout<<max_sell<<endl;
}
