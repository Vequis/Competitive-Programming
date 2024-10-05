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

vi adj[112345];
int comp[112345];

void dfs(int node) {
    
    for (int viz : adj[node]) {
        if (comp[viz] == 0) {
            comp[viz] = comp[node];
            dfs(viz);
        }
    }
}
void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i<=n; i++) comp[i] = 0;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    for (int i = 1; i <=n; i++) {
        if (comp[i] == 0) {
            comp[i] = i;
            dfs(i);
        }
    }

    int q;
    cin >> q;

    while(q--) {
        int a, b;
        cin >> a >> b;

        if (comp[a] == comp[b]) cout << "S" << endl;
        else cout << "N" << endl;
    }
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