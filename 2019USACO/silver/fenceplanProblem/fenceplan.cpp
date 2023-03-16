#include <iostream>

using namespace::std;
#include<vector>
#define REP(i, b) for(int i  = 0; i < b; i++)
#define LL long long

struct cow{
    vector<int> mooNbor;
    int xCoor, yCoor;
    bool visited = 0;
};
int N, M;
int maxX, maxY, minY, minX;
vector<cow> cows;


//floodfills to find moo groups
void floodfill(int cowIndex){
    cows[cowIndex].visited = 1;

    for(int nbor: cows[cowIndex].mooNbor){
        if(cows[nbor].visited == false){
            maxX = max(cows[nbor].xCoor, maxX); 
            maxY = max(cows[nbor].yCoor, maxY); 
            minY = min(cows[nbor].yCoor, minY); 
            minX = min(cows[nbor].xCoor, minX); 
            floodfill(nbor);
        }
    }
}

int main() {
    freopen("fenceplan.in", "r", stdin); 
    freopen("fenceplan.out", "w", stdout); 
    cin>>N>>M;

    //feed in coordinates and moo pairs
    cow tempCow; 
    REP(i, N){
        cin>>tempCow.xCoor>>tempCow.yCoor;
        cows.push_back(tempCow);
    }

    int cowa, cowb;
    REP(i, M){
        cin>>cowa>>cowb;
        cowa--; cowb--;
        cows[cowa].mooNbor.push_back(cowb);
        cows[cowb].mooNbor.push_back(cowa);     
    }

    //find min perimeter for any moo group
    LL minPerimeter = (LL) 100000001*100000001; 
    REP(i, N){
        if(!cows[i].visited){
            maxX = cows[i].xCoor; maxY = cows[i].yCoor;
            minX = cows[i].xCoor; minY = cows[i].yCoor; 
            floodfill(i);
            LL thisPerimeter = (LL) 2UL*(maxX - minX + maxY - minY); 
            minPerimeter = min(minPerimeter,  thisPerimeter);
        }
    }

    cout<<minPerimeter<<endl;
}