#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace::std;
#define FOR(i, b) for(int i = 0; i < b; i++)

bool all52(map<char, char>& cc, map<char, int>& simple){ //simple cycle all 52
    for(auto& [key, val] : cc) if(val == -1) return false; 
    for(auto& [key, val] : simple) if(!val) return false; 
    return true;
}

int check(){
    map<char, char> cc; //target
    map<char, int> cyc, isSimpleCyc; 

    string s1, s2; cin>>s1>>s2;
    if(s1 == s2) return 0;
    int sz = s1.size(), ans = 0;

    //make ccs
    //find targets, check for conflicts
    for(char c = 'a'; c <= 'z'; c++) cc[c] = -1;
    for(char c = 'A'; c <= 'Z'; c++) cc[c] = -1;

    FOR(i, sz){
        if(cc[s1[i]] != -1 && cc[s1[i]] != s2[i]) return -1; //conflict
        cc[s1[i]] = s2[i];
    }
    
    //find cycles
        //if dont end up in same place or theres a leaf then not extra
    int id = 1;
    for(auto& [c0, target] : cc){
        //+1 for every cc not on target already
        if(target == -1) continue; 
        if(c0 != target) ans++;
        if(cyc[c0]) continue; //already accounted

        char c = c0;
        while(!cyc[c]){
            cyc[c] = id; 
            c = cc[c]; 
            if(c == -1 || c == cc[c]) break; //not a cycle
            if(cyc[c]){
                if(c != c0) isSimpleCyc[cyc[c]] = false;
                else if(cyc[c] != id) isSimpleCyc[cyc[c]] = false;
                else if(isSimpleCyc.find(cyc[c])==isSimpleCyc.end() && cyc[c] == id && c == c0) isSimpleCyc[cyc[c]] = true;
            }
        }
        id++;
    }
    //52 exception
    if(all52(cc, isSimpleCyc)) return -1;
    for(auto& [c0, isSimple] : isSimpleCyc) if(isSimple) ans++;
    return ans;
}

int main() {
   // freopen("p1.in", "r", stdin);
   // freopen("p1.out", "w", stdout);
    int T; cin>>T;
    FOR(t, T){
        cout<<check()<<endl;
    }
}