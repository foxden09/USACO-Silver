#include <iostream>
#include <string>
using namespace::std;
#include <vector>
#include<unordered_map>
#include<queue>
#define REP(i, b) for(int i = 0; i < b; i++)

int N; 
string bess, elsie; 

struct cow{
    string name;
    int mother = -1;
    vector<int> children;
};
vector<cow> cows;
vector<bool> visited = {0};

//finds index of certain cow in cows
int findCow(string cowName){
    REP(i, cows.size()) if(cows[i].name == cowName) return i;
    return -1;
}

//finds root of family tree
int findRoot(int cowInd, int &countGen){
    countGen = 0;
    while(cows[cowInd].mother != -1){
        cowInd = cows[cowInd].mother;
        countGen++;
    }
    return cowInd; 
}

//from direct ancestor/bessie, check children with bfs
void bfs(int directCow){
    queue<int> q;
    q.push(directCow);
    int level = 0;

    while(!q.empty()){
        int levelSize = q.size();

        while(levelSize--){
            int currCow = q.front();
            q.pop();

            visited[currCow] = true;

            //add non visited children
            REP(i, cows[currCow].children.size()){
                if(visited[i]) continue;
                else q.push(cows[currCow].children[i]);
            }
        }
        level++;
    }
}
int main() {
    freopen("family.in", "r", stdin); 
    freopen("family.out", "w", stdout); 
    cin>>N>>bess>>elsie;

    //create tree
    REP(i, N){
        cow cow1, cow2;
        cin>>cow1.name>>cow2.name;
        if(findCow(cow1.name) == -1) cows.push_back(cow1); 
        if(findCow(cow2.name) == -1) cows.push_back(cow2);

        int ind1 = findCow(cow1.name);
        int ind2 = findCow(cow2.name);
        cows[ind2].mother = ind1;
        cows[ind1].children.push_back(ind2);
    }
    visited.resize(cows.size());
  
    
    //check if same family & who is further down the generation line
    int bGen, eGen;
    int bRoot = findRoot(findCow(bess), bGen);
    int eRoot = findRoot(findCow(elsie), eGen);
    if(bRoot != eRoot){
        cout<<"NOT RELATED"<<endl;
        return 0;
    }

    int younger;
    if(bGen > eGen) younger = findCow(bess);
    else younger = findCow(elsie); 
   
    //until reach root, check children bfs
    int directCow = younger;
    do{
        bfs(directCow);
        directCow = cows[directCow].mother;
    }
    while(directCow != bRoot);
    
}