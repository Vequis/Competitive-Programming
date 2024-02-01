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
#define vvi vector<vi>
#define vvii vector<vii>
#define endl '\n'
#define ll long long int
#define MAX (1<<10) //2^10 = 1024

using namespace std;

int u,v,w, n, m, d, s;
vi dist;
priority_queue<ii, vii, greater<ii> > pq;
vvii adj;

void dijkstra(int s){
    dist[s] = 0;

    pq.push({0,s});

    while(!pq.empty()){
        ii topo = pq.top(); pq.pop();
        u = topo.sc;
        d = topo.fs;

        for (auto [v,w] : adj[u]){
            if (dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main(){_

    cin >> n >> m;

    adj = vvii(n+1);
    dist = vi(n+1, INT_MAX);

    for (int i=1; i<=m; i++){
        cin >> u >> v >> w;
        adj[u].eb(v,w);
        adj[v].eb(u,w);
    }

    cin >> s;

    dijkstra(s);

    for (int i=1; i<=n; i++){
        cout << i << " : " << dist[i] << endl;
    }

    return 0;
}