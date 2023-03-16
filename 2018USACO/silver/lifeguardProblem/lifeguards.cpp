#include<iostream>
#include<algorithm>
using namespace::std;
#include<vector>
#include<unordered_set>

int N;

struct myTime{
    int guardNum, theTime; 
    bool start; //0==endtime, 1==starttime
};
bool cmpTime(const myTime & a, const myTime & b){
    return a.theTime<b.theTime; 
}

int main() {
    freopen("lifeguards.in", "r", stdin); 
    freopen("lifeguards.out", "w", stdout); 
    vector<myTime> allTimes; 
    myTime tempStart, tempEnd; tempStart.start=1; tempEnd.start=0;
    cin>>N;

    //create all endpoints vector sorted by time
    for(int i = 0; i < N; i++){
        cin>>tempStart.theTime>>tempEnd.theTime; 
        tempStart.guardNum = i; tempEnd.guardNum = i;
        allTimes.push_back(tempStart); allTimes.push_back(tempEnd);
    }
    sort(allTimes.begin(), allTimes.end(), cmpTime);


    //loop over from min time to max time
    unordered_set<int> currentShift; int *singleCoverage = new int[N]; 
    for(int i = 0; i < N; i++) singleCoverage[i] = 0; 

    int noCoverage = 0, diff;

    for(auto i = allTimes.begin(); i < allTimes.end()-1; i++){
        if((*i).start==1) currentShift.insert((*i).guardNum);           //insert start time
        else currentShift.erase((*i).guardNum);                         //erase guard when end time reached

        diff = (*(i+1)).theTime-(*i).theTime;     //difference between this significant time and next

        if(currentShift.size()==1) singleCoverage[*begin(currentShift)] += diff;       //if only one guard, add to single coverage diff
        if(currentShift.size()==0) noCoverage += diff;      //if empty shift, add to noCoverage
    }
    
    //print max time when optimally firing one guard
    int totDuration = allTimes.back().theTime-allTimes[0].theTime;
    int minCoverage = *min_element(singleCoverage, singleCoverage+N);
    cout<<totDuration-noCoverage-minCoverage<<endl; 

    delete [] singleCoverage; 
}