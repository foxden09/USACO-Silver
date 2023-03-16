#include<iostream>
#include<fstream>
using namespace::std;

void swaps(int *arr, int *counter, int temp1, int temp2, int guess){
    int temp; 
    temp = arr[temp1-1]; arr[temp1-1] = arr[temp2-1]; arr[temp2-1] = temp;
    temp = arr[temp1-1+3]; arr[temp1-1+3] = arr[temp2-1+3]; arr[temp2-1+3] = temp;
    temp= arr[temp1-1+6] ; arr[temp1-1+6] = arr[temp2-1+6]; arr[temp2-1+6] = temp;
    /*for(int i = 0; i < 9; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;*/
    if(arr[guess-1]==1){
        counter[0]++;
    }
    else if(arr[guess-1+3]==1){
        counter[1]++;
    }
    else if(arr[guess-1+6]==1){
        counter[2]++;
    }
}
int main(){
    ofstream fout ("shell.out");
    ifstream fin ("shell.in");
    int n, temp1, temp2, guess;
    fin>>n;
    int arr[9] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    int counter[3] = {0,0,0};
    
    for(int i = 0; i < n; i++){
        fin>>temp1>>temp2>>guess;
        swaps(arr, counter, temp1, temp2, guess);
    }
    fout<<max(counter[2],max(counter[1], counter[0]))<<endl;
}