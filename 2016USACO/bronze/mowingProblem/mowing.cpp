#include <iostream>
#include<fstream>
#include<algorithm>

using namespace::std;

int counts = 1;

struct unit{
    long long xcoor, ycoor;
    int timeis;
};

void doSomething(unit *field, int steps, char direction){
    long long tempy, tempx; 
    tempy = field[counts-1].ycoor; tempx = field[counts-1].xcoor;
    
    for(int y = 1; y < steps+1; y++){
        if(direction=='N'){
            field[counts].ycoor = tempy+y; field[counts].xcoor=tempx;
        }
        else if(direction == 'E'){
            field[counts].xcoor = tempx+y; field[counts].ycoor = tempy;
        }
        else if(direction == 'W'){
            field[counts].xcoor = tempx-y; field[counts].ycoor = tempy;
        }
        else if(direction=='S'){
            field[counts].ycoor = tempy-y; field[counts].xcoor=tempx;
        }
        field[counts].timeis = counts; 
        counts++;
    }

}

bool operator<(const unit& a, const unit& b) {
  return ((long long)a.xcoor*1000001+(long long)a.ycoor*1001+(long long)a.timeis) < ((long long)b.xcoor*1000001+(long long)b.ycoor*1001+(long long)b.timeis);
}

int checkDup(unit*field){
    sort(field, field+counts);
    int smallesttime = 1001;
    for(int r = 1; r < counts+1; r++){
        if(field[r].xcoor==field[r-1].xcoor&&field[r].ycoor==field[r-1].ycoor){
            smallesttime = min(field[r].timeis-field[r-1].timeis,smallesttime);
        }
    }
    if(smallesttime==1001||smallesttime==0) smallesttime = -1;
    
    return smallesttime;
}

int main(){
    ofstream fout ("mowing.out");
    ifstream fin ("mowing.in");

    unit field[1010] = {0,0,0};

    int n, steps; 
    char direction;
    fin>>n;

    for(int i = 0; i < n; i++){
        fin>>direction>>steps; 
        doSomething(field,steps,direction);
    }
    fout<<checkDup(field)<<endl;

    /*for(int i = 0; i < 32; i++){
        fout<<field[i].xcoor<<" "<<field[i].ycoor<<" "<<field[i].timeis<<endl;
    }*/
}