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

vii adj[212345];
int mask;
int vis[212345];
int n;

bool dfs(int node) {
    vis[node] = mask;

    if (node == n) return true;

    for (ii p : adj[node]) {
        if (vis[p.fs] != mask and (p.sc | mask) == mask) {
            if (dfs(p.fs))return true;
        }
    }

    return false;
}   

void solve() {
    int m;
    cin >> n >> m;


    for (int i = 1; i <=m; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        adj[a].eb(b, w);
        adj[b].eb(a, w);
    }

    // analisar o i-th bit (menos valioso) 0-indexado -> num << i
    // num -> 1011 -> onde tem 1 significa que TEM QUE TER aquele numero ali
    // na dfs soh passar pelo vertice se(w[i] or & (1 << i) == 0
    // 
    // se bit da mask = 1, pode passar
    // se bit da mask = 0, n pode passar
    // se (w[i] or mask) != mask -> n pode passar 
    // se conseguir alcançar n, entao o bit i nao eh necessario 
    // a cada passo, relaxar o bit i

    int resp_mask = (1<<30) - 1;

    for (int bit_relaxado = 29; bit_relaxado>=0; bit_relaxado--) {
        // cout << bitset<32>(~(1<<bit_relaxado)) << endl;
        int prev_mask = resp_mask & (~(1<<bit_relaxado));
        // cout << bitset<32>(prev_mask) << endl;

        mask = prev_mask;
        if (dfs(1)) resp_mask = prev_mask;

        // if (dfs(1)) {
        //     cout << bit_relaxado << endl;
        // }
        // dfs-sucesso
    }

    cout << resp_mask << endl;

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