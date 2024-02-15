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
#define MODN 998244353
#define int long long // -> solução divina
#define maxn 312345

using namespace std;

int resp;
vi adj[maxn];
int vis[maxn];

int dp[maxn];

void dfs(int node) {
    if(vis[node]) return;
    vis[node] = 1;

    dp[node] = 1;
    int sum = 0;
    for(int v : adj[node]) {
        if (!vis[v]) {
            dfs(v);
            dp[node] = (dp[node] * (dp[v] + 1))%MODN;
            sum = (sum + dp[v])%MODN;
        }
    }

    // dp[node] = (MODN + dp[node] - 1) %MODN;

    // dp[node] = (dp[node] + 1)%MODN;
    // if (dp[node] == 0) dp[node] = 1;

    // cout << node << ' ' << dp[node] << endl;

    resp = (resp + dp[node]) %MODN;
}

void solve() {
    resp = 0;
    int n;
    cin >> n;

    for(int i = 1; i <=n; i++) adj[i].clear();
    for(int i = 1; i <=n; i++) vis[i] = 0;

    for(int i = 1; i <=n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(1);

    cout << resp + 1 << endl;

}

signed main(){_
    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
