#include <iostream>
#include<algorithm>
using namespace::std;
#include <vector>
#include <unordered_map> 
typedef vector<int> vint;
#define FOR(i, b) for(int i = 0; i < b; i++)
#define R_FOR(i, a) for(int i = a - 1; i >= 0; i--)

int main() {
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    unordered_map<char, int> to_beat = {{'H', 1}, {'P', 2}, {'S', 0}};   //farmer gesture -> winning Bessie gesture
    
    //feed in farmer's gesture
    int N; cin>>N;
    vector<char> gestures (N);
    FOR(i, N) cin>>gestures[i];

    //prefix sum (# of wins only choosing H P or S)
    vector<vint> pwin (N, vint(3));     //0 - H | 1 - P | 2 - S
    FOR(i, N){
        if(i != 0) pwin[i] = pwin[i-1];
        int win_gest = to_beat[gestures[i]];
        pwin[i][win_gest]++;
    }

    //loop through all possible changes
    vint pre_change (3), post_change (3);    //sum of elements bfore & after change
    int max_wins = -1; 

    FOR(i, N){
        pre_change = pwin[i];
        post_change = pwin[N - 1];
        FOR(j, 3) post_change[j] -= pwin[i][j];

        max_wins = max(max_wins, 
        *max_element(post_change.begin(), post_change.end()) 
        + *max_element(pre_change.begin(), pre_change.end()));
    }
    cout<<max_wins<<endl;
}