#include <iostream>

using namespace::std;
#include<vector>
#define REP(i, b) for(int i = 0; i < b; i++)

int topRow, topCol, N; 
vector< vector<int> > beauty; 
int oneType[1001] = {0, 1}, secondType[1001] = {1, 0};
int rowTypes[4][2][1001]; 

//rotate beauty board
void rotate90(){
    vector< vector<int> > newBeauty;
    newBeauty.resize(N);

    REP(j, N){
        for(int i = N-1; i >= 0; i--){
            newBeauty[j].push_back(beauty[i][j]);
        }
    }
    beauty = newBeauty;
}

//list all row types | 0: X | 1: C
void createRowTypes(){
    for(int i = 2; i < N; i++) oneType[i] = oneType[i%2]; 
    for(int i = 2; i < N; i++) secondType[i] = secondType[i%2];

    REP(i, N){
        rowTypes[0][0][i] = oneType[i]; rowTypes[0][1][i] = secondType[i];
        rowTypes[1][0][i] = oneType[i]; rowTypes[1][1][i] = oneType[i];
        rowTypes[2][0][i] = secondType[i]; rowTypes[2][1][i] = oneType[i];
        rowTypes[3][0][i] = secondType[i]; rowTypes[3][1][i] = secondType[i];
    }
}

//calc which row type is optimal for 2 row submatrix
int calcBestRow(int indexR){
    int maxSum = 0, runningSum = 0;
   
    REP(rowType, 4){
        runningSum = 0;

        REP(i, N){
            if(rowTypes[rowType][0][i] == 1) runningSum += beauty[indexR][i];
            if(rowTypes[rowType][1][i] == 1) runningSum += beauty[indexR+1][i];
        } 
        maxSum = max(runningSum, maxSum);
    }
    return maxSum;
}

//loop over every row in matrix
//!exception for odd
int overallMax(){
    int maxOverall = 0;
    REP(i, (int) N/2){
        maxOverall += calcBestRow(i*2);
    }
    return maxOverall;
}

int main() {
    freopen("spaced.in", "r", stdin); 
    freopen("spaced.out", "w", stdout); 
    cin>>N;

    //feed in beauty grid
    int temp; 
    REP(i, N){
        beauty.push_back(vector<int>());
        REP(j, N){
            cin>>temp;
            beauty[i].push_back(temp);
        }
    }
 
    //create row types
    createRowTypes(); 

    topRow = overallMax();
    rotate90();
    topCol = overallMax(); 
    cout<<max(topRow, topCol)<<endl;

}