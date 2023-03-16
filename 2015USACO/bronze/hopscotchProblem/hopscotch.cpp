#include <iostream>

using namespace::std;

int R, C;
char board[15][15]; 

//counts # of possible paths from specified R & C (recursive)
int countPath(int fromR, int fromC){
    if(fromR == R-1 && fromC == C-1) return 1;

    int totalPathCount = 0;
    for(int nextR = fromR + 1; nextR < R; nextR++){
        for(int nextC = fromC + 1; nextC < C; nextC++){

            //checks if color different/valid jump
            if(board[nextR][nextC] != board[fromR][fromC]){
                totalPathCount += countPath(nextR, nextC);
            }
        }
    }

    return totalPathCount; 
}


int main() {
    freopen("hopscotch.in", "r", stdin); 
    freopen("hopscotch.out", "w", stdout); 
    cin>>R>>C;

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin>>board[i][j];
        }
    }

    cout<<countPath(0, 0)<<endl;
}