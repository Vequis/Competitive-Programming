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
#define maxl 40

using namespace std;

int n;

bool vis[212345];
int pai[212345];
vi adj[212345];
int up[212345];
int down[212345];
bool marked[212345];
int nivel[212345];
int ancestral[212345][maxl];
int last;

void dfs_down(int node) {

    vis[node] = 1;
    int resp = -1;
    if(marked[node]) resp = 0;
    for (int v : adj[node]) {
        if (!vis[v]) {
            dfs_down(v);
            pai[v] = node;

            resp = max(resp, 1 + down[v]);
        }
    }

    down[node] = resp;
    // cout << node << ' ' << down[node] << endl;

    return;
}

void dfs(int node){
    if(marked[node] and nivel[node] > nivel[last]) last = node;
    for (int x : adj[node]){
        if(nivel[x] == -1){
            pai[x] = node;
            nivel[x] = nivel[node] + 1;
            dfs(x);
        }
    }
}

void ancestrais(){
    memset(ancestral, -1, sizeof(ancestral));

    for(int i=1; i<=n; i++) ancestral[i][0] = pai[i];

    for(int j=1; j<maxl; j++){
        for(int i=1; i<=n; i++){
            if(ancestral[i][j-1] != -1){
                ancestral[i][j] = ancestral[ancestral[i][j-1]][j-1];
                // cout << i << ' ' << j << ' ' << ancestral[ancestral[i][j-1]][j-1] << endl;
            }
        }
    }
}

int lca(int u, int v){
    if(nivel[u] < nivel[v]) swap(u, v);

    // cout << 'i' << endl;
    // cout << u << ' ' << v << endl;

    //Fazendo com que nivel[u] == nivel[v]
    for(int i=20; i>=0; i--){
        if(nivel[u] - (1<<i) >= nivel[v]){
            u = ancestral[u][i];
            // cout << u << ' ' << i << endl;
        }
    }

    // cout << '*' << endl;
    // cout << u << ' ' << v << endl;
    // cout << nivel[u] << ' ' << nivel[v] << endl;

    if(u==v) return u;

    for(int i= maxl -1; i>=0; i--){
        if(ancestral[u][i]!= -1 && ancestral[u][i] != ancestral[v][i]){
            u = ancestral[u][i];
            v = ancestral[v][i];
        }
    }

    return ancestral[u][0];

}

signed main(){_

    int t;
    cin >> t;

    while(t--) {
        int k;
        cin >> n >> k;

        for(int i = 1; i <=n; i++) marked[i] = 0;
        for(int i = 1; i <=n; i++) vis[i] = 0;
        for(int i = 1; i <=n; i++) nivel[i] = -1;
        for(int i = 1; i <=n; i++) pai[i] = -1;
        // memset(nivel, -1, sizeof(nivel));

        vi dots;

        for(int i = 0; i < k; i++) {
            int a;
            cin >> a;
            dots.eb(a);
            marked[a] = 1;
        }


        for(int i = 0; i < n-1; i++) {
            int a, b;
            cin >> a >> b;

            if (a > b) swap(a, b);

            adj[a].pb(b);
            adj[b].pb(a);
        }

        nivel[1] = 0;
        dfs(1);
        ancestrais();

        // for(int i = 1; i <=n; i++) {
        //     cout << i << endl;
        //     cout << pai[i] << ' ' << nivel[i] << endl;
        // }

        int pivo = dots[0];
        int npivo;

        int maxd = 0;

        for(int i = 1; i < sz(dots); i++) {
            pivo = lca(dots[i], pivo);
            // cout << pivo << endl;
        }

        for(int i = 1; i <= n; i++) nivel[i] = -1;
        nivel[pivo] = 0;
        dfs(pivo);

        // cout << last << endl;
        int x = last;

        for(int i = 1; i <= n; i++) nivel[i] = -1;
        nivel[x] = 0;
        dfs(x);

        // cout << last << endl;

        cout << (nivel[last] + 1)/2 << endl;

        for(int i = 1; i <=n; i++) adj[i].clear();
    }

    return 0;
}
