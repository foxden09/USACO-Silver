#include<iostream>
#include<fstream>
#include<string>
#define REP(i,a,b) for (int i = a; i < b; i++)

using namespace::std;
#include<vector>

int Siterator = 0;
bool isItMoo(string &S, string &T, int indexOfpartial){
    //returns true if partial is complete (moo)
    bool isItMoobool = true;

    REP(i,0,T.length()){
        if(S[indexOfpartial+i]!=T[i]){
            isItMoobool = false;
        }
    }
    //replaces matched with 'AAA'
    if(isItMoobool==true){
        Siterator=indexOfpartial-1;
        S.erase(indexOfpartial, T.length());
    }
    
    return isItMoobool;
}

void gobackward(string &S, string &T, int indexOfpartial){
    //*exception case if arrive at the beginning of S
    if(indexOfpartial<=0){
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
    while(Siterator<S.length()){
        if(S[Siterator]==T[0]&&isItMoo(S, T, Siterator)==true){
            gobackward(S,T,Siterator);
        }
        Siterator++;
    }
    
    fout<<S<<endl;
}