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

vi adj[maxn];
ii pesarestas[maxn];
ii arestas[maxn];
int nivel[maxn];
int vis[maxn];
int peso[maxn];
int pai[maxn];

bool cmp(int a[], int b[]){
    return a[0] < b[0];
}

void dfs(int node){
    peso[node] = 1;
    for(int x : adj[node]){
        if(!vis[x]){
            vis[x] = 1;
            nivel[x] = nivel[node] + 1;
            dfs(x);
            peso[node] += peso[x];
            pai[x] = node;
        }
    }
}

signed main(){_

    int n;
    cin >> n;

    int resp = 0;

    for(int i=1; i<=n-1; i++){
        int u, v, w;
        cin >> u >> v >> w;
        pesarestas[i] = {w, i};
        arestas[i] = {u, v};
        adj[u].pb(v);
        adj[v].pb(u);
    }

    nivel[1] = 1;
    vis[1] = 1;
    pai[1] = -1;
    dfs(1);

    sort(pesarestas+1, pesarestas+n);

    for(int i=1; i<=n-1; i++){
        int w = pesarestas[i].fs;
        ii aresta = arestas[pesarestas[i].sc];
        int u = aresta.fs;
        int v = aresta.sc;

        if(nivel[u] < nivel[v]) swap(u, v);

        while(pai[v] != -1) v = pai[v];

        cout << (peso[v] - peso[u]) * peso[u] * w << endl;
        resp += (peso[v] - peso[u]) * peso[u] * w;

        peso[v] -= peso[u];
        pai[u] = -1;
    }

    cout << resp << endl;

    return 0;
}
