#include <iostream>

using namespace::std;
#include <vector>
typedef vector<int> vint;
#define FOR(i, b) for(int i = 0; i < b; i++)
#define F0R(i, a, b) for(int i = a; i <= b; i++)

int main() {
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);
    int T, A, B;
    cin>>T>>A>>B;
    if(B < A) swap(A, B);

    vint dp (T+1);
    FOR(i, B) dp[i] = A * (i / A); //set base values b4 B

    for(int i = B; i <= T; i++){  //find best fill for i
        dp[i] = max(dp[i-A] + A, dp[i-B] + B);
    }

    int max_fill = dp[T];
    for(int i = T; i >= A; i--){  //consider water
        int pre = dp[i]/2, post = dp[T - pre];
        max_fill = max(max_fill, pre + post);
        if(max_fill == T) break;
    }
    cout<<max_fill<<endl;
}

