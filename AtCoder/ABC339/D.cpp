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

int dist[63][63];
ii oth[63][63];
ii dir[] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int vis[63][63];

struct node {
    int x1, y1;
    int x2, y2;
    int dist;
};

signed main(){_

    int n;
    cin >> n;

    memset(dist, -1, sizeof(dist));

    queue<node> fila;
    // oth[ini1.fs]

    for(int i = 0; i <= n+1; i++) {
        dist[0][i] = INF;
        dist[n+1][i] = INF;
        dist[i][0] = INF;
        dist[i][n+1] = INF;
    }

    int first = 1;
    ii posf, poss; //first and second
    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;

        for(int j = 0; j < n; j++) {
            if (s[j] == '#') dist[i][j+1] = INF;
            else if (s[j] == 'P') {
                if (first) {
                    first = 0;
                    posf = make_pair(i, j+1);
                }
                else {
                    // dist[i][j+1] = 0;
                    // oth[i][j+1] = posf;
                    poss = make_pair(i, j+1);
                    fila.push({posf.fs, posf.sc, i, j+1, 0});
                }
            }
        }
    }

    queue<ii> fila_pos;
    fila_pos.push(posf);
    int possivel = 0;

    while(!fila_pos.empty()) {
        ii topo = fila_pos.front();
        fila_pos.pop();

        if (topo == poss) {
            possivel = 1;   
            break;
        }

        for(ii d : dir) {
            if (dist[topo.fs + d.fs][topo.sc + d.sc] != INF and !vis[topo.fs + d.fs][topo.sc + d.sc]) {
                fila_pos.push({topo.fs + d.fs, topo.sc + d.sc});
            }
        }
    }

    if(!possivel) {
        cout << -1 << endl;
        return 0;
    }

    // cout << posf.fs << ' ' << posf.sc << endl;
    // cout << poss.fs << ' ' << poss.sc << endl;

    // fila.push(poss);

    while(!fila.empty()) {
        node topo = fila.front();
        fila.pop();

        // cout << topo.fs << ' ' <<topo.sc << endl;
        // cout << oth[topo.fs][topo.sc].fs << ' ' << oth[topo.fs][topo.sc].sc << endl;
        // cout << dist[topo.fs][topo.sc] << endl;
        // cout << endl;

        // cout << topo.x1 << ' ' << topo.y1 << ' ' << topo.x2 << ' ' << topo.y2 << ' ' <<topo.dist << endl;

        if (topo.x1 == topo.x2 and topo.y1 == topo.y2) {
            cout << topo.dist << endl;
            return 0;
        }

        for(ii d : dir) {
            node x = topo;
            x.dist = topo.dist+1;

            if (dist[x.x1 + d.fs][x.y1 + d.sc] != INF) {
                x.x1 += d.fs;
                x.y1 += d.sc;
            }
            if (dist[x.x2 + d.fs][x.y2 + d.sc] != INF) {
                x.x2 += d.fs;
                x.y2 += d.sc;
            }

            fila.push(x);
        }
    }

    return 0;
}
