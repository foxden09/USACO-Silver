#include <iostream>
using namespace::std;
#include <vector>
#include <map>
#include <string>
#define FOR(i, b) for(int i = 0; i < b; i++)
typedef vector<vector<char>> vchar; 
typedef vector<vector<bool>> vbool;
struct paper{ 
    int p_i, p_j; char p_c; 
    bool operator<(const paper& rhs) const{
        if(p_i == rhs.p_i) return p_j < rhs.p_j;
        return p_i < rhs.p_i; 
    }
}; 

int N;
string Maze[25][25];
vector<paper> myseq; 
map<paper, vector<paper>> leads_to; 

//check if moo present
bool has_moo(){
        //diagonals, rows, cols, all backwards
    return true;
}

//if paper present, update blocked by
void upd_board(int i, int j, vbool visited, paper& prev_move){
    char MO = Maze[i][j][0];
    if(MO == 'O' || MO == 'M'){
        int MO_i = Maze[i][j][1] - '0'; MO_i--;
        int MO_j = Maze[i][j][2] - '0'; MO_j--;

        paper curr_move = {MO_i, MO_j, MO};
        leads_to[prev_move].push_back(curr_move);
        prev_move = curr_move;
    }
}

//floodfill
void ff(int i, int j, vbool& visited, paper prev_move){
    if(i < 0 || j < 0 || j >= N || i >= N) return;
    if(Maze[i][j] == "###" || visited[i][j]) return;
    visited[i][j] = true;
    
    upd_board(i, j, visited, prev_move);
    
    ff(i+1, j, visited, prev_move);  ff(i-1, j, visited, prev_move);
    ff(i, j+1, visited, prev_move);  ff(i, j-1, visited, prev_move);
}

//simulate creating sequences
void sim_seq(paper& myp, vchar& board){
    if(board[myp.p_i][myp.p_j] == ' ') board[myp.p_i][myp.p_j] = myp.p_c;
    //myseq.push_back(myp);
    //for(auto thing : myseq) cout<<"("<<thing.p_i<<", "<<thing.p_j<<") "; cout<<endl;
    for(paper& led_to : leads_to[myp]){
        sim_seq(led_to, board);
        board[myp.p_i][myp.p_i] = ' ';
        //myseq.pop_back();
    }
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
    vbool myvst (N, vector<bool>(N));
    paper mypaper = {myi, myj, 'B'};
    ff(myi, myj, myvst, mypaper);

    vchar myboard (3, vector<char>(3, ' '));
    //for(paper& move1 : leads_to[mypaper]) sim_seq(move1, myboard);
}