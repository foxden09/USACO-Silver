#include<iostream>
#include<fstream>
#include<string>
#define REP(i,a,b) for (int i = a; i < b; i++)

using namespace::std;
#include<vector>


bool isItMoo(string &S, string &T, int indexOfpartial){
    //returns true if partial is complete (moo)
    bool isItMoobool = true; int Acounts; vector<int> trueIndices;

    REP(i,0,T.length()){
        //skips A
        Acounts = 0;
        if(S[indexOfpartial+i]=='A'){
            Acounts = 1; 
            while(S[indexOfpartial+i+Acounts]=='A'){
                Acounts++; //! skip over T.length()
            }
        }
        //checks if match
        trueIndices.push_back(indexOfpartial+i+Acounts);
        if(S[indexOfpartial+i+Acounts]!=T[i]){
            isItMoobool = false;
        }
    }
    //replaces matched with 'AAA'
    if(isItMoobool==true){
        REP(j, 0, trueIndices.size()) S[trueIndices[j]]='A';
    }
    
    return isItMoobool;
}

void gobackward(string &S, string &T, int indexOfpartial){
    //*exception case if arrive at the beginning of S
    if(indexOfpartial<T.length()){
        return;
    }

    //find a previous "m" < T.length() away 
    for(int y = indexOfpartial-1; y>(indexOfpartial-T.length()); y--){
        //calls gobackward again if complete found
        if(S[y]==T[0]&&isItMoo(S, T, y)==true){
            gobackward(S, T, y);
            break;
        }
    }
    
}

int main(){
    ofstream fout ("censor.out");
    ifstream fin ("censor.in");
    std::string S, T;
    fin>>S>>T;

    //loop to find "m" T[0]
    for(int Siterator = 0; Siterator < S.length(); Siterator++){
        if(S[Siterator]==T[0]&&isItMoo(S, T, Siterator)==true){
            gobackward(S,T,Siterator);
        }
    }
    
    //prints out without A
    REP(i, 0, S.length()){
        if(S[i]!='A'){
            fout<<S[i];
        }
    }
    fout<<endl;
}