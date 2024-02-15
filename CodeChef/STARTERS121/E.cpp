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

set<ii> obst;
queue<ii> fila;

bool encontra(int x, int y) {
    return obst.find({x, y}) != obst.end();
}

int dx[] = {1, 1, 1, 0, -1, -1, -1, 0};
int dy[] = {1, 0, -1, -1, -1, 0, 1, 1};

void solve() {

    // tem que ver se saindo da parede de cima da pra chegar na esquerda ou embaixo
    // saindo da parede da direita da pra chegar embaixo ou na esquerda

    int n, m;
    cin >> n >> m;
    obst.clear();
    while(!fila.empty()) fila.pop();

    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        obst.insert({x, y});

        if (x == n or y == 1) fila.push({x, y});
    }

    while(!fila.empty()) {
        ii topo = fila.front();
        fila.pop();

        if (topo.fs == 1 or topo.sc == n) {
            cout << "NO" << endl;
            return;
        }

        auto [x, y] = topo;

        for(int i = 0; i < 8; i++) {
            if (x + dx[i] < 0 or x + dx[i] > n) continue;
            if (y + dy[i] < 0 or y + dy[i] > n) continue;

            if (encontra(x + dx[i], y + dy[i])) {
                fila.push({x + dx[i], y + dy[i]});
                obst.erase(obst.find({x + dx[i], y + dy[i]}));
            }
        }
    }

    cout << "YES" << endl;
}

signed main(){_
    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
