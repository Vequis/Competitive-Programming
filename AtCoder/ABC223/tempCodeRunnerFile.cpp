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

vi adj[212345];
int vis[212345];

vector<int> dfs(int node) {

    vis[node] = 0;

    vi resp;

    for(int v : adj[node]) {
        // cout << node << ' ' << v << endl;
        // cout << vis[node] << ' ' << vis[v] << endl;
        if (vis[v] == 0) {
            vi err;
            err.pb(-1);
            return err;
        } else if (vis[v] == -1) {
            vi vx = dfs(v);
            resp.insert(resp.end(), vx.begin(), vx.end());
        }

    }

    resp.pb(node);
    vis[node] = 1;
    return resp;

}

bool flag = true;

signed main(){

    int n, m;

    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        adj[b].pb(a);
    }

    for(int i = 1; i <=n; i++) sort(all(adj[i]));
    for(int i = 1; i <=n; i++) vis[i] = -1;

    // vi resp = dfs(1);


    vi resp;

    for(int i = 1; i <=n; i++) {
        if(vis[i] == -1) {
            vi aux = dfs(i);
            resp.insert(resp.end(), aux.begin(), aux.end());
        }
    }

    for(int x : resp) {
        if (x == -1) flag = false;
    }

    if(flag) {
        for (int x : resp) cout << x << ' ';
        cout << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
