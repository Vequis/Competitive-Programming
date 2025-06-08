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

int carga[112345];
ii pai[112345]; //{node, w}
int sum[112345]; // soma da subarvore
vii adj[112345];

int dfs(int node) {
    sum[node] = carga[node];

    for (ii p : adj[node]) {
        int v = p.fs;
        int w = p.sc;

        if (pai[v].fs == 0) {
            pai[v] = {node, w};
            sum[node] += dfs(v);
        }
    }

    return sum[node];
}

void solve() {
    int n;
    cin >> n;
    
    for (int i = 1; i <=n; i++) cin >> carga[i];

    for (int i = 1; i < n; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        adj[b].eb(a, w);
        adj[a].eb(b, w);
    }

    pai[1] = {1, -1};
    dfs(1);

    int resp = 0;
    for (int i = 2; i <=n; i++) {
        resp += pai[i].sc * abs(sum[i]);
    }

    cout << resp << endl;
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