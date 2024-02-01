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
#define maxn 112345
using namespace std;

int dist[maxn];
bool vis[maxn];
vii adj[maxn];

void dijkstra(int node){
    memset(dist, INF, sizeof(dist));
    priority_queue<ii, vii, greater<ii> > fila;

    fila.push({0, node});
    dist[node] = 0;

    while(!fila.empty()){
        int u = fila.top().sc;
        fila.pop();

        if(vis[u]) continue;
        vis[u]  = 1;

        for(ii p : adj[u]) {
            int v= p.fs;
            int w = p.sc;

            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                fila.push({dist[v], v});
            }
        }
    }
}

signed main(){_

    int n, m;
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].eb(v, w);
        adj[v].eb(u, w);

    }

    dijkstra(1);

    for(int i=1; i<=n; i++) cout << i << ' ' << dist[i] << endl;

    return 0;
}