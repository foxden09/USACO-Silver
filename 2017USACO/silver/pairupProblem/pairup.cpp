#include <iostream>
#include <algorithm>
using namespace::std;
#include <deque>

typedef long long ll;
#define FOR(i, b) for(int i = 0; i < b; i++)
int N, i1, i2;
ll mintime = 0;


struct cow{  
    int num, milk;  
    bool operator<(const cow& rhs)const { return milk < rhs.milk; }
};

void cmpcow(cow& cow1, cow& cow2, deque<cow>& cows){
    mintime = max(mintime, (ll) cow1.milk + cow2.milk);
    if(cows.size() == 1) { cows.pop_back(); return; }

    int minnum = min(cow1.num, cow2.num);
    cow1.num -=  minnum;
    cow2.num -=  minnum;

    if(cow1.num == 0) cows.pop_front();
    if(cow2.num == 0) cows.pop_back(); 
}


int main() {
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);

    //feed in data
    cin>>N;
    deque<cow> cows (N);       
    FOR(i, N) cin>>cows[i].num>>cows[i].milk;
    sort(cows.begin(), cows.end());

    //pair cows & find min milk time
    while(!cows.empty()){
        cmpcow(cows.front(), cows.back(), cows);
    }
    cout<<mintime<<endl;
} 
