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

int grid[1123][1123];
int dist[1123][1123];

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i <=m+1; i++){
        grid[0][i] = 1;
        grid[n+1][i] = 1;
    }
    for (int i = 0; i <=n+1; i++){
        grid[i][0] = 1;
        grid[i][m+1] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j< m; j++) {
            cin >> grid[i][j];
            dist[i][j] = INF;
        }
    }

    queue<ii> fila;
    fila.push({0,0});
    dist[0][0] = 0;

    int resp = -1;
    while(!fila.empty()) {
        ii t = fila.front();
        fila.pop();

        // cout << t.fs << ' ' << t.sc << endl;

        if (t.sc == m-1) {
            int end = (n-1 + dist[t.fs][t.sc])%n;
            // cout << end << ' ' << t.fs << endl;

            if (resp != -1) {
                resp = min(resp, dist[t.fs][t.sc] + abs(end - t.fs));
            } else {
                resp = dist[t.fs][t.sc] + abs(end - t.fs);
            }
            resp = min(resp, dist[t.fs][t.sc] + n - abs(end - t.fs));

            continue;
        }


        if (grid[(t.fs+1)%n][t.sc+1] == 0 and dist[(t.fs+1)%n][t.sc+1] > dist[t.fs][t.sc] + 1) {
            dist[(t.fs+1)%n][t.sc+1] = dist[t.fs][t.sc] + 1;
            fila.push({(t.fs + 1)%n, t.sc + 1});
        }

        if (grid[(t.fs+1)%n][t.sc] == 0 and grid[(t.fs+2)%n][t.sc] == 0 and dist[(t.fs+2)%n][t.sc] > dist[t.fs][t.sc] + 1) {
            dist[(t.fs+2)%n][t.sc] = dist[t.fs][t.sc] + 1;
            fila.push({(t.fs + 2)%n, t.sc});
        }
    }

    cout << resp << endl;
}

signed main(){_
    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
