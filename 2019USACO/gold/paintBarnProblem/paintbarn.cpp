#include <iostream>

using namespace::std;
#define FOR(i, a, b) for(int i = a; i < b; i++)

int N, K;
int barn[202][202] = {0}, psum[202][202] = {0}; 

//mark +1 and -1 
void markEnds(int row1, int col1, int row2, int col2){
    int height = row1 - row2;
    FOR(j, 0, height){
        barn[row1 - j][col1] += 1;
        barn[row1 - j][col2] += -1; 
    }
}


int main() {
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
    cin>>N>>K;
    
    //feed in rectangles & mark ends & mark rect boundaries
    int row1, row2, col1, col2;
    int LL_x = 0, LL_y = 202, UR_x = 202, UR_y = 0;
    FOR(i, 0, N){
       cin>>col1>>row1>>col2>>row2; 
       row1 = 201 - row1; 
       row2 = 201 - row2;

       markEnds(row1, col1, row2, col2);

       LL_x = max(LL_x, row1); LL_y = min(LL_y, col1);
       UR_x = min(UR_x, row2); UR_y = max(UR_y, col2);
    }
    LL_x++; UR_y++; UR_x++;

    //loop over barn array, simulating coats # to find where has K coats
    int coats = 0, Kcoats = 0;
    FOR(i, UR_x, LL_x){
        FOR(j, LL_y, UR_y){
            coats += barn[i][j];
            if(coats == K) Kcoats++;

            //set up psum array
            if(coats == K) psum[i][j] = -1;
            else if(coats == K-1) psum[i][j] = 1;
            else psum[i][j] = 0;
        }
    } 
    cout<<Kcoats<<endl;
    

    FOR(i, UR_x, LL_x){
        FOR(j, LL_y, UR_y){
            cout<<psum[i][j]<<" ";
        }
        cout<<endl;
    }

    //build prefix sum array
    FOR(i, UR_x, LL_x){
        FOR(j, LL_y + 1, UR_y){
            psum[i][j] += psum[i][j-1];
        }
    }
    
    FOR(i, UR_x, LL_x){
        FOR(j, LL_y, UR_y){
            cout<<psum[i][j]<<" ";
        }
        cout<<endl;
    }

                                                                                                                                    
}


/*
FOR(i, UR_x, LL_x){
    FOR(j, LL_y, UR_y){
        cout<<psum[i][j]<<" ";
    }
    cout<<endl;
}
*/