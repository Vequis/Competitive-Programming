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

vii adj[1024][2];
int winner[1024][2];
int p[1024];
int d[1024];

int dfs(int i, int direction) {
    if (winner[i][direction] != -1) return winner[i][direction];

    if (sz(adj[i][direction]) == 0) return winner[i][direction] = 1;

    winner[i][direction] = 0;

    if (direction == 1) {
        return winner[i][direction] = dfs(adj[i][direction][(sz(adj[i][direction]) - 1)].fs, direction ^ 1);
    } else {
        return winner[i][direction] = dfs(adj[i][direction][0].fs, direction ^ 1);
    }
}

void solve() {
    int n, k;
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

    for (int i = 0; i < sz(points); i++) {
        adj[i][0].clear();
        adj[i][1].clear();
        for (int j = 0; j< sz(points); j++) {
            if (points[i].fs > points[j].fs and abs(points[i].fs - points[j].fs) % k == (-points[i].sc + points[j].sc + k) % k) {
                adj[i][1].pb({j, 0});
            } else if (points[i].fs < points[j].fs and abs(points[i].fs - points[j].fs) % k == (-points[i].sc + points[j].sc + k) % k) {
                adj[i][0].pb({j, 1});
            }
        }
        
        winner[i][0] = -1;
        winner[i][1] = -1;
    }

    for (int i = 0; i < sz(points); i++) {
        dfs(i, 0);
        dfs(i, 1);

        // cout << winner[i][0] << ' ' << winner[i][1] << endl;
    }

    for (int i = 0; i < sz(starts); i++) {
        // int idx = points[i].fs;

        for (int j = 0; j < sz(points); j++) {
            // analisar melhor
            if (starts[i] <= points[j].fs and abs(starts[i] - points[j].fs) % k == ( points[j].sc + k) % k) {
                if (winner[j][1] == 1) {

                    cout << "YES" << endl;
                } else {
                    cout << "NO" << endl;
                }

                break;
            }

            if (j==sz(points)-1) {
                // cout << "*YES" << endl;
                cout << "YES" << endl;
            }
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