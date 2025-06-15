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
int prox[212345]; // -1 não entrei -2: sendo processado

void dfs(int node) {
    prox[node] = 0;

    for (int v : adj[node]) {
        if (prox[v] == -1) {
            dfs(v);
            int x = prox[v] + 1;

            if (x % 2) {
                prox[node] = x;
                return;
            } else if (prox[node] == 0) {
                prox[node] = x;
            }
        }
    }

    prox[node] = 0;
}

void solve() {
    int n, t;
    cin >> n >> t;
    
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    for (int i = 1; i <=n; i++) prox[i] = -1;

    int init;
    cin >> init;

    dfs(init);

    if (prox[init] % 2) {
        cout << "Ron" << endl;
    } else {
        cout << "Hermione" << endl;
    }
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