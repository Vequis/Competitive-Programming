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

bool check(int x, int y, int n, int m) {
    return x > 0 and y > 0 and x <= m and y <= n;
}

int friends[3123][3123];
int vis[3123][3123];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

signed main(){_

    int t;
    cin >> t;

    int cont = 0;

    while(t--) {
        cont++;
        cout << "Case #" << cont << ':' << ' ';

        int n;
        cin >> n;
        int m;
        cin >> m;

        string s;
        int tr_count = 0;
        vii stones;
        vii trees;

        for(int i = 0; i < n; i++) {
            cin >> s;

            for(int j = 0; j < m; j++) if (s[j] == '^') trees.eb(i+1, j+1);
            for(int j = 0; j < m; j++) if (s[j] == '#') stones.eb(i+1, j+1);
        }

        queue<ii> fila;
        fila.push({1, 1});
        memset(vis, 0, sizeof(vis));
        memset(friends, 0, sizeof(friends));

        while(!fila.empty()) {
            ii coords = fila.front();
            fila.pop();

            if(vis[coords.fs][coords.sc] == 1) continue;
            vis[coords.fs][coords.sc] = 1;


            for (int i = 0; i < 4; i++) {
                int x = coords.fs + dx[i];
                int y = coords.sc + dy[i];

                if (check(x, y, n, m)) {
                    if (vis[x][y] == 0) {
                        friends[coords.fs][coords.sc]++;
                        friends[x][y]++;

                        fila.push({x, y});
                    }
                }
            }
        }

        for(ii stone : stones) {
            friends[stone.fs][stone.sc] = -1;
            fila.push({stone.fs, stone.sc});
        }
        memset(vis, 0, sizeof(vis));

        while(!fila.empty()) {
            ii coords = fila.front();
            fila.pop();

            if(vis[coords.fs][coords.sc] == 1) continue;
            vis[coords.fs][coords.sc] = 1;

            // cout << coords.fs << ' ' << coords.sc << endl;

            for (int i = 0; i < 4; i++) {
                int x = coords.fs + dx[i];
                int y = coords.sc + dy[i];

                if (check(x, y, n, m)) {
                    if (vis[x][y] == 0) {
                        // friends[coords.fs][coords.sc]++;
                        friends[x][y]--;

                        if(friends[x][y] < 2) fila.push({x, y});
                    }
                }
            }
        }

        bool deuruim = 0;
        for(ii tree : trees) {
            if (friends[tree.fs][tree.sc] < 2) deuruim = true;
        }

        if (sz(trees) == 0) {
            cout << "Possible" << endl;
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= m; j++) {
                    if (friends[i][j] == -1) cout << '#';
                    else if (friends[i][j] < 2) cout << '.';
                    else cout << '^';
                }
                cout << endl;
            }
        } else if (deuruim) {
            cout << "Impossible" << endl;
        } else {
            cout << "Possible" << endl;
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= m; j++) {
                    if (friends[i][j] == -1) cout << '#';
                    else if (friends[i][j] < 2) cout << '.';
                    else cout << '^';
                }
                cout << endl;
            }
        }



        // if ((n==1 or m==1) and tr_count > 0) {
        //     cout << "Impossible" << endl;
        //     continue;
        // } else if (tr_count == 0) {
        //     cout << "Possible" << endl;

        //     for(int i = 0; i < n; i++) {
        //         for(int j = 0; j < m; j++) {
        //             cout << '.';
        //         }
        //         cout << endl;
        //     }
        // } else {
        //     cout << "Possible" << endl;

        //     for(int i = 0; i < n; i++) {
        //         for(int j = 0; j < m; j++) {
        //             cout << '^';
        //         }
        //         cout << endl;
        //     }
        // }




    }

    return 0;
}
