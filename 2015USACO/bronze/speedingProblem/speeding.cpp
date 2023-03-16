#include <iostream>
#include<vector>
#include<fstream>

using namespace::std;


int main() {
    ofstream fout ("speeding.out");
    ifstream fin ("speeding.in");
    int n, m, temp1, temp2, total = 0, maxOver = 0;
    int arr[100];

    fin>>n>>m;
    for(int i = 0; i < n; ++i){
        fin>>temp1>>temp2;
        fill(arr+total, arr+temp1+total, temp2);
        total+=temp1;
    }
    total = 0;

    for(int i = 0; i < m; ++i){
        fin>>temp1>>temp2;
        for(int y = total; y < total+temp1; y++){
            maxOver = max(temp2-arr[y], maxOver);
        }
        total+=temp1;
    }
    fout<<maxOver<<endl;
}