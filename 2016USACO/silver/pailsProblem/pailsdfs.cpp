#include <iostream>

using namespace::std;
#include<climits>

bool visited[101][101][101] = {0};
int minDist = INT_MAX;
int X, Y, maxOps, desired;

//search through possible states to find min distance (not visited & <= K)
void dfs(int currOp, int currX, int currY){
    if(visited[currX][currY][currOp] || currOp > maxOps) return;

    minDist = min(minDist, abs(desired - (currX + currY)));
    visited[currX][currY][currOp] = 1;

    dfs(currOp + 1, 0, currY);  //empty X
    dfs(currOp + 1, currX, 0);  //empty Y
    dfs(currOp + 1, X, currY);  //fill X
    dfs(currOp + 1, currX, Y);  //fill Y

    int pourXtoY = min(currX, Y - currY);
    dfs(currOp + 1, currX - pourXtoY, currY + pourXtoY);   //pour X into Y
    int pourYtoX = min(currY, X - currX);
    dfs(currOp + 1, currX + pourYtoX, currY - pourYtoX);   //pour Y into X
}

int main() {
    freopen("pails.in", "r", stdin); 
    freopen("pails.out", "w", stdout); 
    cin>>X>>Y>>maxOps>>desired;

    dfs(0, 0, 0);

    cout<<minDist<<endl;
}