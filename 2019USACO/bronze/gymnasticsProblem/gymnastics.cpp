#include<iostream>
#include<fstream>
#include<algorithm>

using namespace::std;
#include<vector>

#define indexOf(a, b) min(a,b)*100+max(a,b)

int main(){
    ofstream fout ("gymnastics.out");
    ifstream fin("gymnastics.in");

    int whatPairs[3000], K, N, temp, tempIndex;
    vector <int> currentPairs;

    fin>>K>>N;
    int numofconsistent = N*(N-1)/2;
    
    //rest of pairs
    for(int i = 0; i < K; i++){
        currentPairs.clear();
        for(int y = 0; y < N; y++){
            fin>>temp; currentPairs.push_back(temp);
        }

        for(int y = 0; y < N-1; y++){
            for(int j = y+1; j < N; j++){
                tempIndex = indexOf(currentPairs[y], currentPairs[j]); //what index in whatPairs points to this pair 
                if(i==0){
                    whatPairs[indexOf(currentPairs[y], currentPairs[j])] = currentPairs[y]*100+currentPairs[j]; //set pair to their first ordering 
                }
                else if(whatPairs[tempIndex]==-1){
                    continue; //skip if already know it changed
                }
                else if(whatPairs[tempIndex]!=(currentPairs[y]*100+currentPairs[j])){
                    numofconsistent--; whatPairs[tempIndex] = -1; //if ordering different, numofconsisten goes down 
                }
            }
        }
    }
    fout<<numofconsistent<<endl;
}