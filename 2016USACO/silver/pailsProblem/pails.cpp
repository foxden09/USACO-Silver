#include <iostream>

using namespace::std;
#include<queue>
#include<vector>
#include<climits>
using vbool = vector<bool>;

struct state{
    int op, x, y;
};
queue<state> states;

//enque if valid state (not visited)
void statesEnque(state nextState, vector<vbool> &visited){
    if(!visited[nextState.x][nextState.y]){
        states.push(nextState);
    }
}

int main() {
    freopen("pails.in", "r", stdin); 
    freopen("pails.out", "w", stdout); 
    int X, Y, maxOps, desired;
    cin>>X>>Y>>maxOps>>desired;

    states.push(state{0, 0, 0});
    int minDist = INT_MAX;
    vector<vbool> visited (X+1, vbool (Y+1, 0));

    while(!states.empty()){
        state curr = states.front();
        states.pop();
        visited[curr.x][curr.y] = 1;

        minDist = min(minDist, abs(desired - (curr.x + curr.y)));
        if(curr.op < maxOps){
            statesEnque( state{curr.op + 1, 0, curr.y}, visited); //empty X bucket
            statesEnque( state{curr.op + 1, curr.x, 0}, visited); //empty Y bucket
            statesEnque( state{curr.op + 1, X, curr.y}, visited); //fill X bucket
            statesEnque( state{curr.op + 1, curr.x, Y}, visited); //fill Y bucket

            int pourXtoY = min(curr.x, Y - curr.y);
            statesEnque( state{curr.op + 1, curr.x - pourXtoY, curr.y + pourXtoY}, visited); //pour X into Y
            int pourYtoX = min(curr.y, X - curr.x);
            statesEnque( state{curr.op + 1, curr.x + pourYtoX, curr.y - pourYtoX}, visited); //pour Y into X
        }
    }
    cout<<minDist<<endl;
}