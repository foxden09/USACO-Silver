#include<iostream>
#include<fstream>
#include<string>


using namespace::std;
#include<vector>
//
struct partial{
    int indexof;
    int howmanymatchT;
};

void findT(vector<partial> &allPartials, string &S, string &T, int indexofpartial, int numI){
    for(int y = 0; y < T.length()-1; y++){
        if(S[numI+y+1]==T[y+1]){
            allPartials[indexofpartial].howmanymatchT++;
        }
        else{
            break;
        }
    }
    //loop over rest of T to see if S[y]==T[k]
    //if not, then modify allPartials (along the way)
    //* perhaps add if next one is not also a partial then delete
}



void simulateT(vector<partial> &allPartials, string &S, string &T, int partialsIterator){
    int Siterator = allPartials[partialsIterator].indexof, Tlength = T.length();
    for(int y = allPartials[partialsIterator].howmanymatchT; y<=T.length(); y++){
        if(y==T.length()){
            S.erase(Siterator, T.length());
        }
        if(S[Siterator+y]!=T[y]){
            break;
        }
        
    }
    //go backwards through allPartials less than iterator
    //if that == moo, then space/delete it it
        //check nearest less than T.length() [maybe exception equal to T.length()]
            //call findT, if found then repeat check nearest
    //if not, delete

}



int main(){
    ofstream fout ("censor.out");
    ifstream fin ("censor.in");
    std::string S, T;
    fin>>S>>T;
    vector<partial> allPartials; partial temp; int countOf = 0;


    for(int i = 0; i < S.length(); i++){
    //if S[0]=T[0], then append to allPatails & call func findT 
        if(S[i]==T[0]){
            temp.indexof = i; temp.howmanymatchT=1; 
            allPartials.push_back(temp); 
            findT(allPartials, S, T, countOf, i);
            countOf++;
        }
    }
    //loop over S to find T[0]
    


    for(int i = allPartials.size() - 1; i >= 0; i--){
       simulateT(allPartials, S, T, i);
    }

    fout<<S<<endl;
}