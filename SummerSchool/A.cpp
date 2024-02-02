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
#define int long long //-> solução divina?

#define maxn 112345
#define maxm 212345


using namespace std;

vi adj[maxn];
int nivel[maxn];
vi resp;
vi temp;
int pai[maxn];
int vis[maxn];

int c, d;

void dfs(int node) {
    if (c!=-1) return;
    vis[node] = 1;
    for (int x : adj[node]) {
        if (vis[x] and pai[node] != x) {
            c = node;
            d = x;
            return;
        }
        if (!vis[x]) {
            pai[x] = node;
            dfs(x);
        }
    }
}

void dfs2(int node) {
    if (sz(resp) > 0) return;
    vis[node] = 1;

    for(int x : adj[node]) {
        if (x == c and pai[node] != x and sz(resp) == 0) {
            resp.pb(x);
            int it = node;
            while(it != c) {
                resp.pb(it);
                it = pai[it];
            }
            resp.pb(c);

            return;
        }
        
        if (!vis[x]) {
            pai[x] = node;
            dfs2(x);
        };


    }
}

signed main(){_

    int n, m;
    cin >> n >> m;

    c = d = -1;
    c = -1;

    for(int i = 1; i <= n; i++) pai[i] = -1;

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    for(int i = 1; i<=n; i++) {
        if (!vis[i]) dfs(i);
    }
    //c = 1;

    //cout << c << ' ' << d << endl;

    if (c==-1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }


    for(int i = 1; i <=n; i++) pai[i] = -1;
    for(int i = 1; i <=n; i++) vis[i] = 0;
    dfs2(c);

    if(sz(resp) <= 2) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    cout << sz(resp) << endl;
    for(int x : resp) cout << x << ' ';
    cout << endl;

    return 0;
}
