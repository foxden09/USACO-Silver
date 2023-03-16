#include <iostream>
#include<algorithm>
#include<fstream>

using namespace::std;

int main() {
    ofstream fout ("paint.out");
    ifstream fin ("paint.in");

    int nums[4], temp;
    fin>>nums[0]>>nums[1]>>nums[2]>>nums[3];

    if(max(nums[0],nums[1])>max(nums[2],nums[3])){
        temp = nums[0]; nums[0] = nums[2]; nums[2] = temp;
        temp = nums[1]; nums[1] = nums[3]; nums[3] = temp;
    }

    if(nums[1]<nums[2]){
        fout<<nums[1]-nums[0]+nums[3]-nums[2]<<endl;
    }
    else{
        fout<<max(nums[3], nums[1])-min(nums[0], nums[2])<<endl;
    }

}