#include <iostream>

using namespace::std;
#include <unordered_map>
#include <vector>
#define FOR(i, b) for(int i = 0; i < b; i++)
#define MYMOD 1000000007;
typedef long long ll;

int N;
ll area_sum = 0;

int main() {
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    cin>>N;

    //feed in and map x & y values 
    unordered_map<int, vector<int>> x_map, y_map;
    unordered_map<int, int> x_sum, y_sum;
    FOR(i, N){
        int x_i, y_i;
        cin>>x_i>>y_i;
        x_map[x_i].push_back(y_i);
        x_sum[x_i] += y_i;
        
        y_map[y_i].push_back(x_i);
        y_sum[y_i] += x_i;
    }   

    //loop over x_map keys 
    for(auto &x_i: x_map){
        for(int &a : x_i.second){
            if(y_map[a].size() == 1 || x_i.second.size() == 1) continue;
            cout<<x_i.first<<endl;
            //horz side
            int y_sz = y_map[a].size();
            ll hsides = (ll) y_sum[a] - x_i.first * y_sz;

            //vertical side & calc area
            int x_sz = x_i.second.size();
            
            ll big_a = a * x_sz;
           // cout<<x_sum[x_i.first]<<" "<<a<<" "<<x_sz<<" "<<big_a<<endl;
            ll vside = (ll) x_sum[x_i.first] - big_a;
            //cout<<hsides<<" "<<abs((ll) x_sum[x_i.first] - big_a)<<endl;
            ll tings = abs((ll) vside % 1000000007);
            ll tings2 = abs((ll) hsides % 1000000007);
            ll tings3 = (tings * tings2 ) % MYMOD;
            cout<<tings<<" "<<tings2<<" "<<tings3<<endl;
            area_sum += (ll) abs(vside  * hsides) % MYMOD;                
        }
    }
    int modsum = area_sum % MYMOD;
    cout<<modsum<<endl;
}

//! unsigned long long