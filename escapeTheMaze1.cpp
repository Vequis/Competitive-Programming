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
#define int long long

using namespace std;

int n, l;
vi adj[212345];

int timer; //Lembrar de zerar o timer
vi tin, tout;
vector<vi> up;
vi leafs, depth;

void dfs(int v, int p) {
    tin[v] = ++timer;
    up[v][0] = p;
    if(v!= p) depth[v] = depth[p] + 1;

    for(int i = 1; i <= l; ++i) {
        up[v][i] = up[up[v][i-1]][i-1];
    }

    bool is_leaf = 1;
    for(int u : adj[v]) {
        if (u!=p) {
            dfs(u, v);
            is_leaf = 0;
        }

    }
    if (is_leaf) leafs.pb(v);

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v) { //is u ancestor of v?
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;

    for(int i = l; i>=0; --i) {
        if(!is_ancestor(up[u][i], v)) u = up[u][i];
    }

    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n+1);
    tout.resize(n+1);
    depth.resize(n+1);
    timer = 0;
    l = ceil(log2(n));
    leafs.clear();
    depth[root] = 0;
    up.assign(n+1, vector<int>(l+1));
    dfs(root, root);
}

signed main(){_

    int t;
    cin >> t;

    while(t--) {
        int k;
        cin >> n >> k;

        vi friends;        

        for(int i = 0; i < k; i++) {
            int a;
            cin >> a;
            friends.pb(a);
        }

        for(int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;

            adj[u].pb(v);
            adj[v].pb(u);
        }

        preprocess(1);
    
        // cout << lca(4, 5) << '*' << depth[lca(4, 5)] << ' ' << depth[5] << endl;
        bool friends_win = 1;

        for(int l : leafs) {
            bool reachable = 1;
            for(int f : friends) {
                // cout << l << ' ' << f << endl;
                if(depth[f] - depth[lca(l, f)] <= depth[lca(l, f)]) {
                    // cout << '^' << endl;
                    reachable = 0;
                }
            }

            if (reachable) friends_win = 0;
        }

        if(friends_win) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }

        for(int i = 1; i <= n; i++) adj[i].clear();
    }


    return 0;
}
