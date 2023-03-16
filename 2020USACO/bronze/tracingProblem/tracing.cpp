#include<iostream>
#include<string>
#include<algorithm>

using namespace::std;
#include<vector>

int N, T; string statuses; int maxK = 0; int minK = 10000000;
int totalZeroCows = 0;

struct Record{
    int t, x, y;
    bool validZeroCow = 0;
};
bool cmpT(const Record &a, const Record &b){
    return a.t < b.t;
}
bool cmpX(const Record &a, const Record &b){
    return a.x < b.x;
}
vector<Record> records;

//compare K
void simulateK(int zeroCow, int tempK){
    vector<int> tempStatuses; vector<int> tempShakes;
    for(int i = 0; i < N; i++){
        tempStatuses.push_back(0); tempShakes.push_back(0);
    } 

    tempStatuses[zeroCow] = 1;
    //simulate spreading
    for(int i = 0; i < T; i++){
        int ithCow = records[i].x-1; int secondCow = records[i].y-1;
        if(tempStatuses[ithCow]==1) tempShakes[ithCow]++;
        if(tempStatuses[secondCow]==1) tempShakes[secondCow]++;
        
        if(tempShakes[ithCow] <= tempK && tempStatuses[ithCow]==1) tempStatuses[secondCow]=1; //infected passes onto another infected, shakes < tempK
        else if(tempShakes[secondCow] <= tempK && tempStatuses[secondCow]==1) tempStatuses[ithCow]=1;
    }

    //check if tempStatuses mathces 1100
    for(int i = 0; i < N; i++){
        char statusChar = '0'+tempStatuses[i];
        if(statusChar!=statuses[i]) return;
    } 
    maxK = max(maxK, tempK); minK = min(minK, tempK); 
    if(records[zeroCow].validZeroCow==0){
        totalZeroCows++;
        records[zeroCow].validZeroCow=1;
    }
}

int main(){
    freopen("tracing.in", "r", stdin);
    freopen("tracing.out", "w", stdout);
    cin>>N>>T>>statuses;

    //sort records by time
    for(int i = 0; i < T; i++){
        Record tempRecord;
        cin>>tempRecord.t>>tempRecord.x>>tempRecord.y; 
        records.push_back(tempRecord);
    }

    //find max interactions (~K)
    sort(records.begin(), records.end(), cmpX);
    int maxInteract = 1, runningCount = 1;

    for(int i = 1; i < T; i++){
        if(records[i-1].x==records[i].x) runningCount++;
        else runningCount = 1;
        maxInteract = max(maxInteract, runningCount);
    }
  
    sort(records.begin(), records.end(), cmpT); //sort by time
    

    //loop over "1"s as x_0
    for(int zeroCow = 0; zeroCow < N; zeroCow++){

        if(statuses[zeroCow]=='1'){
            //simulate virus spread for each K
            for(int tempK = 0; tempK <= maxInteract; tempK++){ 
                simulateK(zeroCow, tempK);
            }
        }
    }

    //cout
    cout<<totalZeroCows<<" "<<minK<<" ";
    if(maxK==maxInteract) cout<<"Infinity"<<endl;
    else cout<<maxK<<endl;
}