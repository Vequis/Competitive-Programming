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

int prox[212345];
// int mark[212345];
int grau[212345];
vi adj[212345];
int vis[212345];

void solve() {
    int n, k;
    cin >> n >> k;

    for(int i = 1; i<=n; i++) prox[i] = -1;
    for(int i = 1; i<=n; i++) grau[i] = 0;
    for(int i = 1; i<=n; i++) vis[i] = 0;
    for(int i = 1; i<=n; i++) adj[i].clear();

    while(k--) {
        int prim;
        cin >> prim;

        if (n == 1) continue;
        int u;
        cin >> u;
        for(int i = 2; i < n; i++) {
            int v;
            cin >> v;
            adj[u].pb(v);
            grau[v]++;
            u = v;
        }
    }

    queue<int> fila;
    for(int i = 1; i <=n; i++) {
        if (grau[i] == 0) fila.push(i);
    }

    int cont = 0;
    while(!fila.empty()) {
        int topo = fila.front();
        fila.pop();
        // cout << topo << endl;
        // if (!vis[topo]) cont++;

        cont++;

        vis[topo] = 1;

        for (int v : adj[topo]) {
            grau[v]--;
            if (grau[v] == 0) fila.push(v);
        }
    }

    if (cont == n or n == 1) cout << "YES" << endl;
    else cout << "NO" << endl;

}

signed main(){_

    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
