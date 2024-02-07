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
#define maxm 200200
#define maxn 212345

using namespace std;

struct aresta{
    int peso;
    int a, b;
};

bool comp(aresta a, aresta b){
    return a.peso > b.peso;
}

int n, m;
aresta arestas[maxm];
int pai[maxn];
int peso[maxn];
aresta mst[maxm]; //Aqui guardaremos a arvore

//sem binary lifting
int find(int x){
    if(pai[x] == x) return x;
    return pai[x] = find(pai[x]); //path compression
}

void join(int a, int b){
    a = find(a);
    b = find(b);

    if(peso[a] > peso[b]) pai[b] = a;
    else if(peso[a] < peso[b]) pai[a] = b;
    else {
        pai[b] = a;
        peso[a]++;
    }
}

aresta resp;
int indresp;

void kruskal(){
    // cout << m << endl;
    for (int i = 1; i <= n; i++) pai[i] = i;

    sort(arestas+1, arestas+1+m, comp);

    int size = 0;

    for (int i=1; i<=m; i++) {
        int a = arestas[i].a;
        int b = arestas[i].b;
        if(find(a) != find(b)){
            join(a,b);

            mst[++size] = arestas[i];
            // if(size==n-1) return;
        } else {
            resp = arestas[i];
            indresp = i;
        }
    }
}

vi adj[212345];

int x;

void dfs(int node) {
    // cout << node << ' ' << pai[node] << ' ' << 'x' << endl;
    if (node == x) return;
    for (int v : adj[node]) {
        if (pai[v] == -1) {
            pai[v] = node;
            dfs(v);
        }
    }
}

signed main(){_

    int t;
    cin >> t;
    while(t--) {
            cin >> n >> m;

            for(int i=1; i<=m; i++){
                int u, v, w;
                cin >> u >> v >> w;

                arestas[i].peso = w;
                arestas[i].a = u;
                arestas[i].b = v;
            }

            // cout << m << endl;
            kruskal();

            int u = resp.a;
            int v = resp.b;
            // cout << u << ' ' << v << ' ' << indresp << '*' << endl;
            int comp = find(u);

            for (int i = 1; i <=m; i++) {
                int p = arestas[i].a;
                if (find(p) == comp and i != indresp) {
                    // cout << "aresta: " << arestas[i].a << ' ' << arestas[i].b << ' ' << i << endl;
                    adj[arestas[i].a].pb(arestas[i].b);
                    adj[arestas[i].b].pb(arestas[i].a);
                }
            }

            for(int i = 1; i <=n; i++) pai[i] = -1;
            x = v;
            pai[u] = u;
            dfs(u);

            int it = v;
            vi resposta;
            while(it != u) {
                resposta.eb(it);
                it = pai[it];
            }
            resposta.eb(u);

            cout << resp.peso << ' ' << sz(resposta) << endl;
            for(int a : resposta) cout << a << ' ';
            cout << endl;

            for(int i = 1; i <=n; i++) adj[i].clear();
    }
    // for (int i = 1; i < n; i++) {
    //     cout << mst[i].a << ' ' << mst[i].b << endl;
    // }

    return 0;
}
