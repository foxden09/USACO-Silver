#include <iostream>
#include<algorithm>
using namespace::std;
#include <vector>
#include <unordered_map>
#include <set>
#define FOR(i, b) for(int i = 0; i < b; i++)
typedef pair<int, int> mypair;
typedef set<mypair> myset;
typedef myset::reverse_iterator myit; 
typedef unordered_map <int, int> mymap;

struct datarow{
    int day, cow, val;
    bool operator<(const datarow &rhs) const { return day < rhs.day; }
};

int main() {
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    int N, G;
    cin>>N>>G;
   
    mymap cow2milk;     //map cow id to current output
    myset milks;      //sort by value
    cow2milk[-1] = G;   milks.insert({G, -1});
    
    //feed in data & sort by day
    vector<datarow> records (N); 
    FOR(i, N){
        cin>>records[i].day>>records[i].cow>>records[i].val;
    }
    sort(records.begin(), records.end());


    //simulate putting max on wall
    set<int> max_milks = {-1}, temp_max;
    int changes = 0;
    FOR(i, N){
        //update cow record
        int currcow = records[i].cow, currval = records[i].val; 
        if(currcow == 6642676) cout<<currval<<endl;
        if(cow2milk.find(currcow) == cow2milk.end()) cow2milk[currcow] = G + currval;
        else{
            milks.erase({cow2milk[currcow], currcow}); 
            cow2milk[currcow] += currval;
        }
        milks.insert({cow2milk[currcow], currcow});
        

        //find max gallons produced
        int max_milk = -1;
        for(auto it = milks.rbegin(); it != milks.rend(); it++){
            mypair curr = *it; 
            if(max_milk != -1 && max_milk != curr.first) break;
            if(max_milk == -1) max_milk = curr.first; 
            temp_max.insert(curr.second);
        }
        
        //see if need to update board
        if(temp_max != max_milks){
            changes++;
            max_milks = temp_max;
        }
        temp_max.clear();
    }
    cout<<changes<<endl;
}

/*

*/