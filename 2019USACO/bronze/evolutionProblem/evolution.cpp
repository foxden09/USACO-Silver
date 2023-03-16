#include <iostream>
#include<bitset>
#include<string>
#include<algorithm>

using namespace::std;
#include<vector>
#define REP(i, b) for(int i = 0; i < b; i++)

int N; int features[25] = {0}; 

//sorts by number of features
bool sortSize(const vector<string>& v1, const vector<string> &v2){
    return v1.size() < v2.size();
}

//check if all features unique
int main() {
    freopen("evolution.in", "r", stdin); 
    freopen("evolution.out", "w", stdout); 
    cin>>N;
    int predate[25] = {0};
    vector<vector<string>> groups (N);

    //feed in populations
    int K;
    REP(i, N){
        cin>>K;
        groups[i].resize(K);
        REP(j, K) cin>>groups[i][j];
        sort(groups[i].begin(), groups[i].end());
    }
    sort(groups.begin(), groups.end(), sortSize);

   REP(i, N){
       
   }


   //largest subdate-- -> if not unique, then check for nearest blank
   //nearest blank contains substring of that
   //if noone subdates you and you are not unique screwed
   //check if you predate someboedy, cant be already predated screwed

    //if it has one feature then a blank must exist explaining it   
    //start with the smallest
    // a blank - a substring
}