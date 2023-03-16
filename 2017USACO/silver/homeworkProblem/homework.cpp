#include <iostream>
using namespace::std;
#include <vector>
#include <limits>
#include <cmath>

#define FOR(i, a, b) for(int i = a; i < b; i++)
#define R_FOR(i, a, b) for(int i = a; i >= b; i--)
typedef long long ll;
const int EPSILON = numeric_limits<double>::epsilon();

int main() {
    freopen("homework.in", "r", stdin);
    freopen("homework.out", "w", stdout);

    //feed in scores
    int N;  cin>>N;
    vector<int> scores(N + 1);
    FOR(i, 1, N + 1) cin>>scores[i];

    //set up suffix variables
    vector<int> best_k;
    best_k.push_back(N-2);

    ll suffix_sum = scores[N] + scores[N-1];
    int suffix_min = min(scores[N], scores[N-1]);
    double best_avg = max(scores[N], scores[N-1]);

    //simulate finding k's for best average
    R_FOR(k, N - 3, 1){
        suffix_sum += scores[k + 1];
        suffix_min = min(scores[k + 1], suffix_min);
        double avg = (suffix_sum - suffix_min) / (N - k - 1.0);

        //update avg & best_k
        if(abs(avg - best_avg) <= EPSILON){
            best_k.push_back(k);
        }
        else if(isgreater(avg, best_avg)){
            best_avg = avg;
            best_k.clear();
            best_k.push_back(k);
        }
    }

    R_FOR(k, best_k.size()-1, 0) cout<<best_k[k]<<endl;
}