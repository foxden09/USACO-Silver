#include <iostream>

using namespace::std;
#include <vector>
#define FOR(i, b) for(int i = 0; i < b; i++)
int A, B, C, tA, tB, tC, N;
bool visited[7];
//! set abc to -1

bool ord(){ 
    if(tA == -1 && tB == -1 || tB == -1 && tC == -1 || tA == -1 && tC == -1) return true; 
    if(tA == -1) return tB <= tC;
    if(tB == -1) return tA <= tC;
    if(tC == -1) return tA <= tB;
    return tA <= tB && tB <= tC; 
}
bool try_sum(int num, int &i1, int &i2){  //try A + B or B + C or A + C
    if(i1 != -1 && i2 != -1) return num == i1 + i2;
    if(i1 == -1) i1 = num - i2;
    else if(i2 == -1) i2 = num - i1;
    return ord();
}

bool try_one(int num, int &i1){ //try A or B or C
    if(i1 != -1 && i1 != num) return false;
    i1 = num; 
    return ord();
}

bool try_pos(int num, int pos){ //try out specified position
    tA = A, tB = B, tC = C; 
    if(visited[pos]) return false;
    else visited[pos] = true;

    if(pos == 0) return try_one(num, tA);
    else if(pos == 1) return try_one(num, tB);
    else if(pos == 2) return try_one(num, tC);
    
    else if(pos == 3) return try_sum(num, tA, tB);
    else if(pos == 4) return try_sum(num, tB, tC);
    else if(pos == 5) return try_sum(num, tA, tC);

    else if(pos == 6) return num == A+B+C;
    return false;
}


int main() {
    freopen("abc.in", "r", stdin);
    freopen("abc.out", "w", stdout);

    
    //cin>>N;
    A = -1; B = -1; C = -1;
    //! reset a b c
}
