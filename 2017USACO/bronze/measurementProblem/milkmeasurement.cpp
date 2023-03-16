#include <iostream>
#include<algorithm>
#include<fstream>
#include<string>
#include<map> 

using namespace::std;
#include<vector>


struct datarow{
    int day;
    string name;
    int changein;
};

bool compareByDay(const datarow &a, const datarow &b){
    return a.day<b.day;
}

int main(){
    ofstream fout ("measurement.out");
    ifstream fin ("measurement.in");
    int N, m = 0, indexfromname; 
    vector<datarow> datasheet; datarow temp; 
    fin>>N;
    int cowrates[3] = {0,0,0}, numofchanges = 0, previousMax = 123, currentMaxIndex = 123, runningMax = 0; //123 is 3 way tie

    for(int i = 0; i < N; i++){
        fin>>temp.day>>temp.name>>temp.changein;
        datasheet.push_back(temp);
    }
    sort(datasheet.begin(), datasheet.end(), compareByDay);

    for(int i = 0; i < N; i++){
        if(datasheet[i].name == "Bessie") indexfromname = 0; 
        else if(datasheet[i].name == "Elsie") indexfromname = 1; 
        else if(datasheet[i].name=="Mildred") indexfromname = 2; 
        cowrates[indexfromname] += datasheet[i].changein;

        runningMax = 0;
        for(int i = 0; i < 3; i++){
            if(cowrates[i]>runningMax){
                currentMaxIndex = i; runningMax = cowrates[i];
            }
        }
        if(cowrates[0]==cowrates[1]&&cowrates[1]==cowrates[2]) currentMaxIndex = 123;
        else if(cowrates[0]==cowrates[1]&&cowrates[0]==runningMax) currentMaxIndex = 12;
        else if(cowrates[0]==cowrates[2]&&cowrates[0]==runningMax) currentMaxIndex = 13; 
        else if(cowrates[1]==cowrates[2]&&cowrates[1]==runningMax) currentMaxIndex = 23; 
        if(currentMaxIndex!=previousMax) numofchanges++;
        previousMax = currentMaxIndex;
    }
    fout<<numofchanges<<endl;
}

