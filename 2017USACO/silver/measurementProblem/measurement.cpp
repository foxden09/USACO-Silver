#include <iostream>

using namespace::std;
#include <vector>
#include <unordered_map>
#include <set>
#define FOR(i, b) for(int i = 0; i < b; i++)
typedef pair<int, int> mypair;
typedef set<pair<int,int>> myset;
typedef unordered_map <int, int> mymap;

struct datarow{
    int day, cow, val;
    bool operator<(const datarow &rhs) const { return day < rhs.day; }
};

//check if pair is still valid
bool check_curr(mymap& cow2milk, mypair& cowpair){

}

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
    myset max_milks = milks, temp_max;
    int changes = 0;
    FOR(i, N){
        milks.insert({records[i].val, records[i].cow});

        //find max gallons produced
        int max_milk, index = milks.size() - 1;
        do{
            mypair currpair = milks[index];
            max_milk = milks[index].val;
        } while(milks[index].val == max_milk && index >= 0);
        
        
        while(records[index].val == max_milk && index >= 0){
            temp_max.insert({records[index].val, records[index].cow});
            index--;
        }

        if(temp_max != max_milks){
            changes++;
            max_milks = temp_max;
        }
        temp_max.clear();
    }
    cout<<changes<<endl;
        //check if valid
}
