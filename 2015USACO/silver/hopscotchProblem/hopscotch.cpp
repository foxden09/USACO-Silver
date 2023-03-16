#include <iostream>
using namespace::std;
#include <vector>
#define FOR(i, a) for(int i = 0; i < a; i++)
typedef vector<long> vlong;

int main()
{
    freopen("hopscotch.in", "r", stdin);
    freopen("hopscotch.out", "w", stdout);
    int R, C, K;
    cin>>R>>C>>K;
    vector<vlong> arr (R, vlong (C));
    vector<vlong> dp (R, vlong (C));  //# of ways to get to square
    FOR(r, R){ FOR(c, C) cin>>arr[r][c]; }

    dp[0][0] = 1;
    FOR(r, R){   //loop thru all dp[r][c]
        FOR(c, C){  
            FOR(pr, r){    //find # ways to get to dp[r][c]  
                FOR(pc, c){
                    if(arr[pr][pc] == arr[r][c]) continue;
                    dp[r][c] += dp[pr][pc] % 1000000007;
                }
            }
        } 
    }
    cout<<dp[R-1][C-1] % 1000000007<<endl;
}
