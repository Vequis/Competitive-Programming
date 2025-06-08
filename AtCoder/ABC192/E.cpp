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

//07:35

int INFLL = INF;
priority_queue<ii, vii, greater<ii>> pq;
int dist[112345];
int proc[112345];
vector<tuple<int, int, int>> adj[112345];

void dijkstra(int node) {

    dist[node] = 0;
    pq.push({0, node});

    while(!pq.empty()) {
        ii topo = pq.top(); pq.pop();

        int u = topo.sc;
        int w = topo.fs;

        if (proc[u]) continue;
        proc[u] = 1;

        for (auto edge : adj[u]) {
            int v = get<0>(edge);

            int saida = dist[u];
            int k = get<2>(edge);
            if (saida%k != 0) saida = ((saida/k) + 1) * k;
            
            if (!proc[v] and saida + get<1>(edge) < dist[v]) {
                dist[v] = saida + get<1>(edge);
                pq.push({dist[v], v});
            }
        }
    }
}

void solve() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    for (int i = 1; i <=n; i++) dist[i] = INFLL;

    for (int i = 1; i<=m; i++) {
        int a, b, t, k;
        cin >> a >> b >> t >> k;

        adj[a].eb(b,t,k);
        adj[b].eb(a,t,k);
    }

    dijkstra(x);
    if (!proc[y]) {
        cout << -1 << endl;
        return;
    }
    cout << dist[y] << endl;
}

signed main(){_
    int t;
    // cin >> t;
    INFLL = INFLL*INF;
    t=1;

    while(t--) {
        solve();
    }

    return 0;
}