#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long LL;
 
#define INF 2000000000
#define FF first
#define SS second

int n, m;
 
vector<pair<LL,LL>> intervals;
 
bool ok(LL d) {
    LL prev = -1LL * INF * INF;
    
    int cnt = 0;
    for (auto& i : intervals) {
        while (max(prev + d, i.FF) <= i.SS) {
            prev = max(prev + d, i.FF);
            cnt++;
            if (cnt >= n) break;
        }
        if (cnt >= n) break;
    }
 
    return (cnt >= n);
}
 
int main() {
    freopen("socdist.in","r",stdin);
    freopen("socdist.out","w",stdout);
    cin >> n >> m;

    intervals.resize(m);
    for (int i = 0; i < m; ++i) 
        cin >> intervals[i].FF >> intervals[i].SS;
 
    sort(intervals.begin(), intervals.end());
 
    LL lo = 1;
    LL hi = 1LL * INF * INF;
    LL res = -1;
 
    while (lo <= hi) {
        LL mid = (lo + hi) / 2;
 
        if (ok(mid)) {
            res = mid;
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
 
    cout << res << "\n";
}