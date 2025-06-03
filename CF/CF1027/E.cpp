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

int danger[212345];
int threat[212345];
int min_threat[212345];
int vis[212345];
vi adj[212345];

void dfs(int node) {
    vis[node] = 1;

    for (int v : adj[node]) {
        if (!vis[v]) {
            threat[v] = max(danger[v] - min_threat[node], danger[v]);
            min_threat[v] = danger[v] - threat[node];
            dfs(v);
        }
    }
}

void solve() {
    int n;
    cin >> n;

    for (int i = 1; i <=n; i++) cin >> danger[i];
    for (int i = 1; i <=n; i++) vis[i] = 0;
    for (int i = 1; i <=n; i++) adj[i].clear();

    for (int i = 1; i <=n-1; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    threat[1] = danger[1];

    dfs(1);
    for (int i = 1; i <= n; i++) {
        cout << threat[i] << ' ' ;
    }
    cout << endl;

}

signed main(){_
    int t;
    cin >> t;
    // t=1;

    while(t--) {
        solve();
    }

    return 0;
}