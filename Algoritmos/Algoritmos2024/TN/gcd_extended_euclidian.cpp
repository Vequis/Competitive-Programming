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

//ax + by = g = mdc(a,b)
int gcd_extended(int a, int b, int& x, int& y) {
    if (a < b) return gcd_extended(b, a, y, x);
    if (b==0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd_extended(b, a%b, x1, y1);
    x = y1;
    y = x1 - y1*(a/b);
    return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd_extended(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

signed main(){_

    int x, y;
    // cin >> x >> y;

    cout << gcd_extended(355, 269, x, y) << endl;
    // cout << x << ' ' << y << endl;
    // 

    return 0;
}
