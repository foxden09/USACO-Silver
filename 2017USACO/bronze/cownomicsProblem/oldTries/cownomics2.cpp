#include<iostream>
#include<fstream>
#include<string>

using namespace::std;
#include<vector>

int convertChartoInt(char a){
    if(a=='A') return 0;
    else if(a=='G') return 1;
    else if(a=='C') return 2; 
    else if(a=='T') return 3;
    return -1;
}

int main(){
    ofstream fout ("cownomics.out");
    ifstream fin ("cownomics.in");
    int N, M; fin>>N>>M; fin.ignore();
    vector<string> plaingenomes, cursedgenomes; string temp1; 
    int countOftriplets = 0; int matches[64]{}, temp; bool doesntMatch = true;

    //append to vectors
    for(int i = 0; i < N*2; i++){
        getline(fin, temp1);
        if(i<N) cursedgenomes.push_back(temp1);
        else plaingenomes.push_back(temp1);
    }

    //loop over all indices
    for(int firstIndex = 0; firstIndex < M-2; firstIndex++){
        for(int secondIndex = firstIndex+1; secondIndex < M-1; secondIndex++){
            for(int thirdIndex = secondIndex+1; thirdIndex < M; thirdIndex++){
                for(int y = 0; y < 64; y++) matches[y] = 0; doesntMatch = true; 
                for(int i = 0; i < N; i++){
                    if(matches[convertChartoInt((char) cursedgenomes[i][firstIndex])*16+convertChartoInt((char) cursedgenomes[i][secondIndex])*4+convertChartoInt((char) cursedgenomes[i][thirdIndex])]==0){
                        matches[convertChartoInt((char) cursedgenomes[i][firstIndex])*16+convertChartoInt((char) cursedgenomes[i][secondIndex])*4+convertChartoInt((char) cursedgenomes[i][thirdIndex])] =1;
                        break;
                    }
                }
                for(int i = 0; i < N; i++){
                    temp = convertChartoInt((char) plaingenomes[i][firstIndex])*16+convertChartoInt((char)plaingenomes[i][secondIndex])*4+convertChartoInt((char) plaingenomes[i][thirdIndex]);
                    if(matches[temp]>0){
                        doesntMatch = false; break; 
                    }
                }
                if(doesntMatch==true){
                    /*for(int i = 0; i < N; i++){
                        cout<<cursedgenomes[i][firstIndex]<<cursedgenomes[i][secondIndex]<<cursedgenomes[i][thirdIndex];
                        cout<<" "<<plaingenomes[i][firstIndex]<<plaingenomes[i][secondIndex]<<plaingenomes[i][thirdIndex]<<endl;
                    }*/
                    countOftriplets++;
                } 
            }
        }
    }
    fout<<countOftriplets<<endl;
}