#include <iostream>

using namespace::std;
#include <vector>
#include <string>
#include <unordered_map>
#define FOR(i, b) for(int i = 0; i < b; i++)
#define F0R(i, a, b) for(int i = a; i < b; i++)
typedef vector< unordered_map<string, int> > myvec;
typedef vector< vector<string> > myvec2;
int N, unq = 1, cows = 0;    //unique label for each blob
char wanted;   //each blob's defining char
bool visited[20][20];
vector<myvec2> visitrect (20, myvec2(20));
char photo[20][20];
string marked[21][21];


vector<myvec> psum (21, myvec(21));
void make_psum(){
    F0R(i, 1, N+1){
        F0R(j, 1, N+1){
            psum[i][j][marked[i-1][j-1]]++;
            for(auto &p : psum[i-1][j]) psum[i][j][p.first] += p.second;
            for(auto &p : psum[i][j-1]) psum[i][j][p.first] += p.second;
            for(auto &p : psum[i-1][j-1]) psum[i][j][p.first] -= p.second;
        }
    }
}

//checks if rectangle valid
bool ff_check(int i1, int j1, int i2, int j2){
    i1++; j1++; i2++; j2++;
    unordered_map<char, vector<int>> blobs; 
    unordered_map<string, int> mysum; 

    for(auto &p : psum[i2][j2]) mysum[p.first] += p.second;
    for(auto &p : psum[i1-1][j2]) mysum[p.first] -= p.second;
    for(auto &p : psum[i2][j1-1]) mysum[p.first] -= p.second;
    for(auto &p : psum[i1-1][j1-1]) mysum[p.first] += p.second;
    for(auto &p : mysum){
        if(p.second <= 0) continue;
        string unqs = p.first.substr(1); int unqi = stoi(unqs);
        blobs[p.first[0]].push_back(unqi);
    } 
    
    int onefrq = 0, twofrq = 0;
    for(auto &p : blobs){
        if(p.second.size() == 1) onefrq++;
        if(p.second.size() > 1) twofrq++;
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

//floodfill
void ff(int i, int j){
    if(i < 0 || j < 0 || j >= N || i >= N) return;
    if(visited[i][j] || photo[i][j] != wanted) return;
    visited[i][j] = 1;
    marked[i][j] = wanted + to_string(unq);

    ff(i + 1, j);    ff(i, j + 1);
    ff(i - 1, j);    ff(i, j - 1);
}   

//loop over all possible bottom right (ends) 
void loop_end(int s_i, int s_j){
    for(int o = N - 1; o >= min(s_i, s_j); o--){
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

    //map blobs to numbers & make psum
    FOR(i, N){
        FOR(j, N){
            if(!visited[i][j]){
                wanted = photo[i][j];
                ff(i, j);
                unq++;
            }
        }
    }
    make_psum();
    
    //loop over upper left bound (start), in nested L shape
    FOR(o, N){   //originator
        loop_end(o, o); 
        F0R(j, o+1, N) loop_end(o, j);
        F0R(i, o+1, N) loop_end(i, o);
    }

    cout<<cows<<endl;
}


/*
FOR(i, N+1){
        FOR(j, N+1){
            cout<<"In "<<i<<" "<<j<<", ";
            for(auto ss : psum[i][j]) cout<<ss.second<<" of group "<<ss.first<<endl;
            cout<<endl;
        }
        cout<<endl;
    }
*/