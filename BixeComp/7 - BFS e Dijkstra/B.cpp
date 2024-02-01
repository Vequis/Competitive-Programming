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

queue<ii> fila;
int t;
int grid[9][9];
int dist[9][9];
char c;

int a, b;
int at1, at2;
int dir1[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dir2[8] = {2, 1, -1, -2, -2, -1, 1, 2};

signed main(){_

    cin >> t;

    for (int i = 1; i<=t; i++) {
        cin >> c;
        a = (int)(c - 'a' + 1);
        cin >> c;
        b = (int)(c - '0');

        fila.push({a, b});

        cin >> c;
        a = (int)(c - 'a' + 1);
        cin >> c;
        b = (int)(c - '0');

        while(fila.empty() == false) {
            ii p = fila.front();
            fila.pop();

            if (p.fs == a && p.sc == b) {
                cout << dist[p.fs][p.sc] << endl;
                break;
            }
            for (int j=0; j<8; j++) {
            
                int at1 = p.fs + dir1[j];
                int at2 = p.sc + dir2[j];

                if (at1 <= 0 || at2 <= 0 || at1 > 8 || at2 > 8) continue;

                if (grid[at1][at2] == i) continue;
                grid[at1][at2] = i;

                dist[at1][at2] = dist[p.fs][p.sc] + 1;
                fila.push({at1, at2});
            
            }
        }

        while(!fila.empty()) {
            fila.pop();
        }

        for (int i = 1; i<=8; i++) {
            for (int j = 1; j<=8; j++) {
                dist[i][j] = 0;
            }
        }

    }

    return 0;
}
