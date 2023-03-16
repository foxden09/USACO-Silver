#include <iostream>
#include <algorithm>
using namespace::std;
#include <vector>
#define FOR(i, b) for(int i = 0; i < b; i++)
typedef vector<pair<int,int>> vpint;
int N, K;

int main() {
    freopen("berries.in", "r", stdin);
    freopen("berries.out", "w", stdout);

    //feed in trees
    cin>>N>>K;
    vector<int> trees (N);
    FOR(i, N) cin>>trees[i];
    sort(trees.begin(), trees.end(), greater<int> ());

    //find factors (baskets -> berries) for each tree
    vector<vpint> all_factors;
    int max_bess = 0;   //!SET DEFAULT MAX
    FOR(i, N){
        vpint factors; 
        int bskt_q = 1;       //! K + 1? basket quantity

        while(bskt_q <= min(trees[i], K - 1)){
            int berries = (int) trees[i] / bskt_q; 
            if(berries <= max_bess) continue;       //!<= or <
            
            factors.push_back({bskt_q, berries});
            bskt_q++;
        }

        all_factors.push_back(factors);
        //!case where biggest tree < K DO I STOP BEFORE? probs not
    }
    
    for(vpint er: all_factors){
        for(auto sd : er){
            cout<<"# of baskets: "<<sd.first<<" berries per: "<<sd.second<<endl;
        }
        cout<<endl;
    }
}
/*

*/