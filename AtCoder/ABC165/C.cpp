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

int cont = 0;
int resp = 0;

vector<tuple<int, int, int, int>> queries;

void generate(vi &v) {
    if (sz(v) == n) {
        cont++;

        int cur = 0;
        for (auto t : queries) {
            int a, b, c, d;
            tie(a, b, c, d) = t;
        
            if (v[b-1] - v[a-1] == c) cur += d;
        }

        resp = max(resp, cur);
        return;
    }

    int s = sz(v);
    for (int i = (s == 0 ? 1 : v[s-1] ); i<=m; i++) {
        v.pb(i);
        generate(v);
        v.pop_back();
    }
}

void solve() {
    int q;
    cin >> n >> m >> q;

    for (int i = 0; i < q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        queries.eb(a, b, c, d);
    }

    vi v;
    generate(v);

    cout << resp << endl;
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