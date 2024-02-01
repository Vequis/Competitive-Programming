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
const int MAX = 1e5 + 5;

using namespace std;

int n, m;
vector< vi > adj(MAX);
int vis[MAX];
int dp[5*MAX]; // u, nodo que estamos;; v: nodo anterior

pair arestas[5*MAX];

int dfs(int aresta){
    if (dp[aresta]!=0) return dp[aresta];
    vis[u] = 1;
    int ans = 1;

    for (pair [v,id] : adj[u]){
        if (v>ant) ans = max(ans, dfs(v, u) + 1);
    }

    vis[u] = 0;
    return dp[u][ant] = ans;
}

int main(){_

    cin >> n >> m;

    for (int i=0; i<m; i++){
        int u, v;
        cin >>  u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for (int i=1; i<=n; i++){
        cout << dfs(i, 0) << ' ';
    }

    cout << endl;

    return 0;
}