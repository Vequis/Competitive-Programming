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

char tabela[1111][1111];
int memo[1111][1111];

int h, w;

int dp(int x, int y){
    if(x<1 or y<1) return 0;
    if(memo[x][y] != -1) return memo[x][y];

    if(tabela[x][y] == '#') return memo[x][y] = 0;

    return memo[x][y] = (dp(x-1, y) + dp(x, y-1))%MODN;
}

int n, m;

signed main(){_

    cin >> n >> m;

    memset(memo, -1, sizeof(memo));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            char c;
            cin >> c;
            tabela[i][j] = c;
        }
    }

    memo[1][1] = 1;

    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=m; j++){
    //         cout << dp(i, j) << ' ';
    //     }
    //     cout << endl;
    // }

    cout << dp(n,m) << endl;

    return 0;
}
