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
int memo[1111][1111];
int h, w;


int dfs(int x, int y) {
    if(memo[x][y] != -1) return memo[x][y];

    int resp = 0;
    if (x+1 <= h and grid[x+1][y] == '.') resp += dfs(x+1, y);
    if (y+1 <= w and grid[x][y+1] == '.') resp = (resp+ dfs(x, y+1))%MODN;

    // cout << x << ' ' << y << ' ' << resp << endl;

    return memo[x][y] = resp;
}

signed main(){_

    cin >> h >> w;

    memset(memo, -1, sizeof(memo));

    for(int i = 1; i <=h; i++) {
        for(int j = 1; j<=w; j++) {
            cin >> grid[i][j];
        }
    }

    memo[h][w] = 1;

    cout << dfs(1, 1) << endl;


    return 0;
}
