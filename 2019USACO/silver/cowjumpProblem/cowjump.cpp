#include <iostream>

using namespace::std;
#include <vector>
#include <set>
#define FOR(i, b) for(int i = 0; i < b; i++)
#define F0R(i, a, b) for(int i = a; i <= b; i++)

struct Point;
struct Segment{
    int id; 
    Point* p1, p2;
};
struct Point{
    int x, y;
    Segment& seg; 
    bool operator<(const Point& rhs)const{ return x < rhs.x; }
};
bool cmpseg(const Segment& lhs, const Segment& rhs) { return min(lhs.p1, lhs.p2).y < min(rhs.p1, rhs.p2).y; }; 
set<Segment> curr_segs; 
typedef set<Segment>::iterator it; 
Segment seg1, seg2; int N;

bool is_on_right_side(Point p, Segment seg){
    Point p1 = {seg.p2.x - seg.p1.x, seg.p2.y - seg.p1.y, seg};
    Point p2 = {p.x - seg.p1.x, p.y - seg.p1.y, seg}; 
    return p1.x * p2.y - p2.x * p1.y < 0; 
}
bool valid_it(it s1_it, it s2_it){ return s1_it == curr_segs.end() || s2_it == curr_segs.end(); }
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
        points[i*2].seg = segs[i];  points[i*2+1].seg = segs[i];
    }
    sort(points.begin(), points.end());

    //find first intersect
    for(Point p : points){
        it after = curr_segs.upper_bound(p.seg);
        it before = prev(after);
        if(curr_segs.find(p.seg) != curr_segs.end()){
            if(valid_it(before, after) && check_intersect(*before, *after)) break;
            curr_segs.erase(p.seg);
        } 
        else{
            if(valid_it(before, before) && check_intersect(*before, p.seg)) break;
            if(valid_it(after, after) && check_intersect(*after, p.seg)) break;
            curr_segs.insert(p.seg);
        }
    }

    //check if higher seg intersects any others
    //if(seg1.id > seg2.id) swap(seg1, seg2);
    int ans = seg1.id; 
    for(Segment s : segs){
        if(s.id == seg1.id || s.id == seg2.id) continue;
        if(check_intersect(seg2, s)) { ans = seg2.id; break; }
    }
    cout<<ans+1<<endl;
}
