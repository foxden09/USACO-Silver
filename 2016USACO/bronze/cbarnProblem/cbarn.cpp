#include <iostream>
#include<fstream>

using namespace::std;

int main() {
    ofstream fout ("cbarn.out");
    ifstream fin ("cbarn.in");
    int n, minDis = 2147483646 , tot;
    fin>>n;
    int *arr = new int[n];

    for(int i = 0; i < n; i++){
        fin>>arr[i];
    }
    for(int i = 0; i < n; i++){
        tot = 0;
        for(int y = i+1; y < n+i; y++){
            
            tot+=arr[y%(n)]*(y-i);
            //if(i==1) cout<<tot<<" "<<arr[y%(n+1)]<<" y%(n+1): "<<y%(n)<<endl;
        }
        //cout<<tot<<" "<<i<<endl;
        minDis = min(tot, minDis);
    }
    fout<<minDis<<endl;

}