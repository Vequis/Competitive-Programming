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

vector<vector<int>> flip(const vector<vector<int>>& grid) {
    int h = grid.size() - 1;
    int w = grid[1].size() - 1;

    vector<vi> new_grid(w + 1, vi(h + 1)); // Preenche com 0

    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            new_grid[j][i] = grid[i][j];
        }
    }

    return new_grid;
}

int f[612345];

int zerosums(vi v) {

    int resp = 0;
    int sum = 0;
    for (int i = 1; i < sz(v); i++) {
        sum += v[i];
        // cout << v[i] << ' ' << sum << ' ' << i << endl;
        resp += (sum == 0) + (f[sum + 300000]++);
    }

    sum = 0;
    for (int i = 1; i < sz(v); i++) {
        sum += v[i];
        f[sum+300000]--;
    }

    return resp;
}

void solve() {
    vector<vi> grid;

    int h, w;
    cin >> h >> w;

    grid.pb(vi(w+1));
    for (int i = 0; i < h; i++) {
        string s;
        cin >> s;

        vi row;
        row.pb(0);

        for (char c : s) {
            if (c == '.') {
                row.pb(1);
            } else {
                row.pb(-1);
            }
        }

        grid.pb(row);
    }

    if (h > w) {
        grid = flip(grid);
        swap(h, w);
    }

    // for (vi v : grid) {
    //     for (int x : v) cout << x;
    //     cout << endl;
    // }

    vector<vi> psa(h+1, vi(w+1)); // psa na coluna

    for (int j = 1; j <= w; j++) {
        for (int i = 1; i<= h; i++) psa[i][j] = psa[i-1][j] + grid[i][j];
    }


    int resp = 0;

    for (int i = 1; i <= h; i++) {
        for (int j = i; j<=h; j++) {

            vi v(w+1);

            for (int k=1; k<= w; k++) {
                v[k] = psa[j][k] - psa[i-1][k];
            }

            // cout << "vector: " << endl;
            // for (int x : v) cout << x << ' ';
            // cout << endl;
            resp += zerosums(v);

            // cout << i << ' ' << j << ' ' << zerosums(v) << endl;
        }
    }

    cout << resp << endl;
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