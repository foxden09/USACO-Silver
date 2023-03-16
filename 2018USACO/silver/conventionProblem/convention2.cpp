#include <iostream>
#include <algorithm>
using namespace::std;
#include <vector>
#include <queue>
#define FOR(i, b) for(int i = 0; i < b; i++)

struct cow{
    int t_start, t_len, senior;
    bool operator<(const cow& rhs) const{
        return senior > rhs.senior;
    }
};
bool cmpStart(const cow& lhs, const cow& rhs){
    return lhs.t_start > rhs.t_start; 
}

int main() {
    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);
    int N;  
    cin>>N;

    //feed in cows & sort by start time
    vector<cow> cows (N);
    FOR(i, N){
        cin>>cows[i].t_start>>cows[i].t_len;
        cows[i].senior = i;
    }
    sort(cows.begin(), cows.end(), cmpStart);

    //simulate waiting
    priority_queue<cow> qCow;
    int max_wait = 0;
    int curr_t = cows.back().t_start + cows.back().t_len;

    while(!cows.empty()){ 

        //add to queue all cows waiting
        do{
            qCow.push(cows.back());
            cows.pop_back();
        }
        while(!cows.empty() && cows.back().t_start <= curr_t);

        int next_s = qCow.top().t_start;
        int next_len = qCow.top().t_len;
        
        max_wait = max(max_wait, curr_t - next_s);  
        if(next_s > curr_t) curr_t = next_s;    //if no cows waiting
        curr_t += next_len; 
        qCow.pop();
    }
    cout<<max_wait<<endl;
}