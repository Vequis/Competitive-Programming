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

vii adj[1123];
set<int> paths[1123];

void solve() {
    int n;
    cin >> n;
    
    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        adj[a].eb(b, w);
    }

    queue<ii> fila;
    paths[1].insert(0);
    fila.push({1, 0});

    while(!fila.empty()) {
        ii topo = fila.front(); fila.pop();

        int u = topo.fs;
        int p = topo.sc;

        // cout << u << ' ' << p << endl;

        for (ii edge : adj[u]){
            int v = edge.fs;
            int w = edge.sc;

            if (paths[v].find(w xor p) == paths[v].end()) {
                fila.push({v, w xor p});
                paths[v].insert(w xor p);
            }
        }
    }   

    if (paths[n].empty()) {
        cout << -1 << endl;
    } else {
        cout << *(paths[n].begin()) << endl;
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