#include <iostream>

using namespace::std;
#include<vector>
#include<string>
#include<unordered_set>

int N, K;
vector< unordered_set<string> > visitedDances; //K_i -> "1234"
vector< pair<int, int> > changes;


//converts current position into string form 
string tostring(int *positions){
    string stringPositions;
    for(int i = 0; i < N; i++){
        char tempPos = '0' + positions[i];
        stringPositions += tempPos;
    }
    return stringPositions;
}

int main() {
    freopen("mooves.in", "r", stdin); 
    freopen("mooves.out", "w", stdout); 
    cin>>N>>K;
    int *positions = new int[N]; // currentPos -> cow
    bool *haveVisited = new bool[N*N]; //cowa * N + cowB
    visitedDances.resize(K+1);

    for(int i = 0; i < N; i++){
        haveVisited[i*N+i] = 1;
        positions[i] = i;
    }

    //feed in K swaps
    int posa, posb; 
    for(int i = 0; i < K; i++){
        cin>>posa>>posb; posa--; posb--;
        changes.push_back(make_pair(posa, posb));
    }

    //while haven't visited same dance, swap
    bool getOut = 0; 
    int tempPos;
    string stringPos = tostring(positions);
    visitedDances[K-1].insert(stringPos);

    while(!getOut){
        for(int i = 0; i < K; i++){
            posa = changes[i].first; posb = changes[i].second;
            /*cout<<posa<<" "<<posb<<endl;
            for(int i = 0; i < N; i++) cout<<positions[i]<<" ";
            for(int i = 0; i < N; i++){
                for(int j  = 0; j < N; j++){
                    cout<<haveVisited[i*N + j]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;*/
           
    
            //swap 
            tempPos = positions[posa];
            positions[posa] = positions[posb];
            positions[posb] = tempPos; 

            haveVisited[positions[posa]*N + posa] = 1;
            haveVisited[positions[posb]*N + posb] = 1;

            //check whether dance positions visited
            stringPos = tostring(positions);
            if(visitedDances[i].count(stringPos) > 0) getOut = true; //!maybe break
            else visitedDances[i].insert(stringPos);
        }
    }
    
    for(int i = 0; i < N; i++){
        int countVisited = 0; 
        for(int j = 0; j < N; j++){
            if(haveVisited[i*N + j]) countVisited++;
        }
        cout<<countVisited<<endl;
    }
  
    delete[] haveVisited;
}