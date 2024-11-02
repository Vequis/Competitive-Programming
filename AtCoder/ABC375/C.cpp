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

char grid[3123][3123];
char newgrid[3123][3123];

int n;
ii calc(ii p) {
    return {p.sc, n + 1 - p.fs};
}

ii calc(ii p, int x) {
    int y = (4 - x%4)%4;
    ii resp = p;
    for (int i = 0; i < y%4; i++) resp = calc(resp);
    return resp;
}

void solve() {
    cin >> n;

    for (int i = 1; i <=n; i++) {
        for (int j = 1; j<=n; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 1; i <=n; i++) {
        for (int j = 1; j<=n; j++) {
            int dist = min(i, j);
            dist = min(dist, n+1-i);
            dist = min(dist, n+1-j);


            ii p = calc({i, j}, dist);

            // cout << i << ' ' << j << ' ' << dist << ' ';
            // cout << endl;
            // cout << p.fs << ' ' << p.sc << ' ' << grid[p.fs][p.sc] << endl;
            newgrid[i][j] = grid[p.fs][p.sc];
        }
    }

    for (int i = 1; i <=n; i++) {
        for (int j = 1; j<=n; j++) {
            cout << newgrid[i][j];
        }
        cout << endl;
    }
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