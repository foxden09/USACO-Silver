#include <iostream>
#include<algorithm>

using namespace::std;
#include<vector>
#define REP(i, a, b) for(int i = a; i < b; i++)

int N; 
vector<int> haybales; 

//propogate forwards or backwards, simulating explosions
//ends when false or reach end/beginning
int goUpDown(int hayPos, int upDown){
    int counter = 0;

    for(int j = hayPos; j > 0 && j < N-1; j+=upDown){
        counter++; 
        int distNext = abs(haybales[j]-haybales[j+upDown]); 
        if(distNext > counter) return counter-1;
    }
    return counter; 
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
        cout<<haybales[i]<<" "<<goUpDown(i, 1)<<" "<<goUpDown(i, -1)<<endl;
        maxExplode = max(maxExplode, goUpDown(i, 1)+goUpDown(i, -1));
    }
    cout<<maxExplode+1;
    

}