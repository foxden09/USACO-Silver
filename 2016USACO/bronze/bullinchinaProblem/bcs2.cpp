#include<iostream>
#include<algorithm>

using namespace::std;
#include<vector>

const int maxSize = 3*8-2;
int N, K; 
int pieces[10][8][8]; int origPiece[maxSize][maxSize];
vector<int> allValid; vector<int> thisArrange;

bool isMatching(int origChar, int possChar, int row_w, int col_q){
    //ok if this piece is dot && orig is hash (2)
    // ok if this piece is hash && orig is hash (1)
    // ok if this piece is dot && orig is dot (0)
    // not ok if this piece is hash && orig is not hash

    // not ok if piece out of bounds
    /*if(((col_q>=N-1&&col_q<=2*N-2)==false)&&((row_w>=N-1&&row_w<=2*N-2)==false)){
        if(possChar==1) return false;
    }*/
    if(origChar == 1 && possChar == 0) thisArrange.push_back(2);
    else if(origChar == 1 && possChar == 1) thisArrange.push_back(1);
    else if(origChar == 0 && possChar == 0) thisArrange.push_back(0);
    else if(origChar == 0 && possChar == 1) return false;

    return true;
}


void validArrange(int i, int row, int col){
    thisArrange.clear();
    
    //check if arrangement valid
    for(int w = 0; w < N; w++){
        for(int q = 0; q < N; q++){
            if(isMatching(origPiece[row+w][col+q], pieces[i][w][q], row+w, col+q)==true);
            else return;
        } 
    }

    for(int w = 0; w < N; w++){
        for(int q = 0; q < N; q++){
            cout<<origPiece[row+w][col+q]<<" ";
        } 
        cout<<endl;
    }
    cout<<row<<" "<<col<<endl;
    allValid.insert(allValid.end(), thisArrange.begin(), thisArrange.end());

}

int main(){
    freopen("bcs.in", "r", stdin);
    freopen("bsc.out", "w", stdout);
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

    
    for(int i = 0; i < allValid.size()/(N*N); i++){
        for(int k = 0; k < N; k++){
            for(int j = 0; j < N; j++){
                cout<<allValid[i*N*N+k*N+j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl<<endl;
    }
    
}