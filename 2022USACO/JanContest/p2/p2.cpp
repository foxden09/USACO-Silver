#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace::std;
#define FOR(i, b) for(int i = 0; i < b; i++)
typedef pair<int, int> myp;
struct coor{ int r, c; };
int N;
int grid[1502][1502]; //-1:R  -2:L  0> cost
//converts r, c to int
int ctoi(int r, int c){ return r*(N+1)+c; } 

vector<int> par , has; 
void update(int i, int children, int offset){
    //dfs for every parent update has amount
    has[i] += offset*children;
    if(par[i] == -1) return;
    update(par[i], children, offset);
}

//dfs from each vat to create cc, add has amount
int dfs(int i, int j, int previ, int prevj){
    par[ctoi(i, j)] = ctoi(previ, prevj);
    has[ctoi(i, j)] = 1;
    int i2 = i-1, j2 = j, i3 = i, j3 = j-1;
    if(!(i2<0||j2<0) && grid[i2][j2]==-2) has[ctoi(i, j)] += dfs(i2, j2, i, j);
    if(!(i3<0||j3<0) && grid[i3][j3]==-1) has[ctoi(i, j)] += dfs(i3, j3, i, j);
    return has[ctoi(i, j)];
}

int main(){
   // freopen("p2.in", "r", stdin);
   // freopen("p2.out", "w", stdout);
    cin>>N;
    par = vector<int>((N+2)*(N+2), -1); has.resize((N+2)*(N+2));
    FOR(i, N){
        string rd; cin>>rd;
        FOR(j, N) grid[i][j] = rd[j]=='R'?-1:-2; 
        cin>>grid[i][N];
    }
    FOR(j, N) cin>>grid[N][j];

    //dfs for every vat
    FOR(i, N) if(grid[i][N-1]==-1) has[ctoi(i, N)] = dfs(i, N-1, i, N);  //vats to the right
    FOR(j, N) if(grid[N-1][j]==-2) has[ctoi(N, j)] = dfs(N-1, j, N, j); //vats to the bottom

    //FOR(i, N+1){ FOR(j, N+1) cout<<has[ctoi(i, j)]<<" "; cout<<endl; }
    int Q; cin>>Q;
    int cost = 0;
        FOR(i, N) cost += has[ctoi(i, N)]*grid[i][N];
        FOR(j, N) cost += has[ctoi(N, j)]*grid[N][j];
        cout<<cost<<endl;
    FOR(q, Q){
        int fi, fj; cin>>fi>>fj; fi--; fj--;
        update(par[ctoi(fi, fj)], has[ctoi(fi, fj)], -1); //subtract old par

        if(grid[fi][fj]==-1){//find new par
            grid[fi][fj]=-2;
            par[ctoi(fi, fj)] = ctoi(fi+1, fj);
        }
        else{
            grid[fi][fj]=-1;
            par[ctoi(fi, fj)] = ctoi(fi, fj+1);
        }

        update(par[ctoi(fi, fj)], has[ctoi(fi, fj)], 1); //add has amount
       // cout<<endl;
      ///  FOR(i, N+1){ FOR(j, N+1) cout<<has[ctoi(i, j)]<<" "; cout<<endl; }
        //for every vat par, find cost
        int cost = 0;
        FOR(i, N) cost += has[ctoi(i, N)]*grid[i][N];
        FOR(j, N) cost += has[ctoi(N, j)]*grid[N][j];
        cout<<cost<<endl;
    }
    
}   