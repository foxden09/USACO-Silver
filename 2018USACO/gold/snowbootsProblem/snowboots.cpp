#include <iostream>
#include <algorithm>
#include <climits>
using namespace::std;
#include <vector>
#include <set>
#define FOR(i, b) for(int i = 0; i < b; i++)
typedef vector<pair<int, int>> vpair; 
int N, B;

struct Row{
    int lhs, rhs, elems;    //elems = # of consecutive elements contained
    bool operator<(const Row& other) const { return lhs < other.lhs; }
};
typedef set<Row> myset;
typedef myset::iterator myit;
struct Boot{
    int depth, stepsz, index;
    bool operator<(const Boot& rhs) const { return depth > rhs.depth; }
};

int main() {
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);
    cin>>N>>B;
    
    //feed in & sort roads by depth
    vpair roads (N);
    int rd_depth; 
    FOR(i, N){
        cin>>rd_depth;
        roads[i] = {rd_depth, i};
    }
    sort(roads.begin(), roads.end());

    //feed in & sort boots by depth
    vector<Boot> boots (B);    // depth, stepsz
    vector<bool> can_trek (B);
    FOR(i, B){
        cin>>boots[i].depth>>boots[i].stepsz;
        boots[i].index = i;
    }
    sort(boots.begin(), boots.end());


    //find largest consecutive pairing 
    int it = N - 1, max_row = 0; 
    myset indices = {{INT_MIN, INT_MIN, 0}, {INT_MAX, INT_MAX, 0}};
    FOR(i, B){
        int mydepth = boots[i].depth;
   
        while(it >= 0 && roads[it].first > mydepth){
            if(roads[it].first == 0 and (roads[it].second == 0 or roads[it].second == N - 1)) { it--; continue; }
            Row myrow = {roads[it].second, roads[it].second, 1};
            myit rnbor = indices.lower_bound(myrow); 
            myit lnbor = prev(rnbor);
             
            if(rnbor->lhs - myrow.rhs == 1){
                myrow.rhs = rnbor->rhs;
                myrow.elems += rnbor->elems;
                indices.erase(rnbor);
            }
            if(myrow.lhs - lnbor->rhs == 1){
                myrow.lhs = lnbor->lhs;
                myrow.elems += lnbor->elems;
                indices.erase(lnbor);
            }
            indices.insert(myrow);
            max_row = max(myrow.elems, max_row);
            it--;
        }    
        
        if(boots[i].stepsz > max_row) can_trek[boots[i].index] = 1;     //update can_trek 
    }
    
    for(bool trek : can_trek) cout<<trek<<endl;
}

/*
for(Row r : indices){
            if(r.lhs == INT_MAX || r.lhs == INT_MIN) continue;
            cout<<"lhs: "<<r.lhs<<" rhs: "<<r.rhs<<" elems: "<<r.elems<<endl;
        }
        cout<<endl;
*/