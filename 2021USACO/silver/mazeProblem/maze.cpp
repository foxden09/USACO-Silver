#include <iostream>
using namespace::std;
#include <vector>
#include <set>
#include <string>
#define FOR(i, b) for(int i = 0; i < b; i++)
typedef vector<vector<char>> vchar; 
typedef vector<vector<bool>> vbool;

int N;
string Maze[25][25];
set<string> orders; 

//checks if ordering is unique
bool is_new_order(vchar &newbrd){
    string myord;
    FOR(i, 3){
        FOR(j, 3){
            myord += newbrd[i][j];
        }
    }
    if(orders.find(myord) == orders.end()) return false;
    orders.insert(myord);
    return true;
}

//check if moo present
bool has_moo(){
    return true;
}


//floodfill
void call_ff(int i, int j, vchar& board, vbool& visited);

void ff(int i, int j, vchar& board, vbool& visited){
    if(i < 0 || j < 0 || j >= N || i >= N) return;
    if(Maze[i][j] == "###" || visited[i][j]) return;
    visited[i][j] = true;
    
    //if its a move
    char MO = Maze[i][j][0];
    int MO_i = Maze[i][j][1] - '0'; MO_i--;
    int MO_j = Maze[i][j][2] - '0'; MO_j--;
    cout<<"HI"<<endl;
    if(MO == 'O' || MO == 'M'){
        vchar newbrd;
        copy(board.begin(), board.end(), back_inserter(newbrd));
        vbool newvst (N, vector<bool>(N));
        newvst[i][j] = 1;
        
        if(newbrd[MO_i][MO_j] == ' ') {
            newbrd[MO_i][MO_j] = MO;
            is_new_order(newbrd);
        }
        call_ff(i, j, newbrd, newvst);
    }
    else call_ff(i, j, board, visited);
}

void call_ff(int i, int j, vchar& board, vbool& visited){
    ff(i+1, j, board, visited); 
    ff(i-1, j, board, visited);
    ff(i, j+1, board, visited); 
    ff(i, j-1, board, visited);
}

int main() {
    freopen("maze.in", "r", stdin);
    freopen("maze.out", "w", stdout);

    //feed in data
    cin>>N;
    string temp = "___";
    int myi, myj;

    FOR(i, N){
        FOR(j, N){
            FOR(k, 3) cin>>temp[k]; 
            Maze[i][j] = temp;
            if(Maze[i][j] == "BBB") { myi = i; myj = j; }
        }
    }

    //initiate flood fill at BBB
    vchar myboard (3, vector<char>(3, ' '));
    vbool myvst (N, vector<bool>(N));
    ff(myi, myj, myboard, myvst);

    //diagonals, rows, cols, all backwards
}