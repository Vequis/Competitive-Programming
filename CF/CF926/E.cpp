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
#define maxn 112345
#define int long long // -> solução divina

using namespace std;

int vis[maxn];
vi adj[maxn];
int ordem[maxn];

int t;

set<ii> queries;
map<int, int> abertos;

vi ini[maxn];

void dfsordem(int node) {
    vis[node] = 1;
    ordem[node] = t;
    t++;

    for(int v : adj[node]) {
        if (!vis[v]) dfsordem(v);
    }
}

int resp = 0;

void dfs(int node) {
    vis[node] = 1;

    for (int b : ini[node]) {
        int a = node;
        int bc = b;
        if (a > bc) swap(a, bc);
        if (queries.find({a, bc}) != queries.end()) {
            // resp++;
            queries.erase(queries.find({a, bc}));
        }
    }

    resp+=abertos[node];

    for(int v : adj[node]) {
        if (!vis[v]) dfs(v);
    }
}

void solve() {


    int n;
    cin >> n;
    for(int i = 1; i <=n; i++) vis[i] = 0;
    for(int i = 1; i <=n; i++) adj[i].clear();
    abertos.clear();
    resp = 0;
    t = 1;

    for(int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    // dfsordem(1);

    int q;
    cin >> q;

    for(int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        ini[a].pb(b);
        ini[b].pb(a);
        if (a > b) swap(a, b);
        queries.insert({a, b});
    }

    dfs(1);

    cout << resp << endl;
} 

signed main(){_
    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
