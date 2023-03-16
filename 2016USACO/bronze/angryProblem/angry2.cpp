#include <iostream>
#include<algorithm>

using namespace::std;
#include<vector>
#define REP(i, a, b) for(int i = a; i < b; i++)

int N; 
vector<int> haybales; 

//propogate forwards or backwards, simulating explosions
//ends when false or reach end/beginning
int explode(int currentPos, int upDown, int counter){

    int nextPos = currentPos+upDown;
    while(true){
        if(nextPos <= -1 || nextPos >= N) break; 

        int dist = abs(haybales[nextPos] - haybales[currentPos]);
        if(dist > counter){
            if(nextPos==currentPos+upDown) break;         //no significant prev explosions, cant go farther
            return explode(nextPos-=upDown, upDown, counter+1);     //check what happened with prev furthest explosion
        }
        else nextPos+=upDown;               //increment to next possible explosion victim
    }

    return nextPos-upDown; 
}   

int main() {
    freopen("angry.in", "r", stdin); 
    freopen("angry.out", "w", stdout); 
    cin>>N;
    
    //feed in haybale positions and sort them 
    int tempHay; 
    REP(i, 0, N){
        cin>>tempHay; 
        haybales.push_back(tempHay);
    }
    sort(haybales.begin(), haybales.end());

    //simulate explosions to find maximum exploded haybales *ignore beginning and end
    int maxExplode = 0; 
    REP(i, 1, N-1){
        int explosion = (explode(i, 1, 1)-i)+(i-explode(i, -1, 1)); 
        maxExplode = max(maxExplode, explosion);
    }
    cout<<maxExplode+1;
    

}