#include <iostream>
using namespace std;
 
const int mx = 5000005;
int min_turns[mx] = {0, 1};
bool composite[mx] = {false};
int max_mod4[4] = {2, 1, 2, 3};
 
int main() {
    freopen("p2.in", "r", stdin);
    freopen("p22.out", "w", stdout);
	for(int i = 2; i < mx; i++) {
		if(!composite[i]) {
			for(int j = i; j < mx; j += i) {
				composite[j] = true;
			}
			max_mod4[i % 4] = i;
		}
		min_turns[i] = (i - max_mod4[i % 4]) / 2 + 1;
	}

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		int ans = mx;
		for(int i = 0; i < n; i++) {
			int a_i; cin >> a_i;
			if(min_turns[a_i] / 2 < ans / 2) ans = min_turns[a_i];
		}
		if(ans & 1) cout << "Farmer John" << ans << endl;
		else cout << "Farmer Nhoj" << ans << endl;
	}
}