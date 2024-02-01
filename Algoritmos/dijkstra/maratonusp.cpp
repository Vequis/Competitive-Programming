#include<bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(x) (int)(x).size()
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define all(x)  (x).begin() , (x).end()
#define fs first
#define sc second
#define vii vector<ii>
#define endl '\n'
#define ll long long int
#define MAXX 1073741823
#define MAX (1<<20)
#define INF 0x3f3f3f3f
#define MODN 1000000007
#define int long long // -> solução divina
#define ii pair<int, int>

using namespace std;

int n, m;
vector<vii> adj(100100);

void dijkstra(){
    vi dist(n+2, -1);
    priority_queue< ii > pq;
    dist[1] = 0;;
    pq.push(ii(dist[1], 1));

    while(!pq.empty()){
        ii p = pq.top(); pq.pop();
        int distatual = p.fs;
        int u = p.sc;
    
        if(distatual < dist[u]) continue;

        for(auto it1 : adj[u]){
            int v=it1.fs;
            int custo = it1.sc;

            if(dist[v] == -1 or dist[u] + custo < dist[v]){
                dist[v] = dist[u] + custo;
                pq.push(ii(dist[v], v));
            }
        }
    }

    for(int i=1; i<=n; i++) cout << dist[i] << ' ';
    cout << endl;
}

signed main(){_

    cin >> n >> m;

    for (int i=1; i<=m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].pb(ii(b, c));
    } 

    dijkstra();

    return 0;
}
