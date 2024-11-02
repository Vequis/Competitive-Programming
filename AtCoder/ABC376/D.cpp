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

vi adj[212345];
int vis[212345];
int dist[212345];

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].pb(b);
    }   

    queue<int> fila;

    fila.push(1);
    dist[1] = 0;
    vis[1] = 1;

    while(!fila.empty()) {
        int u = fila.front(); fila.pop();
        for (int v : adj[u]) {
            if (v == 1) {
                cout << dist[u] + 1 << endl;
                return;
            }
            if (!vis[v]) {
                fila.push(v);
                dist[v] = dist[u] + 1;
                vis[v] = 1;
            }
        }
    }

    cout << -1 << endl;
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