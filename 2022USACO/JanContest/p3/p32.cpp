#include <iostream>
#include <vector>

using namespace::std;
#define FOR(i, b) for(int i = 0; i < b; i++)
#define sz size()
vector<int> A;
int N;
string s;
void moveRight(int l, int r);

void moveLeft(int l, int r){
    int i = r;
    while(i >= l){
        if(A[i] == 1){ if(i<r) moveRight(i+1, r); r = i-1; }
        s.push_back('L');
        A[i]--; 
        i--; 
    }
    if(A[l] > 0) moveRight(l, r); //cycle
}                                      

void moveRight(int l, int r){
    int i = l;
    while(i <= r){
        s.push_back('R');
        A[i]--;
        i++;
    }
    moveLeft(l, r);
}


int main() {
    //freopen("p3.in", "r", stdin);
    //freopen("p3.out", "w", stdout);
    cin>>N;
    A.resize(N);
    FOR(i, N) cin>>A[i];
    moveRight(0, N-1);
    cout<<s<<endl;
    //keep going right till end 
    //keep going left till find 1 or beginning
    
}