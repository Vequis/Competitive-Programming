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

int n, m, u, v, w, s, d, t;
vi dist;
vvii adj;
priority_queue< ii, vii, greater<ii> > pq;

void dijkstra(int s){
    dist[s] = 0;
    pq.push({0,s});

    while(!pq.empty()){
        ii topo = pq.top();
        pq.pop();
        d = topo.fs;
        u = topo.sc;

        if (dist[u] < d) continue;

        for (ii par : adj[u]) {
            v = par.fs; w = par.sc;
            if (dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int casos;

int main(){_

    cin >> casos;

    for (int i=1; i<=casos; i++){

        cin >> n >> m >> s >> t;

        adj = vvii(n+1);
        dist = vi(n+1, INT_MAX);

        for (int j=0; j<m; j++){
            cin >> u >> v >> w;
            adj[u].eb(v,w);
            adj[v].eb(u,w);
        }

        dijkstra(s);

        cout << "Case #" << i << ": "; 

        if (dist[t] == INT_MAX){
            cout << "unreachable" << endl;
        } else {
            cout << dist[t] << endl;
        }
        
        while(!pq.empty()) pq.pop();
    }

    return 0;
}