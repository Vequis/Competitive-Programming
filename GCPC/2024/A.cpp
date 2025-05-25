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

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i<=m; i++) {
        int a,b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    int cor = 0;
    int resp = 0;

    for (int i = 1; i <=n; i++) {
        stack<int> pilha;

        if (!vis[i]) {


            pilha.push(i);

            vis[i] = ++cor;
            
            int count = 1;
            while(!pilha.empty()) {
                int topo = pilha.top(); pilha.pop();
                for (int v : adj[topo]) {
                    if (!vis[v]) {
                        vis[v] = cor;
                        pilha.push(v);
                        count++;
                    }
                }
            }

            resp = max(resp, count);
        }
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