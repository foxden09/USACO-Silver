#include<iostream>
#include<fstream>
#include<string>

using namespace::std;
#include<vector>
#define REP(i,a,b) for(int i = a; i < b; i++)

int findYeses(vector<string> &firstanimal, vector<string> &secondanimal){
    
}
//find max yeses in animal pair

int main(){
    ofstream fout("guess.out");
    ifstream fin("guess.in");
    int N, K; string tempString;
    fin>>N;
    vector<vector<string>> allAnimals;
    

    //append all animals to allAnimals and all attributes to allAttributes
    REP(i, 0, N){
        fin>>tempString>>K; allAnimals.push_back({});
        REP(y, 0, K){
            fin>>tempString; allAnimals[i].push_back(tempString);
        }
    }
    

    //loop over all animal pairs 


}