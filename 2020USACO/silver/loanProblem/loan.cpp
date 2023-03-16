#include <iostream>
#include <iomanip>
using namespace::std;
#include <vector>
typedef long long ll;
#define FOR(i, b) for(int i = 0; i < b; i++)
ll N, K, M;

//simulates farmer's pay back rules
ll pay_back(ll X){
    ll Y = N, days = 0;
    while(days < K && Y > 0){
        ll inc = Y/X; 
        if(max(M, inc) == M) { 
            days += Y/M; 
            if(Y % M != 0) days++; 
            return days <= K;
        }

        ll nextdist =  Y - (inc-1) * X;
        days = nextdist / inc; 
        if(nextdist % inc != 0) days++; 
        Y -= nextdist + (nextdist % inc);
    }
    return Y <= 0 && days <= K;
}

int main() {
    freopen("loan.in", "r", stdin);
    freopen("loan.out", "w", stdout);
    cin>>N>>K>>M;

    //find largest possible X
    ll X = 1, best;
    for(ll jump = N/2; jump >= 1; jump /= 2){
        cout<<X<<endl;
        while(pay_back(X + jump)) X += jump; 
    }
    cout<<pay_back(29803)<<endl;
}