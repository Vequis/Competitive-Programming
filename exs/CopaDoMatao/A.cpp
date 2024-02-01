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
#define PI 4 * atan(1)
#define int long long // -> solução divina

using namespace std;

double ang (int x1, int y1, int x2, int y2) {
    return atan((y2-y1)/(x2-x1)) * 180/PI;
}

double dist (int x1, int y1, int x2, int y2) {
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

double angr (int xp1, int yp1, int xp2, int yp2, int x1, int y1, int x2, int y2) {
    double ang1, ang2;
    if (xp1 == xp2)
        ang1 = 90;
    else 
        ang1 = ang(xp1, yp1, xp2, yp2);
    if (x1 == x2)
        ang2 = 90;
    else 
        ang2 = ang(x1, y1, x2, y2);
    
    return ang2-ang1;
}

int x[112345], y[112345];
double d[112345];

signed main(){

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i];
        cin >> y[i];
    }

    cout << 'o' << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; angr(x[i], y[i], x[i+1], y[i+1], x[i+j], y[i+j], x[i+j+1], y[i+j+1]) < 90 && j < n; j++) {
            d[i] += dist(x[i+1], y[i+1], x[i], y[i]);
        }
        cout << fixed;
        cout << setprecision(8) << d[i] << endl;
    }

    return 0;
}