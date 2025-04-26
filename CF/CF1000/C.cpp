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

int vis[212345];
int degree[212345];
set<int> adj[212345];

int proib_node = -1;

void calculate_degree(int node) {
    vis[node] = 1;

    for (int v : adj[node]) {
        if (!vis[v] and v != proib_node) {
            degree[node]++;
            calculate_degree(v);
        }
    }
}

void solve() {
    int n;
    cin >> n;

    proib_node = -1;
    for (int i = 1; i <=n; i++) {
        vis[i] = 0;
        adj[i].clear();
        degree[i] = 1;  
    }

    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }   


    if (n == 2) {
        cout << 0 << endl;
        return;
    }

    degree[1] = 0;
    calculate_degree(1);

    // int max_degree = 0;
    // int max_node = -1;
    // for (int i = 1; i <=n; i++) {
    //     if (degree[i] > max_degree) {
    //         max_degree = degree[i];
    //         max_node = i;
    //     }
    // }


    //cout << max_degree << ' ' << max_node << endl;

    // int conn_comp = 1;
    // proib_node = max_node;
    // conn_comp += max_degree - 1;

    // for (int i = 0; i <=n; i++) {
    //     vis[i] = 0;
    //     degree[i] = 1;
    // }


    // for (int i = 1; i <=n; i++) {
    //     if (!vis[i] and proib_node != i) {
    //         degree[i] = 0;
    //         calculate_degree(i);
    //     }
    // }


    // degree[proib_node] = 0;

    // max_degree = 0;
    // max_node = -1;
    // for (int i = 1; i <=n; i++) {
    //     if (degree[i] > max_degree) {
    //         max_degree = degree[i];
    //         max_node = i;
    //     }
    // }
    // proib_node = max_node;
    // int guarda = max_degree;
    vii ve;

    for (int i = 1; i <=n; i++) {
        ve.eb(degree[i], i);
    }

    sort(all(ve));

    int resposta = 0;
    for (int i = 1; i<= n; i++){
        for (int j = 1; j<=n; j++) {
            if (i==j) continue;
            int cur = degree[i] + degree[j] - 1;
            if (adj[i].count(j) > 0) cur--;

            if (cur < resposta - 1) break;
            if (cur > resposta) resposta = cur;
        }
    }

    cout << resposta << endl;
    return;
    // NEW
    int resp =0;

    int max_degree = 0;
        // vi subst(n+1);
    // for (int i = 1; i <=n; i++) {
    //     // for (int j = 1; j<=n; j++)subst[j] = 0;
    //     // for (int v : adj[i]) subst[v] = 1;

    //     max_degree = 0;
    //     for (int j = 1; j <=n; j++) {
    //         int x = adj[i].c
    //         if (i != j and degree[j] - subst[j] > max_degree) {
    //             max_degree = degree[j] - subst[j];
    //         }
    //     }   

    //     resp = max(resp, max_degree + degree[i]);
    // }


    // cout << resp - 1 << endl;

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