#include <iostream>

using namespace::std;
#define FOR(i, b) for(int i = 0; i < b; i++)
int N, K;
int barn[1010][1010] = {0}; 

//mark +1 and -1 
//! figure out for one sqaure big
void markEnds(int row1, int col1, int row2, int col2){
    int height = row1 - row2;
    FOR(j, height){
        barn[row1 - j][col1] += 1;
        barn[row1 - j][col2] += -1; 
    }

}


int main() {
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
    cin>>N>>K;
    
    //feed in rectangles & mark ends
    int row1, row2, col1, col2;
    FOR(i, N){
       cin>>col1>>row1>>col2>>row2; 
       markEnds(1009 - row1, col1, 1009 - row2, col2);
    }

    //loop over barn array, simulating coats # to find where has K coats
    int coats = 0, Kcoats = 0;
    FOR(i, 1010){
        FOR(j, 1010){
            coats += barn[i][j];
            if(coats == K) Kcoats++;
        }
    } 
    cout<<Kcoats<<endl;
}


