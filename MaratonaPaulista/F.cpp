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

using namespace std;

vi dists;
int temps[312345];
bool vis[312345];
vi adj[312345];
int dist[312345];
int n, k;

int dfs(int node) {
    vis[node] = 1;

    int resp = 0;
    for (int v : adj[node]) {
        if (!vis[v]) {
            dist[v] = dist[node] + 1;
            int resp_v = dfs(v);
            if (resp_v != 0) resp += resp_v + 2;
            else if (temps[v] > k) resp += 2;

        }
    }

    return resp;
}

void solve() {

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> temps[i+1];
    }   

    for(int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dist[1] = 0;
    int resp = dfs(1);

    int maior_dist = 0;
    for (int i = 2; i <=n; i++) {
        if (temps[i] > k and dist[i] > maior_dist) maior_dist = dist[i];
    }

    cout << resp - maior_dist << endl;

    //cout << dfs(1) - 
}

signed main(){_
    int t;
    // cin >> t;
    t=1;

    while(t--) {
        solve();
    }

    return 0;
}