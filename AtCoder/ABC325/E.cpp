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
#define maxn 1123

using namespace std;

int dist_trem[maxn][maxn];
int dist_carro[maxn][maxn];
int d[maxn][maxn];
int n;
int a, b, c;

void floyd_warshall(void){
    for(int k=1; k<=n; k++){ // vertice intermediário
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                dist_trem[i][j] = min(dist_trem[i][j], dist_trem[i][k] + dist_trem[k][j]);
                dist_carro[i][j] = min(dist_carro[i][j], dist_carro[i][k] + dist_carro[k][j]);
            }
        }
    }
}

signed main(){_

    memset(dist_trem, INF, sizeof(dist_trem));
    memset(dist_carro, INF, sizeof(dist_carro));
    cin >> n;

 
    cin >> a >> b >> c;

    // for(int i=0; i<m; i++){
    //     int a, b, peso;
    //     cin >> a >> b >> peso;

    //     dist[a][b] = peso;
    //     dist[b][a] = peso;
    // }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >>d[i][j];
            dist_carro[i][j] = a*d[i][j];
            dist_trem[i][j] = b*d[i][j] + c;
            if (i == j) dist_trem[i][j] = 0;
        }
    }

    floyd_warshall();
    // floyd_warshall();
    // floyd_warshall();
    // for(int i = 1; i <= n; i++) {
    //     for(int j = 1; j <= n; j++) {
    //         cout << dist_carro[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // for(int i = 1; i <= n; i++) {
    //     for(int j = 1; j <= n; j++) {
    //         cout << dist_trem[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    int resp = LLONG_MAX;
    for(int i = 1; i <=n; i++) {
        resp = min(resp, dist_carro[1][i] + dist_trem[i][n]);
    }

    cout << resp << endl;




    return 0;
}
