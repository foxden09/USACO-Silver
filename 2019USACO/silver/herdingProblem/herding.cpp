#include <iostream>
#include <algorithm>
using namespace::std;
#include <vector>
typedef vector<int> vint;
#define FOR(i, b) for(int i = 0; i < b; i++)
int N;

void min_moves(vint &cows){
    int leftp = 0, rightp = 0, myrange = 0, maxcows = 0, minmoves = 0; 

    //find max # of cows in N-large window
    while(leftp < N && rightp < N){
        myrange = cows[rightp] - cows[leftp] + 1;       //window size

        if(myrange <= N){
            int cowq = rightp - leftp + 1;              //num of cows
            if(cowq == N - 1 && myrange == N - 1) maxcows = max(N - 2, maxcows);    //special case 1110001 needs 2 moves
            else maxcows = max(cowq, maxcows);       

            rightp++;
        }
        else leftp++;
    }
    cout<<N - maxcows<<endl;
}

int main() {
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);

    //feed & sort in cows
    cin>>N;
    vint cows (N);
    FOR(i, N) cin>>cows[i];
    sort(cows.begin(), cows.end());

    min_moves(cows);

    int max_moves = (cows[N-1] - cows[0])
    - min(cows[N-1]-cows[N-2], cows[1]-cows[0])     //sacrifice smallest starting gap
    - (N-2);                                        //remaining gaps
    cout<<max_moves<<endl;
}
