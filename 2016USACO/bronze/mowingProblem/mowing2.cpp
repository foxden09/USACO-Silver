#include <iostream>
#include<fstream>

using namespace::std;

int times = 1;


void doSomething(int *xcoor, int *ycoor, int steps, char direction){
    int tempy, tempx; 
    tempy = ycoor[times-1]; tempx = xcoor[times-1];
    
    for(int y = 1; y < steps+1; y++){
        if(direction=='N'){
            ycoor[times] = tempy+y; xcoor[times]=tempx;
        }
        else if(direction == 'E'){
            xcoor[times] = tempx+y; ycoor[times] = tempy;
        }
        else if(direction == 'W'){
            xcoor[times] = tempx-y; ycoor[times] = tempy;
        }
        else if(direction=='S'){
            ycoor[times] = tempy-y; xcoor[times]=tempx;
        }
        times++;
    }

}

int checkDup(int *xcoor, int*ycoor){
    for(int i = 0; i < times; ++i){
        
    }
}


int main(){
    ofstream fout ("mowing.out");
    ifstream fin ("mowing.in");

    int xcoor[1000] = {0}, ycoor[1000] = {0};

    int n, steps; 
    char direction;
    fin>>n;

    for(int i = 0; i < n; i++){
        fin>>direction>>steps; 
        doSomething(xcoor,ycoor,steps,direction);
    }
    
}