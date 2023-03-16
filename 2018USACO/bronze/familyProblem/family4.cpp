#include <iostream>
#include <algorithm>
#include <string>
#include <cassert>
using namespace std;
#define MAXN 100
 
int N;
string daughter[MAXN];
string mother[MAXN];
 
// returns mother of cow, or "" if mother does not exist
string find_mother(string cow)
{
	for(int i=0;i<N;i++)
		if(cow == daughter[i])
			return mother[i];
	return "";
}
 
// returns number of generations by which cow1 is removed from cow2
// if cow1 is a direct ancestor of cow2.
// returns -1 otherwise.
int is_ancestor(string cow1, string cow2)
{
	int counter = 0;
	while(cow2 != "")
	{
		if(cow1 == cow2)
			return counter;
		cow2 = find_mother(cow2);
		counter++;
	}
	return -1;
}
 
int main()
{
    freopen("family.in", "r", stdin); 
    freopen("family.out", "w", stdout); 
	string bessie, elsie;
	cin >> N >> bessie >> elsie;
	for(int i=0;i<N;i++)
		cin >> mother[i] >> daughter[i];
	
	string cow = bessie;
	int b = 0;
	while(cow != "")
	{
		if(is_ancestor(cow, elsie) != -1)
			break;
		cow = find_mother(cow);
		b++;
	}
	if(cow == "")
	{
		cout << "NOT RELATED\n";
		return 0;
	}
	int a = is_ancestor(cow, elsie);
	if(a == 1 && b == 1) cout << "SIBLINGS\n";
	else if(a > 1 && b > 1) cout << "COUSINS\n";
	else
	{
		if(a > b) swap(elsie, bessie), swap(a, b);
		cout << elsie << " is the ";
		for(int i=0;i<b-2;i++) cout << "great-";
		if(b > 1 && a == 0) cout << "grand-";
		if(a == 0) cout << "mother";
		else cout << "aunt";
		cout << " of " << bessie << '\n';
	}
	return 0;
}