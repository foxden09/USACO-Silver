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
    int maxGroupNum = 0; 
    indexOf = 0; 

    while(indexOf < N){
        if(someShift[indexOf] == groupNum){
            maxGroupNum = indexOf;
            minGroups[indexOf] = groupNum; 
        }
        indexOf++;
    }

    numOfgroups++; 
    return maxGroupNum;  
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
    int prevRight = 0, prevLeft = 0; 
    int rightGroups = 0, leftGroups = 0;

    while(indexOf < N){
        if(minGroups[indexOf] == 0){
            if(rightShift[indexOf] != prevRight){
                prevRight = rightShift[indexOf]; 
                rightGroups++; 
            }
            if(leftShift[indexOf] != prevLeft){
                prevLeft = leftShift[indexOf]; 
                leftGroups++; 
            }
        }
        else break; 
        indexOf++;
    }

    numOfgroups += min(leftGroups, rightGroups); 
    return indexOf-1; 
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

    //find minimum # of groups that accepts every cow 
    int indexOf = 0; 
    while(indexOf < N){
        if(rightShift[indexOf] != 0 && leftShift[indexOf] != 0) minGroups[indexOf] = 0;
        else{
            if(rightShift[indexOf] != 0) indexOf = goToEnd(indexOf, rightShift); 
            else if(leftShift[indexOf] != 0) indexOf = goToEnd(indexOf, leftShift); 
        }  
        indexOf++; 
    }

    //where there are 0s in minGroups add more groups
    indexOf = 0;
    while(indexOf < N){
        if(minGroups[indexOf] == 0){
            indexOf = bothGroups(indexOf, rightShift, leftShift);
        }
        indexOf++;
    }
    cout<<numOfgroups<<endl;
}
