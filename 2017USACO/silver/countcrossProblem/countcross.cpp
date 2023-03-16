#include <iostream>

using namespace::std;
#include<vector>
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define calcPairs(n) (n)*(n-1)/2 

int N, K, R;
int connectedPairs = 0, cowCount = 0;
int goX[4] = {0, 1, 0, -1};
int goY[4] = {1, 0, -1, 0};

class field{
    public:
        int x, y;
        bool hasCow = 0;
        bool visited = 0;
        vector<int> roadX, roadY;  

        //checks if neighbor has road
        bool hasRoad(int newI, int newJ);
};

bool field::hasRoad(int newI, int newJ){
    FOR(r, 0, roadX.size()){
        if(newI == roadX[r] && newJ == roadY[r]) return 1;
    }
    return 0;
}

field fields[101][101];

//flood fill dfs to find connected pair of cows
    //ignore out of bounds, visited, and road
void dfs(int i, int j){
    if(i < 1 || j < 1 || i > N || j > N) return;    
    if(fields[i][j].visited) return;   

    if(fields[i][j].hasCow) cowCount++;
    fields[i][j].visited = true;

    //dfs valid neighbors
    FOR(dir, 0, 4){
        int newI = i + goX[dir];
        int newJ = j + goY[dir];
        if(!fields[i][j].hasRoad(newI, newJ)) dfs(newI, newJ);
    }
}

int main() {
    freopen("countcross.in", "r", stdin); 
    freopen("countcross.out", "w", stdout); 
    cin>>N>>K>>R;

    //set coordinates of fields && mark neighbors
    FOR(i, 1, N+1){
        FOR(j, 1, N+1){
            fields[i][j].x = i;
            fields[i][j].y = j;
        }
    }

    //read in road neighbors
    int aX, aY, bX, bY;
    FOR(i, 0, R){
        cin>>aX>>aY>>bX>>bY;
        fields[aX][aY].roadX.push_back(bX); fields[aX][aY].roadY.push_back(bY);
        fields[bX][bY].roadX.push_back(aX); fields[bX][bY].roadY.push_back(aY);
    }

    //mark where cows located
    FOR(i, 0, K){
        cin>>aX>>aY;
        fields[aX][aY].hasCow = 1;
    }

    //initiate flood fill dfs everywhere cow present & not visited
    FOR(i, 1, N+1){
        FOR(j, 1, N+1){
            if(fields[i][j].hasCow && !fields[i][j].visited){
                cowCount = 0;
                dfs(i, j);
                connectedPairs += calcPairs(cowCount);
            }
        }
    }
    cout<<calcPairs(K)-connectedPairs<<endl;
}