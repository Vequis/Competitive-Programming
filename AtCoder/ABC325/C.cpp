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

char grid[1111][1111];
int vis[1111][1111];
int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dy[] = {-1, -1, -1, 0, 1, 1, 1, 0};

signed main(){_

    int h, w;
    cin >> h >> w;

    queue<ii> fila;

    for(int i = 0; i<=h+1; i++) {
        grid[i][0] = '.';
        grid[i][w+1] = '.';
    }
    for(int i = 0; i<=w+1; i++) {
        grid[0][i] = '.';
        grid[h+1][i] = '.';
    }

    for(int i = 1; i <=h; i++) {
        for(int j = 1; j<= w; j++) {
            char c;
            cin >> c;
            grid[i][j] = c;
        }
    }

    int resp = 0;

    for(int i = 1; i <=h; i++) {
        for(int j = 1; j<= w; j++) {
            if (grid[i][j] == '#' and !vis[i][j]) {
                fila.push({i, j});
                resp++;

                vis[i][j] = 1;
                while(!fila.empty()) {
                    ii topo = fila.front();
                    fila.pop();
                    int ti, tj;
                    ti = topo.fs;
                    tj = topo.sc;
                    for(int k = 0; k < 8; k++) {
                        if (vis[ti+dx[k]][tj+dy[k]] == 0 and grid[ti+dx[k]][tj+dy[k]] == '#') {
                            fila.push({ti+dx[k],tj+dy[k]});
                            vis[ti+dx[k]][tj+dy[k]] = 1;
                        }
                    }

                    // cout << ti << ' ' <<tj << endl;
                }
                // cout << endl;
            }
        }
    }

    cout << resp << endl;

    return 0;
}
