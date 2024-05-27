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
    int m, n;
    map<int, int> a;
    vi b, c;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x] = 1;
        c.pb(x);
    }

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        b.pb(x);
        c.pb(x);
    }

    sort(all(c));

    for (int i = 0; i < n + m - 1; i++) {
        if (a[c[i]] and a[c[i+1]] and c[i] != c[i+1]) {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;

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