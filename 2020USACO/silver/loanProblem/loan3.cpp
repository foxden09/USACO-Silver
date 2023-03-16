#include <iostream>
using namespace::std;
#include <vector>
typedef long long ll;
#define FOR(i, b) for(int i = 0; i < b; i++)
ll N, K, M;

//check if we can pay back
bool pay_back(ll X, ll leftover, ll days){
    ll Y = leftover/X;

    if(days <= 0 || leftover <= 0) return leftover <= 0;    //cant give anymore / gave all already
    if(M >= Y) return days * M >= leftover;                 //check if rest of days we give M its possible

    ll leastY = Y*X;                                        //smallest leftover possible with same Y
    ll tillnext = (leftover - leastY)/Y + 1;                //how many days till new Y
    ll gives = min(tillnext, days);
    return pay_back(X, leftover - gives*Y, days - gives);
}

int main() {
    freopen("loan.in", "r", stdin);
    freopen("loan.out", "w", stdout);
    cin>>N>>K>>M;

    //find largest possible X
    ll low = 1, high = N;
    
    while(low < high){
        ll mid = (low + high + 1)/2;

        if(pay_back(mid, N, K))  low = mid;
        else  high = mid - 1;
    }
    cout<<low<<endl;
}

