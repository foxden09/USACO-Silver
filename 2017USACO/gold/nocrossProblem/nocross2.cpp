#include <iostream>
#include <algorithm> 
#include <cmath>
using namespace std;
#include<vector>
#define FOR(i, a, b) for(int i = a; i <= b; i++)

int main()
{
    freopen("nocross.in", "r", stdin);
    freopen("nocross.out", "w", stdout);
    int N; cin>>N;
    vector<int> l (N+1), r (N+1), dp(N+1);
    FOR(i, 1, N) cin>>l[i]; 
    FOR(i, 1, N) cin>>r[i]; 

    FOR(i, 1, N){ 
        int prev = 0;
    
        FOR(j, 1, N){
            if(abs(l[i]-r[j]) <= 4) { swap(prev, dp[j+1]); dp[j+1]++; } 
            else { prev = dp[j+1]; 
                   dp[j+1] = max(dp[j], dp[j+1]); }
        }
    }
    cout<<dp[N]<<endl;
}

