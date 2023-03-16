#include <iostream>

using namespace::std;
#define REP(i, a, b) for(int i = a; i < b; i++)

int main() {
    freopen("planting.in", "r", stdin); 
    freopen("planting.out", "w", stdout); 
    int N; cin>>N;
    int field1, field2;
    int maxChild = 0;
    int pathways[100001]= {0};

    //count neighbors
    REP(i, 1, N){
        cin>>field1>>field2; 
        pathways[field1]++;
        pathways[field2]++;
    } 

    //find max neighbors
    REP(i, 1, N+1){
        if(pathways[i+1]>maxChild) maxChild = pathways[i+1];
    }

    cout<<maxChild+1<<endl;
}