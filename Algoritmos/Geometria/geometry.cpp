#include<bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(x) (int)(x).size()
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define all(x)  (x).begin() , (x).end()
#define fs first
#define sc second
#define ii pair<int, int>
#define vii vector<ii>
#define endl '\n'
#define ll long long int
#define MAXX 1073741823
#define MAX (1<<20)
#define INF 0x3f3f3f3f
#define MODN 1000000007
#define int long long // -> solução divina

using namespace std;

#define EPS 1e-9

struct point {
    double x, y;
    point() {x = y = 0.0; }
    point(double _x, double _y) : x(_x), y(_y) {}
    double norm() { return hypot(x,y); }
    point normalized() {
        return point(x, y)*(1.0/norm());
    }

    double angle() { return atan2(x,y); }
    double polarAngle() {
        double a = atan2(y, x);
        return a < 0 ? a + 2*acos(-1.0) : a;
    }
    bool operator < (point other) const {
        if (fabs(x - other.x) > EPS) return x < other.x;
        else return y < other.y;
    }
    bool operator == (point other) const {
        return (fabs(x - other.x) < EPS && (fabs(y-other.y) < EPS));
    }
    point operator +(point other) const {
        return point(x + other.x, y + other.y);
    }
    point operator -(point other) const {
        return point(x - other.x, y - other.y);
    }
    point operator *(double k) const {
        return point(x*k, y*k);
    }
};

double dist(point p1, point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

double inner(point p1, point p2) {
    return p1.x*p2.x + p1.y*p2.y;
}
double cross(point p1, point p2) {
    return p1.x*p2.y - p1.y*p2.x;
}
//counterclockwise
bool ccw(point p, point q, point r) {
    return cross(q-p, r-p) > 0;
    //mudar se quiser colinear no convex hull
}
bool collinear(point p, point q, point r) {
    return fabs(cross(p-q, r-p)) < EPS;
}
point rotate(point p, double rad) {
    return point(p.x * cos(rad) - p.y * sin(rad), p.x*sin(rad) + p.y*cos(rad));
}
double angle(point a, point o, point b) {
    return acos(inner(a-o, b-o) / (dist(o, a)*dist(o, b)));
}
point proj(point u, point v) {
    return v*(inner(u, v)/inner(v, v));
}
bool between(point p, point q, point r) {
    return collinear(p, q, r) && inner(p-q, r-q) <= 0;
}

point lineIntersectSeg(point p, point q, point A, point B) {
    double c = cross(A-B, p-q);
    double a = cross(A, B);
    double b = cross(p,q);
    return ((p-q)*(a/c)) - ((A-B)*(b/c));
}
bool parallel(point a, point b) {
    return fabs(cross(a,b)) < EPS;
}
bool segIntersects(point a, point b, point p, point q) {
    if (parallel(a-b, p-q)) {
        return between(a, p, b) || between(a, q, b) || between(p, a, q) || between(p, b, q);
    }
    point i = lineIntersectSeg(a, b, p, q);
    return between(a, i, b) && between(p, i, q);
}

point closestToLineSegment(point p, point a, point b) {
    double u = inner(p-a, b-a) / inner(b-a, b-a);
    if (u < 0.0) return a;
    if (u > 1.0) return b;
    return a + ((b-a)*u);
}

int length_union(const vector<pair<int, int>> &a) {
    int n = a.size();
    vector<pair<int, bool>> x(n*2);
    for (int i = 0; i < n; i++) {
        x[i*2] = {a[i].first, false};
        x[i*2+1] = {a[i].second, true};
    }

    sort(x.begin(), x.end());

    int result = 0;
    int c = 0;
    for (int i = 0; i < n * 2; i++) {
        if (i > 0 && x[i].first > x[i-1].first && c > 0)
            result += x[i].first - x[i-1].first;
        if (x[i].second)
            c--;
        else
            c++;
    }
    return result;
}

int orientation(point a, point b, point c) {
    double v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if (v < 0) return -1; // clockwise
    if (v > 0) return +1; // counter-clockwise
    return 0;
}

bool cw(point a, point b, point c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o < 0 || (include_collinear && o == 0);
}

void convex_hull(vector<point>& a, bool include_collinear = false) {
    point p0 = *min_element(a.begin(), a.end(), [](point a, point b) {
        return make_pair(a.y, a.x) < make_pair(b.y, b.x);
    });
    sort(a.begin(), a.end(), [&p0](const point& a, const point& b) {
        int o = orientation(p0, a, b);
        if (o == 0)
            return (p0.x-a.x)*(p0.x-a.x) + (p0.y-a.y)*(p0.y-a.y)
                < (p0.x-b.x)*(p0.x-b.x) + (p0.y-b.y)*(p0.y-b.y);
        return o < 0;
    });
    if (include_collinear) {
        int i = (int)a.size()-1;
        while (i >= 0 && collinear(p0, a[i], a.back())) i--;
        reverse(a.begin()+i+1, a.end());
    }

    vector<point> st;
    for (int i = 0; i < (int)a.size(); i++) {
        while (st.size() > 1 && !cw(st[st.size()-2], st.back(), a[i], include_collinear))
            st.pop_back();
        st.push_back(a[i]);
    }

    a = st;
}

signed main(){_

    int n;
    cin >> n;

    while(n!=0) {

        vector<point> points;

        for(int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;

            points.pb(point(x, y));
        }

        convex_hull(points, 0);

        reverse(points.begin(), points.end());

        vector<point> resp;
        resp.pb(points[0]);
        for(int i = 1; i < sz(points); i++) {
            if(points[i] == points[i-1]) continue; 
            resp.pb(points[i]);
        }

        cout << sz(resp) << endl;
        for(point p : resp) {
            cout << p.x << ' ' << p.y << endl;
        }

        cin >> n;
    }

    return 0;
}
