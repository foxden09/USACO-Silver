#include<iostream>
#include<algorithm>

using namespace::std;
#include<vector>
#include<unordered_set>

int N, M;

//feeds in genomes into corresponding spotty/plain vector
void cinGenome(vector<string> &genome){
    string tempGenome;
    for(int cow = 0; cow < N; cow++){
        cin>>tempGenome;
        genome.push_back(tempGenome);
    }
}

//forms unordered_sets specifying what bases appear at gene position
void formSet(int genePos, vector<string> &genome, unordered_set<char> &bases){
    for(int cow = 0; cow < N; cow++){
        bases.insert(genome[cow][genePos]);
    }
}

//inverse intersect spotty & plain bases
bool uniqueSpot(unordered_set<char> &spotty, unordered_set<char> &plain){
    for(char base: spotty){
        if(plain.count(base)>0) return false;
    }
    return true;
}

int main(){
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);    
    cin>>N>>M;
    int totalExplain = 0;
    vector<string> Sgenome, Pgenome; string tempGenome; 

    cinGenome(Sgenome); 
    cinGenome(Pgenome);

    for(int genePos = 0; genePos < M; genePos++){
        unordered_set<char> spotty, plain; 

        formSet(genePos, Sgenome, spotty);
        formSet(genePos, Pgenome, plain);

        totalExplain+=uniqueSpot(spotty, plain);
    }

    cout<<totalExplain<<endl;
}
