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

using namespace std;

ll ans;
int n, a, b, c, id;
int vis[MAX];
vii arestas;
vector<vii> adj(MAX);

int dfs(int u, int aresta){
    if (vis[u]) return 0;
    vis[u] = 1;

    int var = 1;

    for (int i=0; i<sz(adj[u]); i++){
        if (adj[u][i].sc == 0) var += dfs(adj[u][i].fs, aresta);
        else if (adj[u][i].sc > aresta) var += dfs(adj[u][i].fs, aresta);
    } 
    vis[u] = 0;

    return var;

}

int main(){_

    arestas.eb(0,0);

    cin >> n;
    for (int i=0; i<n-1; i++){
        cin >> a >> b >> c;
        if (c==1) {
            arestas.eb(a,b);
            c = sz(arestas)-1;
            // cout << c << endl;
        } 
        adj[a].eb(b,c);
        adj[b].eb(a,c);
    }

    // cout << dfs(3,1) << endl;

    for (int i=1; i<=sz(arestas)-1; i++){
        // cout << arestas[i].fs << ' ' << i << endl;
        a = dfs(arestas[i].fs, i);
        b = dfs(arestas[i].sc, i);
        ans += a*b;
    }

    cout << ans << endl;

    return 0;
}