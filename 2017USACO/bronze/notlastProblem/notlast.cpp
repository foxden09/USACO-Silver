#include <iostream>

using namespace::std;
#include<string>
#include<unordered_map>
#define REP(i, b) for(int i = 0; i < b; i++)
typedef unordered_map<string, int> myMapType; 

//find min greater than default min value
int findMin(int defaultMin, myMapType &milkMap){
    int minValue = defaultMin;

    for(auto &it: milkMap){
        if(it.second>defaultMin && it.second<minValue) 
    }
}
int main() {
    freopen("notlast.in", "r", stdin); 
    freopen("notlast.out", "w", stdout); 
    int N; cin>>N;

    //create map of cows -> milk produced (default value 0)
    myMapType milkMap; 
    string cows[7] = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};
    for(string cow: cows) milkMap[cow] = 0;

    //update milkMap
    string tempName; int tempMilk; 
    REP(i, N){
        cin>>tempName>>tempMilk;
        milkMap[tempName]+=tempMilk; 
    }

   
    
    findMin(-1, milkMap); 

}