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

vector<pair<int, ii>> adj[212345];

ii coords[212345];
int vis[212345];

signed main(){_

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int a, b, x, y;
        cin >> a >> b;
        cin >> x >> y;

        adj[a].eb(b, make_pair(x, y));
        adj[b].eb(a, make_pair(-x, -y));
    }

    queue<int> fila;
    fila.push(1);
    vis[1] = 1;

    memset(coords, INF, sizeof(coords));
    coords[1] = {0, 0};

    while(!fila.empty()) {

        int u = fila.front();
        vis[u] = 1;
        fila.pop();
        for (pair<int, ii> q : adj[u]) {
            int v = q.fs;

            if (!vis[v]) {
                fila.push(v);

                coords[v] = {coords[u].fs + q.sc.fs, coords[u].sc + q.sc.sc};
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cout << "undecidable" << endl;
        } else {
            cout << coords[i].fs << ' ' << coords[i].sc << endl;
        }
    }

    return 0;
}
