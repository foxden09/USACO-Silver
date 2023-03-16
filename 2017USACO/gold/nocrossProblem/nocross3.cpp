#include <iostream>
#include <algorithm> 
#include <cmath>
using namespace std;
#include<vector>
#define FOR(i, b) for(int i = 0; i < b; i++)

int main()
{
    freopen("nocross.in", "r", stdin);
    freopen("nocross.out", "w", stdout);
    int N; cin>>N;
    vector<int> l (N), r (N), rmap(N+1), dp(N+1);
    FOR(i, N) cin>>l[i]; 
    FOR(i, N) { cin>>r[i]; rmap[r[i]] = i; }

    FOR(i, N){ 
        int ind = 100000, prev = 0;
    
        for(int j = ind; j < N; j++){
            if(abs(l[i]-r[j]) <= 4) { swap(prev, dp[j+1]); dp[j+1]++; } 
            else { prev = max(prev, dp[j+1]); dp[j+1] = max(dp[j], dp[j+1]); }
            cout<<"i: "<<i<<" j: "<<j<<endl;
            for(int k = 1; k <= N; k++) cout<<dp[k]<<endl;  cout<<endl;
        }
    }
    
    cout<<dp[N]<<endl;
}