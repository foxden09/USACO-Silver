#include<iostream>
#include<fstream>
#include<vector>
using namespace::std;



int main(){
    ofstream fout ("tttt.out");
    ifstream fin ("tttt.in");
    char nums[9];
    for(int i = 0; i < 9; ++i) fin>>nums[i];

    int possibleteams[1000] = {0}; 
    int possibleindiv[26] = {0};
    //for(int i = 0; i < 26; i++) cout<<possibleindiv[i]<<endl;
    vector<int> combos = {0,1,2,3,4,5,6,7,8,0,3,6,1,4,7,2,5,8,0,4,8,2,4,6};
    int indiv = 0, teams = 0, temp1, temp2, temp3;
    char first, second, third;

    for(auto it = begin(combos); it != end(combos); it+=3){
        first = nums[*it]; second = nums[*(it+1)]; third = nums[*(it+2)];
        //cout<<*it<<" HEY "<<first<<second<<third<<endl;

        if(third==second&&third==first){
            //cout<<possibleindiv[static_cast<int>(nums[*it]-'A'+1)]<<endl;
            if(possibleindiv[static_cast<int>(nums[*it]-'A'+1)]!=1){
                possibleindiv[static_cast<int>(nums[*it]-'A'+1)] = 1;
                indiv++;
            }
        }
        else if(third==first||third==second||first==second){
            temp1 = static_cast<int>(nums[*it]-'A'+1); temp2 = static_cast<int>(nums[*(it+1)]-'A'+1); temp3 = static_cast<int>(nums[*(it+2)]-'A'+1); 
            if(third==first){
                if(possibleteams[min(temp3, temp2) + 25*(max(temp3,temp2)-1)]!=1){
                    possibleteams[min(temp3, temp2) + 25*(max(temp3,temp2)-1)] = 1;
                    teams++;
                }
            }
            else if(third == second){
                if(possibleteams[min(temp3, temp1) + 25*(max(temp3,temp1)-1)]!=1){
                    possibleteams[min(temp3, temp1) + 25*(max(temp3,temp1)-1)] = 1;
                    teams++;
                }
            }
            else if(first == second){
                if(possibleteams[min(temp3, temp2) + 25*(max(temp3,temp2)-1)]!=1){
                    possibleteams[min(temp3, temp2) + 25*(max(temp3,temp2)-1)] = 1;
                    teams++;
                }
            }

        }
    }
    fout<<indiv<<"\n"<<teams;
}

