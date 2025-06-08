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
#define PI 3.14159265358979323846

//https://atcoder.jp/contests/abc168/tasks/abc168_c
void solve() {
    double a, b, h, m;
    cin >> a >> b >> h >> m;

    double angleh = 30 * h + (m/60) * 30.0;
    double anglem = 6*m;
    double delta = abs(angleh - anglem);

    delta = delta * PI/180.0;

    // cout << angleh << ' ' << anglem << ' ' << delta << ' ' << cos(delta) << endl;
    double x = a*a + b*b - 2*a*b*cos(delta);
    // cout << x << endl;
    x = sqrt(x);

    cout << setprecision(10);
    cout << fixed << x << endl;
}

signed main(){_
    int t;
    // cin >> t;
    t=1;

    while(t--) {
        solve();
    }

    return 0;
}