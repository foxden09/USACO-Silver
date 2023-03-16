#include <iostream>
#include<algorithm>
#include<fstream>

using namespace::std;

int tot; 

struct thing{
    int lx, ly, rx, ry;
};

void doStuff(thing bill, thing truck){
    tot+=(bill.ry-bill.ly)*(bill.rx-bill.lx);
    //cout<<"before"<<tot<<endl;
    if(bill.ly<=truck.ry&&bill.ry>=truck.ly&&bill.rx>=truck.lx&&bill.lx<=truck.rx){

        tot-=(min(bill.ry, truck.ry)-max(bill.ly, truck.ly))*(min(bill.rx, truck.rx)-max(bill.lx, truck.lx));
    
        
    }
}

int main() {
    ofstream fout ("billboard.out");
    ifstream fin ("billboard.in");
    thing bill1, bill2, truck;
    fin>>bill1.lx>>bill1.ly>>bill1.rx>>bill1.ry>>bill2.lx>>bill2.ly>>bill2.rx>>bill2.ry>>truck.lx>>truck.ly>>truck.rx>>truck.ry;

    doStuff(bill1, truck); doStuff(bill2, truck);
    fout<<tot<<endl;
}