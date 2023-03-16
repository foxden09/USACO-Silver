#include<iostream>
#include<fstream>
using namespace::std;

struct bucket{
    int c, m; 
};

void pour(bucket *buckets, int outof, int into){
    int temp = buckets[into].m+buckets[outof].m;
    buckets[into].m = min(buckets[into].c, temp);
    buckets[outof].m = max(0, temp-buckets[into].c);
}

int main() {
    ofstream fout ("mixmilk.out");
    ifstream fin ("mixmilk.in");

    bucket buckets[3];

    for(int i = 0; i < 3; i++){
        fin>>buckets[i].c>>buckets[i].m;
    }

    for(int i = 0; i < 33; i++){
        pour(buckets, 0, 1);
        pour(buckets, 1, 2);
        pour(buckets, 2, 0);
    }
    pour(buckets, 0, 1);

    fout<<buckets[0].m<<endl<<buckets[1].m<<endl<<buckets[2].m<<endl;

}