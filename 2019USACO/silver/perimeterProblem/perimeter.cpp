#include <iostream>
#include <climits>
using namespace::std;
#include <vector>
#define FOR(i, b) for(int i = 0; i < b; i++)

char grid[1001][1001];
bool visited[1001][1001];
int max_a = -1, min_p = INT_MAX; //max area and its min perimeter 
int N, peri = 0;

//find blob & its perimeter
int ff(int i, int j){
    if(i >= N || j >= N ||  j < 0 || i < 0 ||
        grid[i][j] == '.' ) { peri++; return 0; }
    if(visited[i][j]) return 0;

    visited[i][j] = 1;
    int area = 1;

    area += ff(i + 1, j);  
    area += ff(i, j + 1);
    area += ff(i - 1, j);
    area += ff(i, j - 1);

    return area;
}

int main() {
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);

    //feed in data
    cin>>N;
    FOR(i, N){
        FOR(j, N) cin>>grid[i][j];
    }

    //find max area blob
    FOR(i, N){
        FOR(j, N){
            if(!visited[i][j]) { 
                peri = 0; 
                int curr_a = ff(i, j);
                if(max_a == curr_a) min_p = min(peri, min_p);
                if(max_a < curr_a) { max_a = curr_a; min_p = peri; }
            }
        }
    }
    cout<<max_a<<" "<<min_p<<endl;
}   
