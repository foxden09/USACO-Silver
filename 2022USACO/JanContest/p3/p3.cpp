#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace::std;
#define FOR(i, b) for(int i = 0; i < b; i++)
vector<int> cross; 
int N;
string dir = ""; 
priority_queue<int> pq;

void simulate(int i, int j, int RLs){
     //RLs how much to take off
    while(true){
        //find smallest crosspoint furthest x
        int mini = j;
        for(int m = j; m >= i; m--) if(cross[m]<cross[mini]) mini = m;
        int newCross = cross[mini]-RLs-1; //minicross-RL-1, offset by already cycles
        if(newCross < 0) return;
        RLs += newCross+1; //1 for the right axing 
        FOR(rl, newCross){ //*add to the left
            FOR(s, j-i+1) dir += "R";
             FOR(s, j-i+1) dir += "L";
        }
        FOR(rl, mini-i+1) dir += "R"; //mini-i, last right b4 axing
        
        if(mini != j && i != j) simulate(mini+1, j, RLs-1);
        FOR(rl, mini-i+1) dir += "L"; //mini-i
        j = mini-1; 
        if(j < i) break;        
    }
}

int main(){
    //freopen("p3.in", "r", stdin);
    //freopen("p3.out", "w", stdout);
    cin>>N;
    string s = string("s", 4);
    cross.resize(N); 
    FOR(i, N) { cin>>cross[i]; cross[i]/=2; } 
    simulate(0, N-1, 0);
    cout<<dir<<endl;
}