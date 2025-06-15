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

int k, n, m;

int psa[512][512]; // psa[i][j] = all between 0,0 and i, j

int s(int x, int y) {
    x = max(0LL, x);
    x = min(n, x);

    y = max(0LL, y);
    y = min(m, y);

    return psa[x][y];
}

int sum(int x1, int y1, int x2, int y2) {
    // always x1 <= x2 and y1<=y2

    if (x1 > n or y1 > m) return 0;

    return s(x2, y2) - s(x2, y1-1) - s(x1-1, y2) + s(x1-1, y1-1);
}

// what if a+ k > n

int gained_gold(int a, int b) {
    return sum(a-k, b-k, a+k, b-k) + sum(a-k, b+k, a+k, b+k) + sum(a-k, b-k+1,a-k, b+k-1) + sum(a+k, b-k+1, a-k, b+k-1);
}

int lost_gold(int a, int b) {
    return sum(a-k+1, b-k+1, a+k-1, b+k-1);
}

string grid[512];

void solve() {
    cin >> n >> m >> k;

    for (int i = 0; i<=n; i++){
        for (int j = 0; j<=m; j++) psa[i][j]=0;
    }

    for (int i = 1; i <= n; i++) {
        cin >> grid[i];

        for (int j=1; j<=m; j++) {
            psa[i][j] = psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1] + (grid[i][j-1] == 'g'); 
            // cout << i << ' ' << j-1 << grid[i][j-1] << endl;
        }
    }

    int resp = INF;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j<=m; j++) {
            if (grid[i][j-1] == '.') {
                // cout << i << ' ' << j << lost_gold(i, j) << endl;
                resp = min(resp, lost_gold(i, j));
            }
        }
    }

    cout << psa[n][m] - resp << endl;

    // all before was useless.......

    // for (int i = 0; i<=n; i++){
    //     for (int j = 0; j<=m; j++) {
    //         cout << psa[i][j] << ' ';
    //     }
    //     cout << endl;
    // }


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