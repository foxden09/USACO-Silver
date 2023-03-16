#include <iostream>
#include <algorithm>

using namespace::std;
#include <vector>
#define FOR(i, b) for(int i = 0; i < b; i++)
typedef pair<int, int> store;
typedef long long ll;

int N, M, R;

//! bug -1 if store back -1 return -1
//calculates profits from selling milk to store
int calc_store(int milks, vector<store> &stores, bool practice){
    int my_money = 0; 
    vector<store> copy_store = stores; 

    while(!copy_store.empty() && milks != 0){
        int gallons = min(milks, copy_store.back().second);
        my_money += gallons * copy_store.back().first;
        milks -= gallons;
        
        if(milks == 0) copy_store.back().second -= gallons;
        if(milks != 0 || copy_store.back().second == 0) copy_store.pop_back();
    }
    if(!practice) stores = copy_store; 
    return my_money;
}

int main() {
    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);
    cin>>N>>M>>R;
    
    //feed in data & sort   
    vector<int> cows (N), rentals (R);   
    vector<store> stores (M);   

    FOR(i, N) cin>>cows[i];
    FOR(i, M) cin>>stores[i].second>>stores[i].first;
    FOR(i, R) cin>>rentals[i];

    sort(cows.begin(), cows.end());
    sort(stores.begin(), stores.end());
    sort(rentals.begin(), rentals.end());
    
    //decide best fate for each cow
    ll max_money = 0;

    FOR(i, N){
        //if all empty or if no other options left force other
        if(rentals.empty() && stores.empty()) break;
        if(cows.empty()) break;
        if(rentals.empty()) rentals.push_back(-1); //!
        if(stores.empty()) stores.push_back({-1, -1});

        //choose rental if more profitable
        if(rentals.back() >= calc_store(cows.back(), stores, 1)){   //! >= 
            max_money += rentals.back(); cout<<"RENT "<<rentals.back()<<endl;
            rentals.pop_back();
            continue;
        }         

        //else if store profitable now, reverse order and use best cow
        while(!cows.empty() && !stores.empty()){
            int store_profit = calc_store(cows.back(), stores, 1); 
            if(rentals.back() <= store_profit){   //! <= 
                max_money += calc_store(cows.back(), stores, 0);
                cout<<"STORE"<<" "<<store_profit<<" COW "<<cows.back()<<endl;
                cows.pop_back();
            }
            else break;
        }         
    } 
    cout<<max_money<<endl;

}
