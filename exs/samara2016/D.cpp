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

int n, m, r, c;
char grid[100][100];
int custo[100][100];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
vii limites;
int vis[100][100];
int memo[100][100];

int dfs(int x, int y){

    int resp = 0;
    grid[x][y] = 'o';


    if(memo[x][y]!=-1) return memo[x][y];

    for(int i=0; i<4; i++){
        char c = grid[x+dx[i]][y+dy[i]];

        if(x+dx[i] < 1 or x+dx[i]>n or y+dy[i] < 1 or y+dy[i]>m ) continue;

        if(c=='o') {
            resp+=0;
        } else if(c=='X') {
            resp+=0;
        } else {
            resp+=dfs(x+dx[i], y+dy[i]);
        }
    }

    if(x == r && y == c) return resp;

    cout << x << ' ' << y << ' ';
    if(custo[x][y] < resp){
        grid[x][y] = 'X';
        cout << custo[x][y] << endl;
        return memo[x][y] = custo[x][y];
    } else {
        grid[x][y] = '.';
        cout << resp << endl;
        return memo[x][y] = resp;
    }
}

signed main(){_

    cin >> n >> m >> r >> c;

    memset(memo, -1, sizeof(memo));

    for(int i=0; i<=55; i++){
        custo[0][i] = 1000;
        custo[n+1][i] = 1000;
        custo[i][0] = 1000;
        custo[i][m+1] = 1000;
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            grid[i][j] = '.';
            cin >> custo[i][j];
        }
    }

    grid[r][c] = 'o';
    cout << dfs(r, c) << endl;

    return 0;
}
