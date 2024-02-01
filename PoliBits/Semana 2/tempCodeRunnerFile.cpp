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

vi adj[112345];
int memo[112345];
int memo2[112345];
int a[112345];
int vis[112345];
int xors = 1;

int dfs(int node) {
    memo[node] = a[node];
    memo2[node] = 0;
    vis[node] = 1;

    for (int p : adj[node]) {
        if (vis[p]) continue;
        memo[node] ^= dfs(p);
        memo2[node] += memo2[p];
    }

    if (memo2[node] == 0 and node!=1 and (memo[node] == xors)) memo2[node] = 1;
    if (memo2[node] > 0 and memo[node] == 0) memo2[1] = 2;

    return memo[node];
}

// int dfsResultado(int node, int resultado) {
//     if (!vis[node] or memo2[1] == 2) return 0;
//     vis[node] = 0;

//     memo2[node] = 0;
//     for (int p : adj[node]) {
//         memo2[node] += dfsResultado(p, resultado);
//     }

//     if (memo2[node] >= 2) {
//         memo2[1] = 2;
//     }

//     if (memo2[node] != 0) return memo2[node];
//     return (node!=1 and memo[node] == resultado);
// }

signed main(){_

    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        xors = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i+1];
            vis[i+1] = 0;
            xors ^= a[i+1];
        }


        for (int i = 0; i < n-1; i++) {
            int p, q;
            cin >> p >> q;
            adj[p].pb(q);
            adj[q].pb(p);
        }

        if(xors == 0) {
            cout << "YES" << endl;
            continue;
        }
        
        dfs(1);

        if (k==1){
            cout << "NO" << endl;

        } else {
            if (memo2[1] >= 2) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }

        }

        for(int i = 1; i<= n; i++) {
            adj[n].clear();
            memo2[i] = 0;
        }
    }

    return 0;
}
