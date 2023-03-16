#include <iostream>
#include <fstream>
using namespace std;

int N, x[100], passto[100];   // passto[i] is # of cows passing to cow i                                                                         

// To whom does cow i pass the ball?                                                                                                             
int target(int i)
{
  int left_nbr=-1, left_dist = 1000;
  int right_nbr=-1, right_dist = 1000;

  // Find closet neighbors on left and right                                                                                                     
  for (int j=0; j<N; j++)
    if (x[j] < x[i] && x[i]-x[j] < left_dist) { left_nbr = j; left_dist = x[i]-x[j]; }
  for (int j=0; j<N; j++)
    if (x[j] > x[i] && x[j]-x[i] < right_dist) { right_nbr = j; right_dist = x[j]-x[i]; }

  if (left_dist <= right_dist) return left_nbr;
  return right_nbr;
}

int main(void)
{
  ifstream fin ("hoofball.in");
  ofstream fout ("hoofball.out");
  fin >> N;
  for (int i=0; i<N; i++) fin >> x[i];
  for (int i=0; i<N; i++) passto[target(i)]++;

  int answer = 0;
  for (int i=0; i<N; i++) {
    if (passto[i] == 0) answer++;  // +1 for every "source" cow, to whom nobody passes                                                           
    if (i < target(i) && target(target(i))==i && passto[i]==1 && passto[target(i)]==1)
      answer++;  // +1 for every pair passing to each-other                                                                                      
  }

  fout << answer << "\n";
  return 0;
}