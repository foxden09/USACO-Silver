#include <iostream>

using namespace::std;
#define ll long long
#define triangular(n) ((ll) n)*((ll)n+1)/2

long long N, K, X, X_triangle; 
long long travelled = 0, minTime = 0, speed = 0;

void nextSpeed(){
    //can i go faster OR stay same OR must go slower
    long long remainDist = K - travelled;

    if(remainDist > triangular(speed+1) - X_triangle) speed++;
    else if(remainDist > triangular(speed) - X_triangle) speed = speed;
    else speed--;
}

int main() {
    freopen("race.in", "r", stdin); 
    freopen("race.out", "w", stdout); 
    cin>>K>>N;

    while(cin>>X){
        X_triangle = triangular(X);
        travelled = 0, minTime = -1, speed = 0;

        while(travelled < K){
            //cout<<speed<<" "<<travelled<<endl;
            travelled += speed; 
            minTime++;
            nextSpeed();
        }
        cout<<minTime<<endl;
    }
}