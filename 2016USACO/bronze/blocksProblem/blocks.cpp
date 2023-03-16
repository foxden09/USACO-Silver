#include <iostream>
#include<fstream>
#include<string>

using namespace::std;

int main() {
    ofstream fout ("blocks.out");
    ifstream fin ("blocks.in");
    int n; string temp, temp2;
    int arr[26] = {0}, arr1[26] = {0}, arr2[26] = {0};
    fin>>n;

    for(int i = 0; i < n; i++){
        fin>>temp>>temp2;
        for(auto &ch: temp){
            //cout<<(int)ch-97<<ch<<endl;
            arr1[(int)ch-97]++;
        }
        for(auto &ch: temp2){
            arr2[(int)ch-97]++;
        }
        
        for(int y = 0; y < 26; y++){
            arr[y]+=max(arr1[y],arr2[y]);
        }
        fill(begin(arr1), begin(arr1)+26, 0); fill(begin(arr2), begin(arr2)+26,0);
    }
    
    for(int i = 0; i < 26; i++){
        fout<<arr[i]<<endl;
    }

}