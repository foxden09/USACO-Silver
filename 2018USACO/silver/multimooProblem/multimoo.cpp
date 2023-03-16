#include <iostream>
using namespace::std;
#include <vector>
#include <string>
#define FOR(i, b) for(int i = 0; i < b; i++)
typedef pair<int,int> myp;

int N;
int grid[250][250], marked[250][250];
bool visited[250][250];
int want, unq = 0;
int max_one = 0, max_two = 0, totsz; 

struct Region{  int label, mysz; vector<myp> leads_to; vector<bool> visitreg; };
vector<Region> regions; 


//look for biggest single cow region & mark boundaries
int one_ff(int i, int j){
    if(i < 0 || j < 0 || i >= N || j >= N || visited[i][j]) return 0;
    if(grid[i][j] != want) regions[unq].leads_to.push_back({i, j});
    if(grid[i][j] != want) return 0;

    marked[i][j] = unq;   //mark with label
    visited[i][j] = true;

    int count = 1; 
    count += one_ff(i+1, j) + one_ff(i-1, j);
    count += one_ff(i, j-1) + one_ff(i, j+1);
    return count;
}   

void two_ff(Region &r, int lbl1, int lbl2){
    for(myp nbor : r.leads_to){
        int myunq = marked[nbor.first][nbor.second];
        if(r.visitreg[myunq]) continue;
        r.visitreg[myunq] = true;

        Region& newr = regions[myunq];
        if(lbl2 != -1 && newr.label != lbl1 && newr.label != lbl2) continue;
        cout<<r.label<<" leads to "<<grid[nbor.first][nbor.second]<<" "<<newr.mysz<<endl;
        totsz += newr.mysz;
        max_two = max(max_two, totsz);
        two_ff(newr, lbl1, newr.label);
        totsz -= newr.mysz;
        //r.visitreg[myunq] = false;
    }
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

    //find single cow max
    FOR(i, N){
        FOR(j, N){
            if(!visited[i][j]){
                regions.push_back({});
                want = grid[i][j];

                regions[unq].mysz = one_ff(i, j); 
                regions[unq].label = want;
                max_one = max(regions[unq].mysz, max_one);
                unq++;
            }
        }
    }

    //find cow pair max
    FOR(i, regions.size()) regions[i].visitreg.resize(regions.size());
    FOR(i, regions.size()){
        totsz = regions[i].mysz;
        two_ff(regions[i], regions[i].label, -1);
        
    }
    cout<<max_two<<endl;
}
