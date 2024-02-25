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

struct aresta {
    int l, d, k, c;
    int a, b;
};

vector<aresta> adj[212345];
int dist[212345];
int vis[212345];
int resp[212345];

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        aresta uv;
        cin >> uv.l >> uv.d >> uv.k >> uv.c >> uv.a >> uv.b;
        adj[uv.b].eb(uv);
    }

    memset(dist, INF, sizeof(dist));
    dist[n] = 0;
    priority_queue<ii, vii, greater<ii>> pq;
    pq.push({0, n});
    while(!pq.empty()) {
        ii t = pq.top(); pq.pop();
        if (vis[t.sc]) continue;
        vis[t.sc] = 1;

        for (aresta v : adj[t.sc]) {
            int x = v.l + max(0LL, (t.fs - v.l)/v.d)*v.d;
            if (x + v.c < dist[v.a]) {
                dist[v.a] = x + v.c;
                pq.push({dist[v.a], v.a});
            }
        }
    }

    memset(resp, INF, sizeof(resp));
    for(int i = 1; i<=n; i++) {
        for (aresta v : adj[i]) {
            if (dist[i] <= v.l + v.d*(v.k-1)) {
                resp[v.a] = min(resp[v.a], v.l + v.d*(v.k-1) + v.c);
            }
        }
    }

    for(int i = 1; i < n; i++) {
        if (resp[i] != INF) cout << resp[i] << endl;
        else cout << "Unreachable" << endl;

    }
}   

signed main(){_
    int t;
    // cin >> t;
    t = 1;

    while(t--) {
        solve();
    }

    return 0;
}
