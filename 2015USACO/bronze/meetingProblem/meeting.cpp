#include <iostream>
using namespace::std;
#include<unordered_set>
#include<vector>

int N, M;
int Bruntime = 0, Eruntime = 0;
unordered_set<int> Btimes, Etimes;
struct path{
    int leadsTo, Btime, Etime;
};
vector< vector<path> > whereLeads; //index 0 not used

void followPath(int currentIndex){  
    if(currentIndex == N){
        Btimes.insert(Bruntime);
        Etimes.insert(Eruntime);
    }

    for(auto &it: whereLeads[currentIndex]){
        Bruntime += it.Btime;
        Eruntime += it.Etime; 
        followPath(it.leadsTo); 
        Bruntime -= it.Btime;
        Eruntime -= it.Etime; 
    }
}


int main() {
    freopen("meeting.in", "r", stdin); 
    freopen("meeting.out", "w", stdout); 
    cin>>N>>M;

    //feed in paths and their times to whereLeads
    int A, B, C, D;
    whereLeads.resize(17);
    for(int i = 0; i < M; i++){
        cin>>A>>B>>C>>D;

        path tempPath; 
        tempPath.leadsTo = B; tempPath.Btime = C; tempPath.Etime = D;
        whereLeads[A].push_back(tempPath);
    }

    followPath(1);

    //output min of interesection of sets
    int minTime = 1000000000;
    for(auto &it: Btimes){
        if(Etimes.count(it) > 0){
            minTime = min(minTime, it);
        }
    }
    if(minTime == 1000000000) cout<<"IMPOSSIBLE"<<endl;
    else cout<<minTime<<endl;
}