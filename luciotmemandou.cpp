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
#define INFLL 0x3f3f3f3f3f3f3f3
#define MODN 1000000007
#define int long long // -> solução divina

using namespace std;

// Am I the real champion?
// There is a champion with less strength than me?

// Edges to the strength in the other map
// And for the adversary that is a bit more stronger
// Then, you just has to run down the graph and see which nodes can achieve the real champions.

// Nodes on map 1: (0:N-1)
// Nodes on map 2: (N: 2N-1)

ii strengths[112345];

vi adj[212345];

int vis[212345];

bool winner[212345];
bool winner_ids[212345];

void dfs(int node) {
    if (vis[node]) return;
    winner[node] = 1;
    vis[node] = 1;

    for (int v : adj[node]) {
        dfs(v);
    }
}

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < 2*n; i++) {
        adj[i].clear();
        vis[i] = 0;
        winner[i] = 0;
        winner_ids[i] = 0;
    }

    for (int i = 1; i <=n; i++) cin >> strengths[i].fs;
    for (int i = 1; i <=n; i++) cin >> strengths[i].sc;

    vii map1, map2;

    for (int i = 1; i <=n; i++) {
        map1.eb(strengths[i].fs, i);
        map2.eb(strengths[i].sc, i);
    }

    sort(all(map1), greater<ii>());
    sort(all(map2), greater<ii>());

    for (int i = 0; i < n; i++) {
        strengths[map1[i].sc].fs = i;
        strengths[map2[i].sc].sc = i+n;
    
        if (i!=0) {
            adj[i].pb(i-1);
            adj[i+n].pb(i+n-1);
        }
    }

    for (int i = 1; i<=n; i++) {
        adj[strengths[i].fs].pb(strengths[i].sc);
        adj[strengths[i].sc].pb(strengths[i].fs);
    }

    dfs(0);
    dfs(n);

    for (int i = 0; i < n; i++) {
        if (winner[i]) {
            winner_ids[map1[i].sc] = 1;
        }

        if (winner[i+n]) {
            winner_ids[map2[i].sc] = 1;
        }
    }

    for (int i = 1; i <=n; i++) {
        if (winner_ids[i]) cout << 1;
        else cout << 0;
    }
    cout << endl;
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