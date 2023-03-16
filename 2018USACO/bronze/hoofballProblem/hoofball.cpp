#include <iostream>
#include <algorithm>
#include <string>

using namespace::std;
#include <vector>
#include <bitset>
#define REP(i, b) for(int i = 0; i < b; i++)

vector<int> cowPos;
int N; 
int numOfgroups = 0, minGroups[101];  
int groupCounter = 1; int previous = 0; 

//returns pos of nearest cow
int nearestCow(int pos){
    int leftDist = 100000, rightDist = 100001;
    if(pos != 0) leftDist = abs(cowPos[pos]-cowPos[pos-1]);
    if(pos != N-1) rightDist = abs(cowPos[pos]-cowPos[pos+1]);
    
    if(leftDist == rightDist) return -1; 
    else if(leftDist > rightDist) return 1;
    else if(leftDist < rightDist) return -1; 
}

//skip to end of group
int goToEnd(int indexOf, int *someShift){
    int groupNum = someShift[indexOf]; 
    while(indexOf < N){
        if(someShift[indexOf] == groupNum) minGroups[indexOf] = groupNum; 
        else break; 
        indexOf++;
    }
    numOfgroups++; 
    return indexOf-1; 
}

//adds groups of right shifts and left shifts to respective array
void addShift(int i, int myShift, int *someShift){
    if(myShift != previous) groupCounter++; 
    previous = myShift;

    someShift[i+myShift] = groupCounter;
    someShift[i] = groupCounter;
}

//calculates min num of groups to use when both are available
int bothGroups(int indexOf, int *rightShift, int *leftShift){
    while(indexOf <)
}   

int main() {
    freopen("hoofball.in", "r", stdin); 
    freopen("hoofball.out", "w", stdout); 
    cin>>N;

    //read in all the pos, sort
    int tempPos;
    REP(i, N){
        cin>>tempPos; 
        cowPos.push_back(tempPos);
    }
    sort(cowPos.begin(), cowPos.end());


    //create arrays representing where everyone leads to
    int rightShift[110] = {0}, leftShift[110] = {0};
    REP(i, N){
        int myShift = nearestCow(i); 

        if(myShift == 1) addShift(i, myShift, rightShift);
        if(myShift == -1) addShift(i, myShift, leftShift);
    }

    REP(i, N) cout<<rightShift[i]<<" ";
    cout<<endl;
    REP(i, N) cout<<leftShift[i]<<" ";
    cout<<endl; 

    //find minimum # of groups that accepts every cow 
    int indexOf = 0; 
    while(indexOf < N){
        if(rightShift[indexOf] != 0 && leftShift[indexOf] != 0) minGroups[indexOf] = 0;
        else{
            if(rightShift[indexOf] != 0) indexOf = goToEnd(indexOf, rightShift); 
            else if(leftShift[indexOf] != 0) indexOf = goToEnd(indexOf, leftShift); 
        }  
        //cout<<indexOf<<endl;
        indexOf++; 
    }
    REP(i, N) cout<<minGroups[i]<<" ";
    //where there are 0s in minGroups add another group
    indexOf = 0;
    while(indexOf < N){
        if(minGroups[indexOf] == 0){
            indexOf = bothGroups(indexOf, rightShift, leftShift );
        }
        indexOf++;
    }
    cout<<numOfgroups<<endl;
}
