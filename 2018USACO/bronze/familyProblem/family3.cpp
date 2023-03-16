#include <iostream>
#include <string>
using namespace::std;
#include <vector>
#include<unordered_map>
#include<queue>
#define REP(i, b) for(int i = 0; i < b; i++)

int N; 
string bess, elsie; 
int younger, older;

struct cow{
    string name;
    int mother = -1;
    vector<int> children;
};
vector<cow> cows;

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
int bfs(int directCow){
    queue<int> q;
    q.push(directCow);
    int level = 0;

    while(!q.empty()){
        int levelSize = q.size();

        while(levelSize--){
            int currCow = q.front();
            q.pop();

            if(currCow == older) return level;
            //add children if level valid
            REP(i, cows[currCow].children.size()){
                q.push(cows[currCow].children[i]);
            }
        }
        level++;
    }
    return -1;
}

//prints proper relation based on bfs level & number of generations gone back (grand count)
void coutMsg(int level, int grand){
    if(level == 1 && grand == -1) cout<<"SIBLINGS"<<endl;
    else if(level > 1) cout<<"COUSINS"<<endl;
    else{
        cout<<cows[older].name<<" is the ";

        for(int i = grand; i > 0; i--){
            cout<<"great-";
        }
        if(level == 0 && grand == -1) cout<<"mother";
        else if(level == 0) cout<<"grand-mother";
        else cout<<"aunt";
        cout<<" of "<<cows[younger].name<<endl;
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
  
    
    //check if same family 
    int bGen, eGen;
    int bRoot = findRoot(findCow(bess), bGen);
    int eRoot = findRoot(findCow(elsie), eGen);
    if(bRoot != eRoot){
        cout<<"NOT RELATED"<<endl;
        return 0;
    }

    //check who is further down the generation line
    if(bGen > eGen){
        younger = findCow(bess);
        older = findCow(elsie);
    }
    else{
        younger = findCow(elsie); 
        older = findCow(bess);
    }


    //until reach root, check children bfs
    int directCow = younger, grand = 0; 
    do{
        directCow = cows[directCow].mother;
        int bfsResult = bfs(directCow);
        if(bfsResult != -1){
            coutMsg(bfsResult, grand-1);
            break;
        }
        grand++;
    }
    while(directCow != bRoot);
    
}