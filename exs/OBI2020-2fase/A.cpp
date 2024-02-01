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
// #define endl '\n'
#define ll long long int
#define MAXX 1073741823
#define MAX (1<<10)
#define INF 0x3f3f3f3f
#define MODN 1000000007

using namespace std;

int s,t,p, u, v;
vi h;
vector< vi > adj(MAX);
int vis[MAX];

int dfs(int node){ //Qual é o tamanho do maior caminho saido de 'node'
    if (vis[node]) return 0; // se foi visitado, retorna 0; 
    vis[node] = 1; // Foi visitado = 1; Não foi visitado = 0;

    int ans = 1; // resposta

    for (int i=0; i<sz(adj[node]); i++){
        ans = max(ans, 1+dfs(adj[node][i]));
    }

    vis[node] = 0;

    return ans;
}

int main(){_

    cin >> s >> t >> p;

    h.pb(0);

    for (int i=1; i<=s; i++){
        int x;
        cin >> x;
        h.pb(x);
    }

    for (int i=0; i<t; i++){
        cin >> u >> v;
        if (h[u] > h[v]){
            adj[u].pb(v);
        } else if (h[v] > h[u]) {
            adj[v].pb(u);
        }
    }

    cout << dfs(p) - 1 << endl;

    return 0;
}