#include<iostream>
#include<algorithm>

using namespace::std;
#include<vector>

const int maxSize = 3*8-2;
int N, K; 
int pieces[10][8][8]; int origPiece[maxSize][maxSize]; int playPiece[maxSize][maxSize];
int allValid[300][9][9]; int numOfValid = 0;

void validArrange(int i, int row, int col){
    copy(&origPiece[0][0], &origPiece[0][0]+maxSize*maxSize, &playPiece[0][0]);
    
    //check if arrangement valid
    for(int w = 0; w < N; w++){
        for(int q = 0; q < N; q++){

            //check how overlap 
            int origChar = origPiece[row+w][col+q]; int possChar = pieces[i][w][q];
            if(origChar == 1 && possChar == 1) playPiece[row+w][col+q] = 2;
            else if(origChar == 0 && possChar == 1) return;
        } 
    }

    //append to allValid if valid
    for(int w = 0; w < N; w++){
        for(int q = 0; q < N; q++){
            allValid[numOfValid][w][q] = playPiece[w+N-1][q+N-1]; 
        } 
    } 
    allValid[numOfValid][8][8] = i+1; //signifies which piece it is
    numOfValid++;
}

bool doFit(int firstPiece, int secondPiece){
    //checks if pieces fit together
    for(int w = 0; w < N; w++){
        for(int q = 0; q < N; q++){
            int firstOne = allValid[firstPiece][w][q], secondOne = allValid[secondPiece][w][q];
            if(firstOne==0&&secondOne!=0) return false;
            else if(firstOne==1&&secondOne!=2) return false;
            else if(firstOne==2&&secondOne!=1) return false; 
        }
    }
    return true; 
}

int main(){
    freopen("bcs.in", "r", stdin);
    freopen("bcs.out", "w", stdout);
    cin>>N>>K;
    char tempPiece;
 
    //append original piece
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>tempPiece;
            if(tempPiece=='#') origPiece[i+N-1][j+N-1] = 1;
            else if(tempPiece=='.') origPiece[i+N-1][j+N-1] = 0;
        }
    }

    //append pieces to 2D vector K*N^2
    for(int i = 0; i < K; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                cin>>tempPiece;
                if(tempPiece=='#') pieces[i][j][k] = 1;
                else if(tempPiece=='.') pieces[i][j][k] = 0;
            }
        }
    }

    //loop over pieces as "first"
    for(int i = 0; i < K; i++){
        
        //check over possible arrangements
        for(int row = 0; row < 2*N-1; row++){
            for(int col = 0; col < 2*N-1; col++){
                validArrange(i, row, col);
            }   
        }
    }
    
    //loop over possible pairings
    for(int firstPiece = 0; firstPiece < numOfValid-1; firstPiece++){
        for(int secondPiece = firstPiece+1; secondPiece < numOfValid; secondPiece++){
            if(doFit(firstPiece, secondPiece)==true){
                cout<<allValid[firstPiece][8][8]<<" "<<allValid[secondPiece][8][8]<<endl;
                break;
            }
        }
    }
}