#include<iostream>
#include<fstream>
#include<string>

using namespace::std;
#include<vector>

bool isItMoo(string &S, string &T, vector<int> &allPartials, int indexOfpartial){
    //checks to see if partial is complete
    bool isItMoobool = true; 
    for(int i = 0; i < T.length(); i++){
        if(S[allPartials[indexOfpartial]+i]!=T[i]){
            isItMoobool = false; break;
        }   
    }
    if(isItMoobool==true){
        S.erase(allPartials[indexOfpartial], T.length());
        for(int i = allPartials.size(); i > indexOfpartial; i--){
            allPartials[i]-=T.length();
        }
    }
    return isItMoobool;
}

void goupordown(string &S, string &T, vector<int> &allPartials, int indexOfpartial, int leadingPartial){
    //for complete partial, checks if previous partial is completed; if so, call again; if not, break
    
    int previousindexofpartial = indexOfpartial - 1; 
    //jumps to last positive (incomplete) partial 
    if(allPartials[previousindexofpartial]<0){
        previousindexofpartial = -allPartials[previousindexofpartial];
    }
    cout<<indexOfpartial<<" "<<previousindexofpartial<<endl;
    //exits if we return/jump to beginning of partial vector OR if previous partial is not nearby
    if(indexOfpartial == 0||allPartials[previousindexofpartial] == -2000000000){
        //if we are either at the beginning of partials because its the previous one OR the previous partial sends to the beginning, return
        allPartials[leadingPartial] = -2000000000; 
        return;
    }
    /*if(allPartials[indexOfpartial]-allPartials[previousindexofpartial]>T.length()){
        return; 
    }*/
    //checks to see if previous partial if completed; if not, set leading partial to last positive partial
    if(isItMoo(S, T, allPartials, previousindexofpartial)==true){
        allPartials[indexOfpartial-1] = -1; 
        goupordown(S, T, allPartials, indexOfpartial-1, leadingPartial);
    }
    else{
        allPartials[leadingPartial] = -(indexOfpartial-1);
    }

}

int main(){
    ofstream fout ("censor.out");
    ifstream fin ("censor.in");
    std::string S, T;
    fin>>S>>T;
    vector<int> allPartials; 
    

    for(int i = 0; i < S.length(); i++){
        if(S[i]==T[0]){
            allPartials.push_back(i); 
        }
    }
 
    isItMoo(S, T, allPartials, 0);
    for(int i = 1; i < allPartials.size(); i++){
        //for all complete partials 
        if(isItMoo(S, T, allPartials, i)==true){
            allPartials[i]=-1; goupordown(S, T, allPartials, i, i);
        }
    }

    fout<<S<<endl;
    
}