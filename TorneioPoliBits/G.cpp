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

int pesoa[11234];
int pesob[11234];
vi adja[11234];
vi adjb[11234];
vii auxa[11234];
vii auxb[11234];
int vis[11234];
int n;

void limpavis() {
    for (int i = 1; i <=n; i++) vis[i] = 0;
}

int dfs1(int node) {
    vis[node] = 1;
    for (int v : adja[node]) {
        if (!vis[v]) {
            pesoa[node]++;
            dfs1(v);
            auxa[node].eb(pesoa[v], v);
        }
    }

    sort(all(auxa[node]));
}

int dfs2(int node) {
    vis[node] = 1;
    for (int v : adjb[node]) {
        if (!vis[v]) {
            pesob[node]++;
            dfs2(v);
            auxb[node].eb(pesob[v], v);
        }
    }

    sort(all(auxb[node]));
}

void solve() {
    for (int i = 1; i<=n; i++) {
        pesoa[i] = 1;
        pesob[i] = 1;
        adja[i].clear();
        adjb[i].clear();
        auxa[i].clear();
        auxb[i].clear();

    }

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adja[a].pb(b);
        adja[b].pb(a);
    }
    limpavis();
    dfs1(1);

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adjb[a].pb(b);
        adjb[b].pb(a);
    }



}

signed main(){_
    int t;
    cin >> t;
    // t=1;

    while(cin >> n) {
        solve();
    }

    return 0;
}