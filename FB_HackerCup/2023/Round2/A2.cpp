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

void tt(int tes) {
    cout<<"Case #"<<tes<<": ";
}

int h, w;
char grid[3123][3123];
int vis[3123][3123];
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};


void solve() {
    cin >> h >> w;

    for(int i = 0; i<=h+1; i++) {
        grid[i][0] = 'B';
        grid[i][w+1] = 'B';
    }
    for(int i = 0; i<=w+1; i++) {
        grid[0][i] = 'B';
        grid[h+1][i] = 'B';
    }

    for(int i = 1; i <=h; i++) {
        for(int j = 1; j<= w; j++) {
            char c;
            cin >> c;
            grid[i][j] = c;

            vis[i][j] = 0;
        }
    }

    queue<ii> fila;

    int comp = 0;
    int resp = 0;
    map<ii, int> f;

    int resposta = 0;

    for(int i = 1; i <=h; i++) {
        for(int j = 1; j<= w; j++) {
            ii livre;

            if (grid[i][j] == 'W' and !vis[i][j]) {
                int cont = 0;
                fila.push({i, j});
                comp++;
                int livres = 0;

                vis[i][j] = 1;
                while(!fila.empty()) {
                    cont++;
                    ii topo = fila.front();
                    fila.pop();
                    int ti, tj;
                    ti = topo.fs;
                    tj = topo.sc;
                    for(int k = 0; k < 4; k++) {
                        if (vis[ti+dx[k]][tj+dy[k]] == 0 and grid[ti+dx[k]][tj+dy[k]] == 'W') {
                            fila.push({ti+dx[k],tj+dy[k]});
                            vis[ti+dx[k]][tj+dy[k]] = 1;
                        } else if (grid[ti+dx[k]][tj+dy[k]] == '.'){
                            
                            if(vis[ti+dx[k]][tj+dy[k]] != comp) {
                                livres++;
                                livre = {ti + dx[k], tj + dy[k]};
                            }
                            vis[ti+dx[k]][tj+dy[k]] = comp;
                        }
                    }

                    // cout << ti << ' ' <<tj << endl;
                }

                if (livres == 1) {
                    resp = 1;
                    // cout << livre.fs << ' ' << livre.sc << ':' << cont << endl;
                    f[livre]+=cont;
                    resposta = max(resposta, f[livre]);
                }
                // cout << livres << endl;
            }
        }
    }


    

    cout << resposta << endl;


}

signed main(){_

    // freopen("ready_go_part_2_input.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        tt(i);
        solve();
    }

    return 0;
}
