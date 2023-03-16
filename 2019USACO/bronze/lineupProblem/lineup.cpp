#include <iostream>
#include<algorithm>

using namespace::std;
#include<unordered_map> 
#include<vector>
#define REP(i, b) for(int i = 0; i < b; i++)

//recursive function
//tries every cow in spot i, then i++ for(int i: 8)
//for a spot check constraints of previous 
//if not possible, stop 
//if valid, continue
vector<int> permutation; int chosen[8] = {0};
string cows[8] = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
unordered_map<int, vector<int> > besides;

//translate cow name into index in string cows[8]
int findCowNum(string name){
    REP(i, 8){
        if(cows[i]==name) return i;
    } return -1;
}

//marks which cows are possible in next position
void markPossible(int *possibleCows){
    //!make more clear
    int availableCow = -1; //if cow is -1 means all possible, -2 is none possible, other is only that possible
    for(int besidesCow: besides[permutation.back()]){
        if(chosen[besidesCow] == 0){
            if(availableCow == -1) availableCow = besidesCow; 
            else{
                availableCow = -2; break;
            }
        }
    }
    REP(i, 8){
        if(availableCow==-2) possibleCows[i] = 0;
        else if(availableCow!=-1 && i != availableCow) possibleCows[i] = 0;
    }
    
}

bool search(){
    if(permutation.size()==8){
        REP(i, 8) cout<<cows[permutation[i]]<<endl;
        return true; 
    }

    //marking possible cows for this position based on constraints
    int possibleCows[8] = {1,1,1,1,1,1,1,1};
    if(permutation.size()!=0){
       markPossible(possibleCows);
    }
    
    REP(i, 8){
        if(chosen[i]) continue;
        if(possibleCows[i]==0) continue;

        chosen[i] = true; 
        permutation.push_back(i);
        if(search()) return true;
        chosen[i] = false;
        permutation.pop_back(); 
    }
    return false;
}

int main() {
    freopen("lineup.in", "r", stdin); 
    freopen("lineup.out", "w", stdout); 
    int N; cin>>N;
    sort(cows, cows+8);
    
    //create map from cow -> who they need to be be
    string firstCow, secondCow, tempString; 
    REP(i, 8) besides.insert({i, {}});
    REP(i, N){
        cin>>firstCow; int firstInt = findCowNum(firstCow); 
        REP(j, 4) cin>>tempString;
        cin>>secondCow; int secondInt = findCowNum(secondCow); 

        besides[firstInt].push_back(secondInt);
        besides[secondInt].push_back(firstInt);
    }   

    search();
}