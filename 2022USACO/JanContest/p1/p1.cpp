#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace::std;
#define FOR(i, b) for(int i = 0; i < b; i++)

map<char, vector<int>> cc; 
map<char, char> dir;
map<char, vector<char>> child; 
map<char, bool> visited, happy;
int ans = 0;
bool hasCycle = false;

void dfs(char c){
    visited[c] = true;
    if(dir[c] == c) return;
    if(visited[dir[c]]){ ans++; hasCycle = true; return; }//cycle
    if(dir[c] == '\0') return; //all satisifed  
      
    ans++;
    dfs(dir[c]);
}

void happydfs(char c){
    happy[c] = true;
    if(dir[c] == c || happy[dir[c]]) return;
    happydfs(dir[c]);
}

int main(){
    freopen("p1.in", "r", stdin);
    freopen("p1.out", "w", stdout);
    int T; cin>>T;
    FOR(t, T){
        ans = 0; bool bad = false;
        cc = map<char, vector<int>>();
        dir = map<char, char>(); 
        visited = map<char, bool>(), happy = visited; 
        string s1, s2; cin>>s1>>s2;
        FOR(i, s1.size()){ //find ccs
            cc[s1[i]].push_back(i); 
            //for each cc check all elements want the same end
            if(!(dir[s1[i]] == '\0' || dir[s1[i]]==s2[i])){ bad = true; break; }
            dir[s1[i]] = s2[i]; 
            child[s2[i]].push_back(s1[i]);
        }
        if(bad){ cout<<-1<<endl; continue; }
        //create directed graph
        for(auto& [key, val] : child){
            hasCycle = false; 
            if(visited[key]) continue;
            for(char c : val){
                if(!visited[c]){
                    dfs(c);
                    happydfs(c); 
                }
            }
            if(hasCycle) ans++;
        }
        //if cycle then its cycle+1, else its just length
        cout<<ans<<endl;
    }
}