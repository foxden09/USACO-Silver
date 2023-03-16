#include <iostream>
using namespace::std;
#include <vector>
#include <string>
#include <map>
#include <set>
#define FOR(i, b) for(int i = 0; i < b; i++)

int N;
int grid[250][250], marked[250][250];
bool visited[250][250], time1st = true;
int want, unq;
vector<int> sizes;                  //mark to size of region
map<int, set<int>> mymap, visitreg;  //mark to nbor marks / visited marks
int max_one = 0, max_two = 0; 

string id2s(int id1, int id2) { return to_string(min(id1, id2)) + " " + to_string(max(id1, id2)); }
pair<int, int> mark2p(int mark1, int mark2) { return {min(mark1, mark2), max(mark1, mark2)}; }

//look for biggest single cow region 
int ff(int i, int j){
    if(i < 0 || j < 0 || i >= N || j >= N || visited[i][j]) return 0;
    if(grid[i][j] != want && !time1st) mymap[unq].insert(marked[i][j]);
    if(grid[i][j] != want) return 0;
    visited[i][j] = true;

    int count = 1; 
    marked[i][j] = unq;
    count += ff(i+1, j) + ff(i-1, j);
    count += ff(i, j-1) + ff(i, j+1);
    return count;
}   

//call one_ff
void call_ff(){
    unq = 0;
    FOR(i, N) { FOR(j, N){ visited[i][j] = 0; } } 

    FOR(i, N){
        FOR(j, N){
            if(!visited[i][j]){
                want = grid[i][j];
                if(time1st) sizes.push_back(ff(i, j));
                max_one = max(sizes[unq], max_one);
                unq++; 
            }
        }
    }
}

//simulate grouping two marks
void two_cow(int ind, int id1, int id2 int totsz){
    
}

int main() {
    freopen("multimoo.in", "r", stdin);
    freopen("multimoo.out", "w", stdout);

    //feed in data
    cin>>N;
    FOR(i, N){
        FOR(j, N){
            cin>>grid[i][j];
        }
    }

    call_ff(); time1st = false;   //find single cow max
    call_ff();                    //find nbors
    
    for(auto p : mymap){
       for(int s : p.second){
           if(visitreg[p.first].find(s) != p.second.end()) continue;

        }
    }
}

/*
FOR(i, N){
        FOR(j, N){
            cout<<marked[i][j]<<" ";
        }cout<<endl;
    }cout<<endl;

*/