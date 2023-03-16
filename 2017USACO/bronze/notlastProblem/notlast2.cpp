#include <iostream>

using namespace::std;
#include<string>
#include<unordered_map>
#include<queue>
#define REP(i, b) for(int i = 0; i < b; i++)
typedef unordered_map<string, int> umap; 
typedef pair<int, string> myPairType; 

//compare priority queue elem by the int (milk produced)
struct cmpValue{
    bool operator()(const myPairType &a, const myPairType &b) const{
        return a.first>b.first; 
    }
};
typedef priority_queue<myPairType, vector<myPairType>, cmpValue> pq; 


string findSecondMin(pq &milkQueue){
    //pop minvalue cows off queue
    int minValue = milkQueue.top().first; 
    while(!milkQueue.empty()){
        if(milkQueue.top().first == minValue) milkQueue.pop(); 
        else break; 
    }
    if(milkQueue.empty()) return "Tie"; 

    //find second min
    int secondMin = milkQueue.top().first; string secondCow = milkQueue.top().second;
    milkQueue.pop();
    if(secondMin!=milkQueue.top().first || milkQueue.empty()){
        return secondCow; 
    }
    else return "Tie";
}

int main() {
    freopen("notlast.in", "r", stdin); 
    freopen("notlast.out", "w", stdout); 
    int N; cin>>N;

    //create map of cows -> milk produced (default value 0)
    umap milkMap; 
    string cows[7] = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};
    for(string cow: cows) milkMap[cow] = 0;

    //update milkMap
    string tempName; int tempMilk; 
    REP(i, N){
        cin>>tempName>>tempMilk;
        milkMap[tempName]+=tempMilk; 
    }

    //create priority queue
    pq milkQueue;
    for(auto &it: milkMap) milkQueue.push({it.second, it.first});

    //print second min
    cout<<findSecondMin(milkQueue)<<endl;
}