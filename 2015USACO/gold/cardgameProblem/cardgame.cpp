#include <iostream>
#include <algorithm>
using namespace::std;
#include <vector>
#include <queue>
#define FOR(i, a, b) for(int i = a; i < b; i++)
typedef vector<int> vint;
int N, my_i, wins = 0;

void play_card(vint &elsie, int r1or2, int inc){
    int count = 0;
    queue<int> bessie; 
    while(my_i >= 0 && my_i < N*2 && count < N){
        
        if(elsie[my_i] == 0) bessie.push(my_i);
        else if(elsie[my_i] == r1or2){
            count++;
            if(!bessie.empty()){
                bessie.pop(); 
                wins++;
            }
        }
        my_i += inc;
    }
}

int main() {
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    cin>>N;

    //feed in cards
    vint elsie (N*2);
    FOR(i, 0, N/2) { cin>>my_i; elsie[my_i - 1] = 1; }
    FOR(i, 0, N/2) { cin>>my_i; elsie[my_i - 1] = 2; }

    my_i = N*2-1;
    play_card(elsie, 1, -1);
    my_i = 0; 
    play_card(elsie, 2, 1);

    cout<<wins<<endl;
}
