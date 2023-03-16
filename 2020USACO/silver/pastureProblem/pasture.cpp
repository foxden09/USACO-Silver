#include <iostream>
#include <algorithm>
using namespace::std;
#include <vector>
#define FOR(i, b) for(int i = 0; i < b; i++)
#define F0R(i, a, b) for(int i = a; i <= b; i++)
int N;
struct coor { int x, y; };
bool compX(const coor& lhs, const coor& rhs) { return lhs.x < rhs.x; }
bool compY(const coor& lhs, const coor& rhs) { return lhs.y < rhs.y; }
vector<coor> coors; int cows[2501][2501];

void make_psum(){
    FOR(i, N) cows[coors[i].x][coors[i].y] = 1;
    F0R(i, 1, N){
        F0R(j, 1, N){
            cows[i][j] += cows[i-1][j] + cows[i][j-1]
            - cows[i-1][j-1]; 
        }
    }
}

int main() {
    freopen("pasture.in", "r", stdin);
    freopen("pasture.out", "w", stdout);

    //feed in data & compress coors
    cin>>N; coors.resize(N);
    FOR(i, N) cin>>coors[i].x>>coors[i].y;
    
    sort(coors.begin(), coors.end(), compY);
    FOR(i, N) coors[i].y = i+1;
    sort(coors.begin(), coors.end(), compX);
    FOR(i, N) coors[i].x = i+1; 

    make_psum();     //create psum

    //find rectangles
    long long tot = 0;
    FOR(i, N){
        F0R(j, i+1, N-1){   //j is higher
            int x_i = coors[i].x, y_i = coors[i].y, x_j = coors[j].x, y_j = coors[j].y;
            int maxy = max(y_i, y_j); int miny = min(y_i, y_j);
           
            int topY = cows[x_i][maxy] - cows[x_i][miny-1];
            int botY = cows[N][maxy] - cows[x_j-1][maxy] - cows[N][miny-1] + cows[x_j-1][miny-1];
            tot += topY * botY;
        }
    }
    cout<<tot+N+1<<endl;
}
