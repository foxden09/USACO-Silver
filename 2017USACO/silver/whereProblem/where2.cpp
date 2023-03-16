#include <iostream>
using namespace::std;
#include <vector>
#include <string>
#include <unordered_map>
#define FOR(i, b) for(int i = 0; i < b; i++)
#define F0R(i, a, b) for(int i = a; i < b; i++)
typedef vector< vector<string> > myvec;
typedef vector<bool> myvec2;
int N, cows = 0;  
char wanted;                //each blob's defining char
vector<myvec> visitrect (20, myvec(20));
char photo[20][20];

//floodfill
void ff(int i, int j, int i1, int j1, int i2, int j2, vector<myvec2>& visited){
    if(i < i1 || j < j1 || j > j2 || i > i2) return;
    if(visited[i][j] || photo[i][j] != wanted) return;
    visited[i][j] = 1;

    ff(i + 1, j, i1, j1, i2, j2, visited);    ff(i, j + 1, i1, j1, i2, j2, visited);
    ff(i - 1, j, i1, j1, i2, j2, visited);    ff(i, j - 1, i1, j1, i2, j2, visited);
}   

//checks if rectangle valid
bool ff_check(int i1, int j1, int i2, int j2){
    vector<myvec2> visited (20, myvec2(20));
    unordered_map<char, int> regions; 

    F0R(i, i1, i2+1){
        F0R(j, j1, j2+1){
            if(!visited[i][j]){
                wanted = photo[i][j];
                ff(i, j, i1, j1, i2, j2, visited);
                regions[wanted]++;
            }
        }
    }

    int onefrq = 0, twofrq = 0;
    if(regions.size() != 2) return false;

    for(auto &p : regions){
        if(p.second == 1) onefrq++;
        if(p.second > 1) twofrq++;
    }
    if(onefrq == 1 && twofrq == 1) return true;

    return false;
}

//checks if rectangle contained within another / calls ff_check
bool usurped(int i1, int j1, int i2, int j2){
    for(string s1 : visitrect[i1][j1]){
        for(string s2 : visitrect[i2][j2]){
            if(s1 == s2) return true;
        }
    }
    
    if(ff_check(i1, j1, i2, j2)){
        F0R(i, i1, i2+1){
            F0R(j, j1, j2+1){
                visitrect[i][j].push_back(to_string(i1)+" "+to_string(j1)+" "+to_string(i2)+" "+to_string(j2));
            }
        }
        cows++;
    }
    return false;
}

//loop over all possible bottom right (ends) 
void loop_end(int s_i, int s_j){
    for(int o = N - 1; o >= max(s_i, s_j); o--){
        if(usurped(s_i, s_j, o, o)) break; 
        for(int i = o-1; i >= s_i; i--) { if(usurped(s_i, s_j, i, o)) break; } 
        for(int j = o-1; j >= s_j; j--) { if(usurped(s_i, s_j, o, j)) break; } 
    }
}

int main() {
    freopen("where.in", "r", stdin);
    freopen("where.out", "w", stdout);

    //feed data
    cin>>N;
    FOR(i, N){
        FOR(j, N){
            cin>>photo[i][j];
        }
    }
    
    //loop over upper left bound (start), in nested L shape
    FOR(o, N){   //originator
        loop_end(o, o); 
        F0R(j, o+1, N) loop_end(o, j);
        F0R(i, o+1, N) loop_end(i, o);
    }

    cout<<cows<<endl;
}