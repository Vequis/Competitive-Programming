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

void solve() {
    int n;
    cin >> n;

    vector<double> vmin;
    vector<double> vmax;

    for (int i = 1; i<=n; i++) {
        double a, b;
        cin >> a >> b;

        vmin.pb(i/b);
        if (a==0) vmax.pb(INF);
        else vmax.pb(i/a);

    }

    sort(all(vmin));
    sort(all(vmax));

    cout << fixed;
    cout << setprecision(7);
    if (vmin[n-1] <= vmax[0]) {
        cout << vmin[n-1] << endl;
    } else {
        cout << -1 << endl;
    }
}

signed main(){_
    int t;
    cin >> t;
    // t=1;

    int cont = 1;
    while(cont <= t) {
        cout << "Case #" << cont << ": ";
        solve();
        cont++;
    }

    return 0;
}