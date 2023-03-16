#include <iostream>

using namespace::std;
#include <vector>
#define FOR(i, a, b) for(int i = a; i < b; i++)

int main() {
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    int N, Q;
    cin>>N>>Q; N++;

    //create psum array
    vector< vector<int>> psum(N, vector<int>(3));
    int cow;
    FOR(i, 1, N){
        psum[i] = psum[i-1];

        cin>>cow;   cow--; 
        psum[i][cow]++;
    }

    //perform queries
    int cstart, cend;
    while(cin>>cstart>>cend){
        cstart--;
        cout<<psum[cend][0] - psum[cstart][0]<<" ";
        cout<<psum[cend][1] - psum[cstart][1]<<" ";
        cout<<psum[cend][2] - psum[cstart][2]<<endl;
    }
}
