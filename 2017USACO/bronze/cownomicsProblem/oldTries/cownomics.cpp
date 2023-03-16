#include<iostream>
#include<fstream>
#include<string>

using namespace::std;
#include<vector>
//checks to see if any matches

int isThereMatch(vector<string> &genomes, int N, int firstIndex, int secondIndex, int thirdIndex, string &potentialMatch){
    string codon;
    for(int k = 0; k < N; k++){
        codon = string(1,genomes[k][firstIndex])+genomes[k][secondIndex]+genomes[k][thirdIndex]; 
        if(codon == potentialMatch){
            return 1;
        }
    }
    return 0;
}

bool goingThroughMatches(vector<string> &plaingenomes, vector<string> &cursedgenomes, int N, int firstIndex, int secondIndex, int thirdIndex){
    static string AGCT = "AGCT"; string tempString2; int counting = 0;
    
    for(int a = 0; a < 4; a++){
        for(int b = 0; b < 4; b++){
            for(int c = 0; c < 4; c++){
                counting = 0; tempString2 = string(1, AGCT[a])+AGCT[b]+AGCT[c];
                counting+=isThereMatch(cursedgenomes, N, firstIndex, secondIndex, thirdIndex, tempString2);
                counting+=isThereMatch(plaingenomes, N, firstIndex, secondIndex, thirdIndex, tempString2);
                if(counting==2) return false;
            }
        }
    }
    return true;
}

int main(){
    ofstream fout ("cownomics.out");
    ifstream fin ("cownomics.in");
    int N, M; fin>>N>>M; fin.ignore();
    string temp1;
    vector<string> plaingenomes, cursedgenomes; int countOftriplets = 0; 

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
                if(goingThroughMatches(plaingenomes, cursedgenomes, N, firstIndex, secondIndex, thirdIndex)==true){
                    countOftriplets++;
                }
            }
        }
    }
    fout<<countOftriplets<<endl;
    return 0;
}