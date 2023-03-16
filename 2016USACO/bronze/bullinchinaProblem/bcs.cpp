#include<iostream>
#include<algorithm>

using namespace::std;
#include<vector>

int N, K; 
vector<int> otherPiece; vector<int> origHashIndices; int pieces[10][64];

bool isMatching(int possibleOrig, int beginning, int i){
    //ok if this piece is dot && orig is hash (APPEND)
    // ok if this piece is hash && orig is hash
    // ok if this piece is dot && orig is dot
    // not ok if this piece is hash && orig is not hash
    for(int e = 0; e < N*N-beginning; e++){
        if(pieces[i][e+beginning]==1 && pieces[0][possibleOrig+e]==0) return false;
        cout<<pieces[i][e+beginning]<<" "<<pieces[0][possibleOrig+e]<<endl;
        //if((*pieces)[i*N*N+e]==0 && origHashIndices[w+e-beginning]==1) otherPiece.push_back(e);
        //else otherPiece.push_back(0);
    }
    return true;
}

void findOtherPiece(int i){
    otherPiece.clear();

    //loop over original hashtags as possible "beginning" first piece hashtag
    for(int y = 0; y < N*N; y++){
        //find "beginning" hashtag
        if(pieces[i][y]==1){
            for(int w = 0; w < origHashIndices.size(); w++){
                //cout<<origHashIndices[w];
                //cout<<" "<<isMatching(origHashIndices[w], y, i)<<endl;
                isMatching(origHashIndices[w], y, i);
            }
            break; 
        } 
    }

}

int main(){
    freopen("bcs.in", "r", stdin);
    freopen("bsc.out", "w", stdout);
    cin>>N>>K;
    char tempPiece;
 

    //append to 2D vector K*N^2
    for(int i = 0; i < K+1; i++){
        for(int j = 0; j < N*N; j++){
            cin>>tempPiece;
            if(tempPiece=='#') pieces[i][j] = 1;
            else if(tempPiece=='.') pieces[i][j] = 0;
        }
    }

    //find original Hash Indices
    for(int j = 0; j < N*N; j++){
        if(pieces[0][j]==1) origHashIndices.push_back(j);
    }

    //loop over pieces as "first"
    for(int i = 1; i < K; i++){
        //check if piece is matching
        findOtherPiece(i);
        
        for(int j = i+1; j < K+1; j++){
           //check if its the "other" piece
        }
    }


}