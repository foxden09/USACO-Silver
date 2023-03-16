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
    vector<store> removed;
    int orig_num = -1;

    while(!stores.empty() && milks != 0){
        int gallons = min(milks, stores.back().second);
        my_money += gallons * stores.back().first;
        milks -= gallons;
        
        if(milks == 0){ 
            orig_num = stores.back().second; 
            stores.back().second -= gallons;
        }
        if(milks != 0 || stores.back().second == 0){
            removed.push_back(stores.back());
            stores.pop_back();
        }
    }
    if(practice){
        if(orig_num != -1) stores.back().second = orig_num;
        stores.insert(stores.end(), removed.rbegin(), removed.rend());
    }
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

    int cow_i = 0;
    while(!cows.empty()){
        //if all empty or if no other options left force other
        
        if(cows.empty()) break;
        if(rentals.empty()) rentals.push_back(-1); //!
        if(stores.empty()) stores.push_back({-1, -1});
        if(rentals.back() == -1 && stores.back().first == -1) break;

        //choose rental if more profitable
        if(rentals.back() >= calc_store(cows.front(), stores, 1)){   //! >= 
            max_money += rentals.back(); //cout<<"RENT "<<rentals.back()<<endl;
            rentals.pop_back();
            cows.erase(cows.begin());
            continue;
        }         

        //else if store profitable now, reverse order and use best cow
        while(!cows.empty() && !stores.empty()){
            int store_profit = calc_store(cows.back(), stores, 1); 
            if(rentals.back() <= store_profit){   //! <= 
                max_money += calc_store(cows.back(), stores, 0);
                //cout<<"STORE"<<" "<<store_profit<<" COW "<<cows.back()<<endl;
                cows.pop_back();
            }
            else break;
        }         
    } 
    cout<<max_money<<endl;
}
