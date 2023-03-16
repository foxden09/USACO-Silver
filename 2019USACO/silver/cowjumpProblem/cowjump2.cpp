#include <iostream>
#include <algorithm>
using namespace::std;
#include <vector>
#include <set>
#define FOR(i, b) for(int i = 0; i < b; i++)
#define F0R(i, a, b) for(int i = a; i <= b; i++)

struct Point{
    int x, y;
    int seg_id; 
    bool operator<(const Point& rhs)const{ return x < rhs.x; }
};
struct Segment{
    int id; 
    Point p1, p2;
    bool operator<(const Segment& rhs)const{return min(p1, p2).y < min(rhs.p1, rhs.p2).y; }
};
set<Segment> curr_segs; 
typedef set<Segment>::iterator it; 
Segment seg1, seg2; int N;

bool is_on_right_side(Point p, Segment seg){
    Point p1 = {seg.p2.x - seg.p1.x, seg.p2.y - seg.p1.y, -1};
    Point p2 = {p.x - seg.p1.x, p.y - seg.p1.y, -1}; 
    return (long long) p1.x * p2.y - (long long) p2.x * p1.y < 0; 
}
bool valid_it(it s1_it){ return s1_it != curr_segs.end(); }
bool check_intersect(Segment s1, Segment s2){
    bool intersecting = (is_on_right_side(s2.p1, s1) ^ is_on_right_side(s2.p2, s1)) && 
                        (is_on_right_side(s1.p1, s2) ^ is_on_right_side(s1.p2, s2));
    if(!intersecting) return false;
    seg1 = s1; seg2 = s2;
    return true;
}

int main() {
    freopen("cowjump.in", "r", stdin);
    freopen("cowjump.out", "w", stdout);

    //feed in data
    cin>>N;
    vector<Segment> segs (N);
    vector<Point> points (N*2);

    FOR(i, N){
        cin>>points[i*2].x>>points[i*2].y;
        cin>>points[i*2+1].x>>points[i*2+1].y;
        segs[i].id = i; segs[i].p1 = points[i*2]; segs[i].p2 = points[i*2+1];
        points[i*2].seg_id = i;  points[i*2+1].seg_id = i;
    }
    sort(points.begin(), points.end());

    //find first intersect
    for(Point p : points){
        Segment curr = segs[p.seg_id]; 
        it after = curr_segs.upper_bound(curr); 
        it before = (valid_it(after) && after != curr_segs.begin()) ? prev(after) : after; 

        if(curr_segs.find(curr) != curr_segs.end()){
            if(valid_it(after) && valid_it(before) && check_intersect(*before, *after)) break;
            curr_segs.erase(curr);
        } else{
            if(valid_it(before) && check_intersect(*before, curr)) break;
            if(valid_it(after) && check_intersect(*after, curr)) break;
            curr_segs.insert(curr);
        }
    }

    //check if higher seg intersects any others
    int higherId = max(seg1.id, seg2.id);
    int ans = min(seg1.id, seg2.id);
    for(Segment s : segs){
        if(s.id == seg1.id || s.id == seg2.id) continue;
        if(check_intersect(segs[higherId], s)) { ans = higherId; break; }
    }
    cout<<ans+1<<endl;
}
