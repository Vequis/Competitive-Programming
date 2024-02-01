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

using namespace std;

int pai[MAX];
priority_queue< ii, vii, greater<ii> > pq;
int dist[MAX];
vector<vii> adj(MAX);

void init(int n){
    for (int i=0; i<=n; i++){
        pai[i] = i;
    }
}

int find(int u){
    if (pai[u] == u) return u;
    return pai[u] = find(pai[u]);
}

void uniao(int u, int v){
    u = find(u);
    v = find(v);
    pai[v] = u;
}

struct aresta{
    int u, v;
    int w;
};

aresta arestas[MAX];
int n, m;

int cmp(aresta a, aresta b){
    return a.w < b.w;
}

int kruskal(){
    int ans = 0;
    sort(arestas, arestas + m, cmp);

    for (int i=0; i<m; i++){
        if (find(arestas[i].u) != find(arestas[i].v)){
            ans += arestas[i].w;
            uniao(arestas[i].u,arestas[i].v);
        }
    }

    return ans;
}

int u, v, w;

void dijkstra(int s){
    pq.push({0,s});
    dist[s] = 0;
    while(!pq.empty()){
        ii par = pq.top(); pq.pop();
        int w = par.fs;
        int u = par.sc;

        for (int i=0; i<sz(adj[u]); i++){
            v = adj[u][i].fs;
            if (dist[v] > w + adj[u][i].sc){
                dist[v] = w + adj[u][i].sc;
                pq.push({dist[v], v});
            }
        }
    }
}

int main(){_
   
   
    /*
    Dijkstra;
    cin >> n >> m;

    for (int i=0; i<=n; i++) dist[i] = INF; 

    for (int i=0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].eb(v,w);
        adj[v].eb(u,w);
    }

    dijkstra(1);

    cout << dist[7] << endl;
    */

    /*
    Kruskal
    init(n);

    for (int i=0; i<m; i++){
        cin >> u >> v >> w;
        arestas[i] = {u,v,w};
    }

    cout << kruskal() << endl;
    */


    return 0;
}