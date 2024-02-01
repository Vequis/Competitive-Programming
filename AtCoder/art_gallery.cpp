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

vector<int> adj[212345];
int dist[212345];
int pai[212345];
int h[212345];

signed main(){_

    int n, m, k;
    cin >> n >> m >> k;


    memset(dist, -1, sizeof(dist));

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    priority_queue<ii> fila;

    set<int> resp;
    for(int i = 0; i < k; i++) {
        int p, he;
        cin >> p >> he;
        h[p] = he;
        fila.push({h[p], p});
        dist[p] = 0;
        pai[p] = p;

        resp.insert(p);
    }

    while(!fila.empty()) {
        ii p_topo = fila.top();
        int topo = p_topo.sc;
        fila.pop();

        // cout << topo << ' ' << p_topo.fs << endl;

        for(int v : adj[topo]) {
            if (dist[v] == -1) {
                pai[v] = pai[topo];
                dist[v] = dist[topo] + 1;
                if (p_topo.fs > 1) fila.push({p_topo.fs - 1, v});
                resp.insert(v);
            }
        }
    }


    cout << resp.size() << endl;
    for(int x : resp) cout << x << ' ';
    cout << endl;

    return 0;
}
