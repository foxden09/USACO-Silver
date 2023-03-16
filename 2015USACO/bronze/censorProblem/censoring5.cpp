#include<iostream>
#include<fstream>
#include<string>

using namespace::std;
#include<vector>

struct partial{
    int indexof, howmanymatchT;
};

int main(){
    ofstream fout ("censor.out");
    ifstream fin ("censor.in");
    std::string S, T;
    fin>>S>>T;
    vector<partial> allPartials; partial temp; 
    

    for(int i = 0; i < S.length(); i++){
        if(S[i]==T[0]){
            temp.indexof = i; temp.howmanymatchT=1; 
            allPartials.push_back(temp); 
        }
    }
}