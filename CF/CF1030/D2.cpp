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

int adj[1024][2];
int winner[1024][2];
int p[1024];
int d[1024];

int dfs(int i, int direction) {
    if (winner[i][direction] != -1) return winner[i][direction];

    if (adj[i][direction] == -1) return winner[i][direction] = 1;

    winner[i][direction] = 0;

    return winner[i][direction] = dfs(adj[i][direction], direction ^ 1);
}

int k;

int l(int a, int d) {
    return (k + a%k - d%k)%k;
}

int l(ii par) {
    return l(par.fs, par.sc);
}

void solve() {
    int n;
    cin >> n >> k;

    for (int i = 1; i <=n; i++) cin >> p[i];
    for (int i = 1; i<=n; i++) {
        int x;
        cin >> x;
        d[i] =x%k;
    }

    int q;
    cin >> q;

    vi starts;
    vii points;

    for (int i = 0; i < q; i++) {
        int start;
        cin >> start;
        starts.pb(start);
        // points.eb(start, 0);
    }

    for (int i = 1; i <=n; i++) {
        points.eb(p[i], d[i]);
    }

    map<int, int> last;
    for (int i = 0; i < k; i++) last[i] = -1;

    for (int i = 0; i < sz(points); i++) {
        adj[i][0] = -1;
        adj[i][1] = -1;

        int x = last[l(points[i])];
        cout << '&' << (points[i].fs + points[i].sc)%k << endl;
        cout << x << endl;
        if (x != -1) {

            adj[i][1] = x;
            adj[x][0] = i;

        }
        last[l(points[i])] = i;
        
        winner[i][0] = -1;
        winner[i][1] = -1;
    }

    for (int i = 0; i < sz(points); i++) {
        dfs(i, 0);
        dfs(i, 1);

        cout << '*' << winner[i][0] << ' ' << winner[i][1] << endl;
    }

    vii coords;

    for (int i = 0; i < sz(points); i++) {
        coords.eb(points[i].fs, i+1);
    }

    for (int i = 0; i < sz(starts); i++) {
        coords.eb(starts[i], 0);
    }

    sort(all(coords));

    map<int, stack<int>> f;

    map<int, int> id;

    for (int i = 0; i < sz(starts); i++) id[starts[i]] = i;

    vi resp(q);

    for (int i = 0; i < sz(coords); i++) {
        // int idx = points[i].fs;

        cout << coords[i].fs << ' ' << coords[i].sc << endl;
        
        if (coords[i].sc == 0) f[l(coords[i])].push(id[coords[i].fs]);
        else {
            int idx = coords[i].sc - 1;
            while(!f[l(points[idx])].empty()) {
                int top = f[l(points[idx])].top();
                f[l(points[idx])].pop();

                resp[top] = winner[idx][1];
            }
        }
    }

    for (int i = 0; i < k; i++) {
        while(!f[i].empty()) {
            int top = f[i].top();
            f[i].pop();

            resp[top] = 1;
        }
    }

    for (int r : resp) {
        if (r) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

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