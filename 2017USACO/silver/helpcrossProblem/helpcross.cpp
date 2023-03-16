#include <iostream>
#include <algorithm>
using namespace::std;
#include<queue>
#include<vector>
#define FOR(i, b) for(int i = 0; i < b; i++)

struct cow{
    int start, end;
    bool operator<(const cow& rhs) const{
        return end > rhs.end;
    }
};
bool cmpStart(const cow& lhs, const cow& rhs){
    return lhs.start > rhs.start;
}

int main() {
    freopen("helpcross.in", "r", stdin);
    freopen("helpcross.out", "w", stdout);
    int C, N;
    cin>>C>>N;
    int chicks[20001];
    vector<cow> cows(N);

    //feed in & sort chicken times 
    FOR(i, C) cin>>chicks[i];
    sort(chicks, chicks + C);

    //feed in & sort cow times by start
    FOR(i, N) cin>>cows[i].start>>cows[i].end;
    sort(cows.begin(), cows.end(), cmpStart);


    priority_queue<cow> waits; 
    int pair_count = 0;
    
    FOR(i, C){

        //enque all cows possible for chicken i
        while(!cows.empty() && cows.back().start <= chicks[i]){
            waits.push(cows.back());
            cows.pop_back();
        }

        //pair cow to chicken
        while(!waits.empty()){
            cow myCow = waits.top();
            waits.pop();
            if(myCow.end >= chicks[i]){
                pair_count++;
                break;
            }
        }
    }

    cout<<pair_count<<endl;
}