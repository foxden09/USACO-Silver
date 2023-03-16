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
    sort(waits.begin(), waits.end());

    //queue up most patient cows first
    vector<int> myqueue; 
    FOR(i, N){
        int mywait = waits.back();
        waits.pop_back();
        if(myqueue.size() <= mywait) myqueue.push_back(mywait);
        else break;
    }
    cout<<myqueue.size()<<endl;
}
