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

int b[212345];
vii adj[212345];
int dist[212345];
int max_bat[212345];
int proc[212345];

void dijkstra_max(int node) {
    max_bat[node] = b[node];

    priority_queue<ii> pq; // {max, node}
    pq.push({max_bat[node], node});

    while(!pq.empty()) {
        ii topo = pq.top(); pq.pop();

        // int maximo = topo.fs;
        int u = topo.sc;

        if (proc[u]) continue;
        proc[u] = 1;

        for (ii edge : adj[u]) {
            int v = edge.fs;
            int w = edge.sc;

            if (w <= max_bat[u] and !proc[v]) {
                max_bat[v] = max_bat[u] + b[v];
                pq.push({max_bat[v], v});
            }
        }
    }
}

void dijkstra(int node) {
    priority_queue<ii, vii, greater<ii>> pq;
    dist[node] = 0;
    pq.push({dist[node], node});

    while(!pq.empty()) {
        ii t = pq.top(); pq.pop();

        // int distancia = t.fs;
        int u = t.sc;

        if (proc[u]) continue;
        proc[u] = 1;

        for (ii p : adj[u]) {
            int v = p.fs;
            int w = p.sc;

            int nec = max(dist[u], w);

            if (max_bat[u] < nec) continue;
            if (nec < dist[v]) {
                dist[v] = nec;
                pq.push({dist[v], v});
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <=n; i++) cin >> b[i];

    for (int i = 1; i <=n; i++) {
        adj[i].clear();
        dist[i] = INF;
        proc[i] = 0;
        max_bat[i] = -1;
    }

    for (int i = 1; i <=m; i++) {
        int s, t, w;
        cin >> s >> t >> w;
        adj[s].pb({t, w});
    }

    dijkstra_max(1);
    // for (int i = 1; i <=n; i++) cout << '*' << max_bat[i] << endl;
    // cout << endl;

    for (int i = 1; i <=n; i++) proc[i] = 0;

    dijkstra(1);

    if (dist[n] == INF) {
        cout << -1 << endl;
    } else {
        cout << dist[n] << endl;
    }
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