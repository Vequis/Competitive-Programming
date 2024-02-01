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
#define maxn 212345

using namespace std;

int dista[maxn];
int distb[maxn];
int dist0[maxn];
vi adj[maxn];
vi alc[maxn];
int n, m, a, b;
queue<int> fila;
int vis[maxn];

signed main(){_

    cin >> n >> m;
    cin >> a >> b;

    for(int i=0; i<m; i++){
        int x,  y;
        cin >> x >> y;
        adj[x].pb(y);
        alc[y].pb(x);
    }

    for(int i=0; i<=n; i++) distb[i] = maxn;
    distb[b] = 0;
    fila.push(b);
    vis[b] = b;
    while(!fila.empty()){
        int u = fila.front();
        fila.pop();

        for(int v : alc[u]){
            if(!vis[v]){
                vis[v] = 1;
                distb[v] = distb[u] + 1;
                fila.push(v);
            }
        }
    }

    for(int i=0; i<=n; i++) vis[i] = 0;
    for(int i=0; i<=n; i++) dist0[i] = maxn;
    dist0[0] = 0;
    fila.push(0);
    vis[0] = 1;
    while(!fila.empty()){
        int u = fila.front();
        fila.pop();

        for(int v : adj[u]){
            if(!vis[v]){
                vis[v] = 1;
                dist0[v] = dist0[u] + 1;
                fila.push(v);
            }
        }
    }

    for(int i=0; i<=n; i++) vis[i] = 0;
    for(int i=0; i<=n; i++) dista[i] = maxn;
    dista[a] = 0;
    fila.push(a);
    vis[a] = a;
    while(!fila.empty()){
        int u = fila.front();
        fila.pop();

        for(int v : alc[u]){
            if(!vis[v]){
                vis[v] = 1;
                dista[v] = dista[u] + 1;
                fila.push(v);
            }
        }
    }

    int resp = INT_MAX;
    for(int i=0; i<=n; i++){
        // cout << dist0[i] << ' ' <<  dista[i]  << ' ' << distb[i] << endl;
        resp = min(resp, dist0[i] + dista[i] + distb[i]);
    }

    cout << resp << endl;

    return 0;
}
