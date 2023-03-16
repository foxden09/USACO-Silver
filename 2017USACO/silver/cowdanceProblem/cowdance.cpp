#include <iostream>

using namespace::std;
#include <vector>
#include <queue>

typedef vector<int> vint;
typedef priority_queue<int, vector<int>, greater<int>> pq;
#define FOR(i, b) for(int i = 0; i < b; i++)
int N, T_MAX;

//check if dance performance for K completes before T_MAX
bool validate(int K, vint &cow_dur){
    pq dance; 
    FOR(i, K) dance.push(cow_dur[i]);
    
    int mytime = 0, i = K;
    while(!dance.empty()){
        mytime = dance.top(); 
        if(mytime > T_MAX) return 0;
        dance.pop();

        if(i < N) dance.push(cow_dur[i] + mytime);
        i++;
    }
    return 1;
}

int main() {
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);

    //feed in data
    cin>>N>>T_MAX;
    vint cow_dur (N);
    FOR(i, N) cin>>cow_dur[i];

    //find smallest K
    int low = 1, high = N;
    while(low < high){
        int mid = (low + high)/2;

        if(validate(mid, cow_dur)) high = mid;
        else  low = mid + 1;
    }
    cout<<low<<endl;
}
