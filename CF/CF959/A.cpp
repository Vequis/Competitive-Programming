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

int n, m;

ii f(int a, int b) {
    ii p = {a + 1, b + 1};
    if (a + 1 > n) p.fs = 1;
    if (b + 1 > m) p.sc = 1;
    return p;
}

void solve() {
    cin >> n >> m;
    if (n == 1 and m == 1) {
        cin >> n;
        cout << -1 << endl;
        return;
    }

    int a[n+1][m+1];
    int b[n+1][m+1];
    for (int i = 1; i<=n; i++) {
        for (int j = 1; j<=m; j++) {
            cin >> a[i][j];
            ii p = f(i, j);
            b[p.fs][p.sc] = a[i][j];
        }
    }

    for (int i = 1; i<=n; i++) {
        for (int j = 1; j<=m; j++) {
            cout << b[i][j] << ' ';
        }
        cout << endl;
    }

    return;
}

signed main(){_
    int t;
    cin >> t;
    // t=1;

    while(t--) {
        solve();
    }

    return 0;
}