#include <iostream>
#include <algorithm>
using namespace::std;
#include <vector>
#define FOR(i, b) for(int i = 0; i < b; i++)

int main() {
    freopen("lemonade.in", "r", stdin);
    freopen("lemonade.out", "w", stdout);

    //feed in & sort cow wait times
    int N; cin>>N;
    vector<int> waits (N); 
    FOR(i, N) cin>>waits[i];
    sort(waits.begin(), waits.end(), greater<int>());

    //simulate queueing up most patient cows first
    FOR(i, N){
        if(i > waits[i]){ 
            cout<<i<<endl;
            break;
        }
    }
}
