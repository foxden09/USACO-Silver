#include <iostream>
#include <vector>

using namespace::std;
#define FOR(i, b) for(int i = 0; i < b; i++)
typedef vector<int> vint;

bool isPrime(int x){
    for(int i = 2; i < x; i++){
        if(x % i == 0) return false;
    }
    return true; 
}

int main(){
   // freopen("p2.in", "r", stdin);
// freopen("p2.out", "w", stdout);
    int T; cin>>T;
    FOR(t, T){
        int N; cin>>N;
        vint cows(N); FOR(i, N) cin>>cows[i];
        int min_steps = 10000000, who_min = 0;
        vint who(N); 
        FOR(i, N){
            int mltpr = 0, this_step = cows[i]/2;
            if(cows[i]%4!=0){ this_step = (cows[i]-cows[i]%4)/2+1; 
                who[i] = 1;
                /*while(true){
                    int diff = cows[i]-mltpr*4;
                    if(diff < 0) break; 
                    if(isPrime(diff)){ this_step = mltpr*4/2+1; who[i] = 1; } //john won
                    mltpr++;
                }*/
            }
            if(this_step < min_steps){
                min_steps = this_step;
                who_min = i; 
            }
        }
        if(!who[who_min]) cout<<"Farmer Nhoj"<<endl;
        else cout<<"Farmer John"<<endl;
    }
}