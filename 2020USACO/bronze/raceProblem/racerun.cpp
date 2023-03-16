#include <iostream>
#include <fstream>
using namespace::std;
#include <vector>
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

vector<int> allK;
void solve(string finname){
    fstream fin, fout;
    fin.open(finname.c_str(), fstream::in);
    fout.open("race.out", fstream::out);
    
    fin>>K>>N;

    while(fin>>X){
        X_triangle = triangular(X);
        travelled = 0, minTime = -1, speed = 0;

        while(travelled < K){
            //cout<<speed<<" "<<travelled<<endl;
            travelled += speed; 
            minTime++;
            nextSpeed();
        }
        fout<<minTime<<endl;
        allK.push_back(minTime);
    }

    fin.close();
    fout.close();
}

int main() {
    fstream fin, fout;
    for(int i = 1 ; i <= 10; i++){
        string finname = to_string(i) + ".in";
        string foutname = to_string(i) + ".out";

        auto start = chrono::steady_clock::now();
        solve(finname);
        auto end = chrono::steady_clock::now();
        auto diff = end - start;

        fin.open(foutname.c_str(), fstream::in);
        
        bool oks = 1;
        int tempx;
        while(fin>>tempx){  
            if(tempx != allK[i]) oks = 0;
        }
        if(oks == 0) cout<<"Test #"+to_string(i)+" failed";
        else cout<<"Test #"+to_string(i)+" succeeded";
        cout << " .... took "<< chrono::duration <double, milli> (diff).count() << " ms"<<endl;;
        fin.close();
        allK.clear();
    }
}